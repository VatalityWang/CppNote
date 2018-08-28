//server.cpp
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

#define LISTEN_PORT 2000
void str_echo(int sockfd) // 服务器收到客户端的消息后的响应
{
    ssize_t n;
    char line[512];

    printf("ready to read\n");

    while ((n = read(sockfd, line, 512)) > 0)
    {

        line[n] = '\0';
        printf("Client: %s\n", line);
        char msgBack[512];
        snprintf(msgBack, sizeof(msgBack), "recv: %s\n", line);
        write(sockfd, msgBack, strlen(msgBack));
        bzero(&line, sizeof(line));
    }

    printf("end read\n");
}

void sig_child(int signo) //父进程对子进程结束的信号处理
{
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);

    return;
}

void *acceptThreadFun(void *arg)
{
    int listenfd = *((int *)arg);
    struct sockaddr_in chiaddr;
    socklen_t chilen;
    int connfd;
    for (;;)
    {
        chilen = sizeof(chiaddr);

        connfd = accept(listenfd, (struct sockaddr *)&chiaddr, &chilen);
        //accept会总listen所维护的已连接队列中pop一个出来
        //阻塞在accept，直到三次握手成功了才返回
        if (connfd == -1)
            printf("accept client error: %s\n", strerror(errno));
        else
            printf("client connected :%d\n", 1);

        close(connfd);
    }
}
int successCount = 0;
int main(int argc, char **argv)
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t chilen;

    struct sockaddr_in chiaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1)
    {
        printf("socket established error: %s\n", (char *)strerror(errno)); //后面需要采用日志到方式来记录
        //socket创建失败后可以让用户选择重新连接
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(LISTEN_PORT);

    int bindc = bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bindc == -1)
    {
        printf("bind error: %s\n", strerror(errno));
        //绑定失败，错误提示
    }

    listen(listenfd, 10); //limit是SOMAXCONN

    signal(SIGCHLD, sig_child);

    pthread_t acceptThread[20];
    int threadCount = 0;
    int err;
    for (threadCount; threadCount < 20; threadCount++)
    {
        err = pthread_create(&acceptThread[threadCount], NULL, acceptThreadFun, &listenfd); //创建线程来帮忙accept
        if (err != 0)
            printf("can not create thread : %s\n", strerror(errno));
    }

    for (;;)
    {
        chilen = sizeof(chiaddr);

        connfd = accept(listenfd, (struct sockaddr *)&chiaddr, &chilen);
        //accept会总listen所维护的已连接队列中pop一个出来
        //阻塞在accept，直到三次握手成功了才返回
        if (connfd == -1)
            printf("accept client error: %s\n", strerror(errno));
        else
            printf("client connected :%d\n", ++successCount);

        close(connfd);
    }
}