/*
 * 程序名：rinetdin.cpp，网络代理服务程序-内网端。
 * 作者：吴从周
*/
#include "_public.h"
using namespace idc;

int  cmdconnsock;  // 内网程序与外网程序的命令通道的socket。

int epollfd=0;     // epoll的句柄。
int tfd=0;            // 定时器的句柄。

#define MAXSOCK  1024
int clientsocks[MAXSOCK];       // 存放每个socket连接对端的socket的值。
int clientatime[MAXSOCK];       // 存放每个socket连接最后一次收发报文的时间。

// 向目标ip和端口发起socket连接，bio取值：false-非阻塞io，true-阻塞io。
int conntodst(const char *ip,const int port,bool bio=false);

void EXIT(int sig);   // 进程退出函数。

clogfile logfile;

// cpactive pactive;     // 进程心跳。

int main(int argc,char *argv[])
{
    if (argc != 4)
    {
        printf("\n");
        printf("Using :./rinetdin logfile ip port\n\n");
        printf("Sample:./rinetdin /tmp/rinetdin.log 192.168.174.132 4000\n\n");
        printf("        /project/tools1/bin/procctl 5 /project/tools1/bin/rinetdin /tmp/rinetdin.log 192.168.174.132 4000\n\n");
        printf("logfile 本程序运行的日志文件名。\n");
        printf("ip      外网代理服务端的地址。\n");
        printf("port    外网代理服务端的端口。\n\n\n");
        return -1;
    }

    // 关闭全部的信号和输入输出。
    // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程。
    // 但请不要用 "kill -9 +进程号" 强行终止。
    closeioandsignal(); signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

    // 打开日志文件。
    if (logfile.open(argv[1])==false)
    {
        printf("打开日志文件失败（%s）。\n",argv[1]); return -1;
    }

    // pactive.addpInfo(30,"inetd");       // 设置进程的心跳超时间为30秒。

    // 建立内网与外网的命令通道。
    if ((cmdconnsock=conntodst(argv[2],atoi(argv[3]),true))<0)
    {
        logfile.write("tcpclient.connect(%s,%s) 失败。\n",argv[2],argv[3]); return -1;
    }

    logfile.write("与外部的命令通道已建立(cmdconnsock=%d)。\n",cmdconnsock);

    // 命令通道建立之后，再设置为非阻塞的。
    fcntl(cmdconnsock,F_SETFL,fcntl(cmdconnsock,F_GETFD,0)|O_NONBLOCK);

    // 创建epoll句柄。
    epollfd=epoll_create(1);

    struct epoll_event ev;  // 声明事件的数据结构。

    // 为命令通道的socket准备可读事件。
    ev.events=EPOLLIN;
    ev.data.fd=cmdconnsock;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,cmdconnsock,&ev);

    // 创建定时器。
    tfd=timerfd_create(CLOCK_MONOTONIC,TFD_NONBLOCK|TFD_CLOEXEC);  // 创建timerfd。

    struct itimerspec timeout;
    memset(&timeout,0,sizeof(struct itimerspec));
    timeout.it_value.tv_sec = 20;           // 超时时间为20秒。
    timeout.it_value.tv_nsec = 0;
    timerfd_settime(tfd,0,&timeout,0);  // 设置定时器。
  
    // 为定时器准备事件。
    ev.events=EPOLLIN;               
    ev.data.fd=tfd;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,tfd,&ev);       // 把定时器的读事件加入epollfd中。

    // pactive.addpinfo(30,"rinetdin");   // 设置进程的心跳超时间为30秒。

    struct epoll_event evs[10];      // 存放epoll返回的事件。

    while (true)
    {
        // 等待监视的socket有事件发生。
        int infds=epoll_wait(epollfd,evs,10,-1);

        // 返回失败。
        if (infds < 0) { logfile.write("epoll() failed。\n"); EXIT(-1); }

        // 遍历epoll返回的已发生事件的数组evs。
        for (int ii=0;ii<infds;ii++)
        {
            logfile.write("已发生事件的socket=%d\n",evs[ii].data.fd);

            ////////////////////////////////////////////////////////
            // 如果定时器的时间已到，有两件事要做：1）设置进程的心跳；2）清理空闲的客户端socket。
            if (evs[ii].data.fd==tfd)
            {
                timerfd_settime(tfd,0,&timeout,NULL);  // 重新设置定时器。

                // pactive.uptatime();        // 1）更新进程心跳。

                // 2）清理空闲的客户端socket。
                for (int jj=0;jj<MAXSOCK;jj++)
                {
                    // 如果客户端socket空闲的时间超过80秒就关掉它。
                    if ( (clientsocks[jj]>0) && ((time(0)-clientatime[jj])>80) )
                    {
                        logfile.write("client(%d,%d) timeout。\n",clientsocks[jj],clientsocks[clientsocks[jj]]);
                        close(clientsocks[jj]);  close(clientsocks[clientsocks[jj]]);
                        clientsocks[clientsocks[jj]]=0;     // 把数组中对端的socket置空，这一行代码和下一行代码的顺序不能乱。
                        clientsocks[jj]=0;                         // 把数组中本端的socket置空，这一行代码和上一行代码的顺序不能乱。
                    }
                }

                continue;
            }
            ////////////////////////////////////////////////////////

            // 如果发生事件的是命令通道。
            if (evs[ii].data.fd==cmdconnsock)
            {
                // 读取命令报文内容。
                char buffer[256];
                memset(buffer,0,sizeof(buffer));
                if (recv(cmdconnsock,buffer,sizeof(buffer),0)<=0)
                {
                    logfile.write("与外网的命令通道已断开。\n"); EXIT(-1);
                }

                // 如果收到的是心跳报文。
                if (strcmp(buffer,"<activetest>")==0) continue;

                // 如果收到的是新建连接的命令。

                // 向外网服务端发起连接请求。
                int srcsock=conntodst(argv[2],atoi(argv[3]));
                if (srcsock<0) continue;
                if (srcsock>=MAXSOCK)
                {
                    logfile.write("连接数已超过最大值%d。\n",MAXSOCK); close(srcsock); continue;
                }

                // 从命令报文内容中获取目标服务地址和端口。
                char dstip[11];
                int  dstport;
                getxmlbuffer(buffer,"dstip",dstip,30);
                getxmlbuffer(buffer,"dstport",dstport);

                // 向目标服务地址和端口发起socket连接。
                int dstsock=conntodst(dstip,dstport);
                if (dstsock<0) { close(srcsock); continue; }
                if (dstsock>=MAXSOCK)
                { 
                    logfile.write("连接数已超过最大值%d。\n",MAXSOCK); close(srcsock); close(dstsock); continue;
                } 

                // 把内网和外网的socket对接在一起。
                logfile.write("新建内外网通道(%d,%d) ok。\n",srcsock,dstsock);

                // 为新连接的两个socket准备可读事件，并添加到epoll中。
                ev.data.fd=srcsock; ev.events=EPOLLIN;
                epoll_ctl(epollfd,EPOLL_CTL_ADD,srcsock,&ev);
                ev.data.fd=dstsock; ev.events=EPOLLIN;
                epoll_ctl(epollfd,EPOLL_CTL_ADD,dstsock,&ev);

                // 更新clientsocks数组中两端soccket的值和活动时间。
                clientsocks[srcsock]=dstsock; clientsocks[dstsock]=srcsock;
                clientatime[srcsock]=time(0); clientatime[dstsock]=time(0);

                continue;
            }
            ////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////
            // 以下流程处理内外网通讯链路socket的事件。
      
            char buffer[5000];   // 从socket中读到的数据。
            int  buflen=0;          // 从socket中读到的数据的大小。

            // 从一端读取数据。
            if ( (buflen=recv(evs[ii].data.fd,buffer,sizeof(buffer),0)) <= 0 )
            {
                // 如果连接已断开，需要关闭两个通道的socket。
                logfile.write("client(%d,%d) disconnected。\n",evs[ii].data.fd,clientsocks[evs[ii].data.fd]);
                close(evs[ii].data.fd);                                      // 关闭客户端的连接。
                close(clientsocks[evs[ii].data.fd]);                  // 关闭客户端对端的连接。
                clientsocks[clientsocks[evs[ii].data.fd]]=0;    // 这一行代码和下一行代码的顺序不能乱。
                clientsocks[evs[ii].data.fd]=0;                        // 这一行代码和上一行代码的顺序不能乱。
                continue;
            }
      
            // 成功的读取到了数据，把接收到的报文内容原封不动的发给对端。
            logfile.write("from %d to %d,%d bytes。\n",evs[ii].data.fd,clientsocks[evs[ii].data.fd],buflen);
            send(clientsocks[evs[ii].data.fd],buffer,buflen,0);

            // 更新两端socket连接的活动时间。
            clientatime[evs[ii].data.fd]=time(0); 
            clientatime[clientsocks[evs[ii].data.fd]]=time(0);  
        }
    }

    return 0;
}

// 向目标地址和端口发起socket连接。
int conntodst(const char *ip,const int port,bool bio)
{
    // 第1步：创建客户端的socket。
    int sockfd;
    if ( (sockfd = socket(AF_INET,SOCK_STREAM,0))==-1) return -1; 

    // 第2步：向服务器发起连接请求。
    struct hostent* h;
    if ( (h = gethostbyname(ip)) == 0 ) { close(sockfd); return -1; }
  
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port); // 指定服务端的通讯端口。
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

    // 把socket设置为非阻塞。
    if (bio==false) fcntl(sockfd,F_SETFL,fcntl(sockfd,F_GETFD,0)|O_NONBLOCK);

    if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr))<0)
    {
        if (errno!=EINPROGRESS)
        {
            logfile.write("connect(%s,%d) %s failed.\n",ip,port); return -1;
        }
    }

    return sockfd;
}

void EXIT(int sig)
{
    logfile.write("程序退出，sig=%d。\n\n",sig);

    // 关闭内网程序与外网程序的命令通道。
    close(cmdconnsock);

    // 关闭全部客户端的socket。
    for (auto aa:clientsocks)
        if (aa>0) close(aa);

    close(epollfd);   // 关闭epoll。

    close(tfd);       // 关闭定时器。

    exit(0);
}