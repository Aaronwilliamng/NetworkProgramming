all:server client
server:server.o
	g++ -g server.o -o server
client:client.o
	g++ -g client.o -o client 
server.o:server.cpp
	g++ -g -c server.cpp
client.o:client.cpp
	g++ -g -c client.cpp
clean:
	rm server.o client.o server client