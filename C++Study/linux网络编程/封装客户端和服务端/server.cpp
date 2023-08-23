#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

class Server {
  private:
    int m_listenfd;
    int m_clientfd;
    string m_clientip;
    unsigned short m_port;

  public:
    Server() : m_listenfd(-1), m_clientfd(-1){};

    bool initserver(const unsigned short port) {
        if ((m_listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
            return false;

        m_port = port;

        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

        if (bind(m_listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) ==
            -1) {
            close(m_listenfd);
            m_listenfd = -1;
            return false;
        }

        if (listen(m_listenfd, 5) == -1) {
            close(m_listenfd);
            m_listenfd = -1;
            return false;
        }

        return true;
    }

    bool accept() {
        struct sockaddr_in caddr;
        socklen_t addrlen = sizeof(caddr);
        if ((m_clientfd = ::accept(m_listenfd, (struct sockaddr *)&caddr,
                                   &addrlen)) == -1)
            return false;

        m_clientip = inet_ntoa(caddr.sin_addr);
        return true;
    }

    const string &cilentip() const { return m_clientip; }

    bool send(const string &buffer) {
        if (m_clientfd == -1)
            return false;

        if ((::send(m_clientfd, buffer.data(), buffer.size(), 0)) <= 0)
            return false;

        return true;
    }

    bool recv(string &buffer, const size_t maxlen) {
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

    bool closeliten() {
        if (m_listenfd == -1)
            return false;

        ::close(m_listenfd);
        m_listenfd = -1;
        return true;
    }

    bool closeclient() {
        if (m_clientfd == -1)
            return false;

        ::close(m_clientfd);
        m_clientfd = -1;
        return true;
    }

    ~Server() {
        closeliten();
        closeclient();
    }
};

int main(int argc, char **argv) {
    if (argc != 2) {
        cout
            << "Using:./demo8 通讯端口\nExample:./demo8 5005\n\n"; // 端口大于1024，不与其它的重复。
        cout << "注意：运行服务端程序的Linux系统的防火墙必须要开通5005端口。\n";
        cout << "      如果是云服务器，还要开通云平台的访问策略。\n\n";
        return -1;
    }

    Server server;
    if (server.initserver(atoi(argv[1])) == false) {
        perror("initserver");
        return -1;
    }

    if (server.accept() == false) {
        perror("accept");
        return -1;
    }

    cout << "客户端已连接" << endl;

    string buffer;
    while (true) {
        if (server.recv(buffer, 1024) == false) {
            perror("recv()");
            break;
        }

        cout << "接收：" << buffer << endl;

        buffer = "ok";
        if (server.send(buffer) == false) {
            perror("send");
            break;
        }
        cout << "发送" << buffer << endl;
    }

    return 0;
}
