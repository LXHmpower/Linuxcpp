#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/_types/_size_t.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Client {
  private:
    int m_clientfd;
    string m_ip;
    unsigned short m_port;

  public:
    Client() : m_clientfd(-1){};

    bool connet(const string &ip, unsigned short port) {
        if (m_clientfd != -1)
            return false;
        m_ip = ip;
        m_port = port;

        if ((m_clientfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
            return false;

        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(m_port);

        struct hostent *h;
        if ((h = gethostbyname(m_ip.c_str())) == nullptr) {
            ::close(m_clientfd);
            m_clientfd = -1;
            return false;
        }
        memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);

        if (::connect(m_clientfd, (struct sockaddr *)&servaddr,
                      sizeof(servaddr)) == -1) {
            ::close(m_clientfd);
            m_clientfd = -1;
            return false;
        }

        return true;
    }

    bool send(const string &buffer) {
        if (m_clientfd == -1)
            return false;
        if (::send(m_clientfd, buffer.data(), buffer.size(), 0) <= 0)
            return false;
        return true;
    }

    bool send(void *buffer, const size_t size) {
        if (m_clientfd == -1)
            return false;

        if ((::send(m_clientfd, buffer, size, 0)) <= 0)
            return false;

        return true;
    }

    bool recv(string &buffer, int maxlen) {
        buffer.clear();
        buffer.resize(maxlen);

        int readn = ::recv(m_clientfd, &buffer[0], buffer.size(), 0);
        if (readn <= 0) {
            buffer.clear();
            return false;
        }
        buffer.resize(readn);
        return true;
    }

    bool close() {
        if (m_clientfd == -1)
            return false;
        ::close(m_clientfd);
        m_clientfd = -1;
        return true;
    }

    bool sendfile(const string &filename, const size_t filesize) {
        ifstream fin(filename, ios::binary);
        if (fin.is_open() == false) {
            cout << "open:" << filename << "failed" << endl;
            return false;
        }

        int onread = 0;
        int totalbytes = 0;
        char buffer[4096];

        while (true) {
            memset(buffer, 0, sizeof(buffer));

            if (filesize - totalbytes > 4096)
                onread = 4096;
            else
                onread = filesize - totalbytes;

            fin.read(buffer, onread);

            if (send(buffer, onread) == false)
                return false;

            totalbytes = totalbytes + onread;

            if (totalbytes == filesize)
                break;
        }

        return true;
    }

    ~Client() { close(); };
};

int main(int argc, char **argv) {
    if (argc != 5) {

        perror("usage ...");
        return -1;
    }

    Client client;
    if (client.connet(argv[1], atoi(argv[2])) == false) {
        perror("connect()");
    }

    struct st_fileinfo {
        char filename[256];
        int filesize;
    } fileinfo;

    memset(&fileinfo, 0, sizeof(fileinfo));
    strcpy(fileinfo.filename, argv[3]);
    fileinfo.filesize = atoi(argv[4]);

    if (client.send(&fileinfo, sizeof(fileinfo)) == false) {
        perror("send");
    }
    cout << "发送文件信息：" << fileinfo.filename << "(" << fileinfo.filesize
         << ")" << endl;

    string buffer;
    if (client.recv(buffer, 2) == false) {
        perror("recv()");
        return -1;
    }
    if (buffer != "ok") {
        cout << "服务端没有回复ok。\n";
        return -1;
    }

    if (client.sendfile(fileinfo.filename, fileinfo.filesize) == false) {
        perror("sendfile()");
        return -1;
    }

    if (client.recv(buffer, 2) == false) {
        perror("recv()");
        return -1;
    }
    if (buffer != "ok") {
        cout << "发送文件内容失败。\n";
        return -1;
    }

    cout << "发送文件内容成功。\n";

    return 0;
}
