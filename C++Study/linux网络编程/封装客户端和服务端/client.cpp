#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

class Client
{
private:
    int m_clientfd;
    string m_ip;
    unsigned short m_port;
public:
    Client():m_clientfd(-1){};

    bool connect( string ip, unsigned port)
    {
        if(m_clientfd != -1) return false;
        m_ip = ip; m_port = port;
        if((m_clientfd = socket(AF_INET,SOCK_STREAM,0)) == -1) return false;

    }
    
    
    ~Client(){};
};


int main(int argc, char *argv[])
{
    return 0;
}