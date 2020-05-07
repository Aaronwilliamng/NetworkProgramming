all:client server
client:client.o
	g++ -g client.o -o client
server:server.o
	g++ -g server.o -o server
client.o:client.cpp
	g++ -g -c client.cpp
serber.o:server.cpp
	g++ -g -c server.cpp
clean:
	rm server client server.o client.o