#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<ctime>
//using namespace std;
#define MAXLINE 4096
int main(int argc,char** argv){
    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[4096];
    int n;
    if((listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        //strerrno(errno):print error information;
        //errno:error code
        std::cout<<"create socket error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
        return 0;
    }
    //set socket address
    //memset:clean address first
    //INADDR_ANY:set the address to 0.0.0.0,which means any address
    //set the port to 6666
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);
    //bind the socket
    if(bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
        std::cout<<"bind socket error:"<<strerror(errno)<<"(error:"<<errno<<")\n";
        return 0;
    }
    //max length of listen queue:10
    if(listen(listenfd,10)== -1){
        std::cout<<"listen socket error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
        return 0;
    }    
    std::cout<<"==========waiting for client's request================\n";
    time_t rawtime;
    struct tm *ptminfo;
    //waiting
    while(1){
        time(&rawtime);
        ptminfo = localtime(&rawtime);
        if((connfd = accept(listenfd,(struct sockaddr*)NULL,NULL))== -1){
            
            std::cout<<"accept socket error:"<<strerror(errno)<<"(errno:"<<errno<<")\n";
            continue;
        }
        n = recv(connfd,buff,MAXLINE,0);
        buff[n] = '\0';//no '\0' at the end of buff,we need to add it manually
        std::cout<<ptminfo->tm_year + 1900<<"/"<<ptminfo->tm_mon + 1<<"/"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec<<":"<<buff<<"\n";
        close(connfd);
    }
    close(listenfd);
    return 0;
}