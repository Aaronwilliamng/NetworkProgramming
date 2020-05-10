# 网络编程实践



## Project 1:单向发送消息(client -> server)

### DEMO:

**功能**: 通过client(图中Linux ubuntu主机)向server(图中MacOS主机)发送消息, server接收消息并输出

![1-1](image/1/1.png)



### 如何使用:

- 文件包含在`./1_SendMessageUnidirection`中
- 其中包含:
  - client.cpp和server.cpp
  - client和server, 可执行文件, 如果这两个文件存在, 可直接跳到下一步骤“运行server和client”; 如果没有, 通过下一步的makefile文件生成这两个可执行文件
  - 一个makefile文件: 用于编译链接生成可执行文件(client和server)
    - 在路径下执行`make`即可
    - 若修改client.cpp或server.cpp后, 可删除相关.o文件和可执行文件,先`make clean`,在`make`
  - 可能会有client.o, server.o, 是在makefile过程中生成的中间编译文件, 可忽略可删除
- 运行server和client
  - 终端一: 在路径执行`./server`, 启动服务端, 监听6666端口
  - 终端二: (需要在server启动后执行)在路径下执行`./client [server主机地址]`, 如`./client 127.0.0.1`(本地地址), 之后输入发送内容即可
  - 若终端没有`ctrl+c`正常退出或其他情况出现bind socket error:Address already in use(error:48), 可执行`sudo lsof -i:6666`查看6666号端号占用情况, 执行`sudo kill [PID]`干掉对应进程





## Project2: GroupChatRoom群聊天

### DEMO

![1-2](image/1/2.png)



**功能: **在Project 1的基础上做了改进, 实现了使用poll的I/O复用的服务器, 支持多客户端同时在线聊天, 服务端支持同时处理网络连接和用户输入



### 如何使用
- 文件包含在`./2_Chatroom`中
- 其中包含:
  - client.cpp和server.cpp
  - client和server, 可执行文件, 如果这两个文件存在, 可直接跳到下一步骤“运行server和client”; 如果没有, 通过下一步的makefile文件生成这两个可执行文件
  - 一个makefile文件: 用于编译链接生成可执行文件(client和server)
    - 在路径下执行`make`即可
    - 若修改client.cpp或server.cpp后, 可删除相关.o文件和可执行文件, 先`make clean`,在`make`
  - 可能会有client.o, server.o, 是在makefile过程中生成的中间编译文件, 可忽略可删除
- 运行server和client
  - 终端一: 在路径执行`./server {listen ip address} {listen port}`, 如`./server 127.0.0.1 31415`, 启动服务端监听本地31415端口
  - 其他终端(终端二、三、四等): (需要在server启动后执行)在路径下执行`./client {server主机地址} {port}`, 如`./client 127.0.0.1 31415`(本地地址), 之后输入发送内容即可
  - 若终端没有`ctrl+c`正常退出或其他情况出现bind socket error:Address already in use(error:48), 可执行`sudo lsof -i:6666`查看6666号端号占用情况, 执行`sudo kill [PID]`干掉对应进程




