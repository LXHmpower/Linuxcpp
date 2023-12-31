#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
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

    ~Client() { close(); };
};

int main(int argc, char **argv) {
    if (argc != 3) {

        perror("usage ...");
        return -1;
    }

    Client client;
    if (client.connet(argv[1], atoi(argv[2])) == false) {
        perror("connect()");
    }

    string buffer;
    for (int i = 0; i < 10; i++) {
        buffer = "这是第" + to_string(i + 1) + "个超级女生，编号" +
                 to_string(i + 1) + "。";

        if (client.send(buffer) == false) {
            perror("send()");
        }
        cout << "发送：" << buffer << endl;

        if (client.recv(buffer, 1024) == false) {
            perror("recv()");
            break;
        }
        cout << "接收：" << buffer << endl;
        sleep(1);
    }

    return 0;
}
