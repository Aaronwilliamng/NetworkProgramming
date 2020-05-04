#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<ctime>
#define MAXLINE 4096
int main(int argc,char**argv){
    int sockfd,n;
    char recvline[4096],sendline[4096];
    struct sockaddr_in servaddr;
    if(argc != 2){
        std::cout<<"usage: ./client <ipaddress>\n";
        return 0;
    }
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        std::cout<<"create socket error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
        return 0;
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<= 0){
        std::cout<<"inet_pton error for "<<argv[1]<<"\n";
        return 0;
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
        std::cout<<"connect error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
        return 0;
    }
    //set time
    time_t rawtime;
    struct tm *ptminfo;
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    while(1){
        std::cout<<ptminfo->tm_year + 1900<<"/"<<ptminfo->tm_mon + 1<<"/"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec<<"\t\n";
        fgets(sendline,4096,stdin);
        if(send(sockfd,sendline,strlen(sendline),0) < 0){
            std::cout<<"send message error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
            return 0;
        } 
    }

    close(sockfd);
    return 0;
}