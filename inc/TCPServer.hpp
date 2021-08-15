#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAXPACKETSIZE 4096

class TCPServer
{
private:
	static void * Task(void * argv);
public:
	int sockfd, newsockfd, n, pid;
	struct sockaddr_in serverAddress;
	struct sockaddr_in clientAddress;
	pthread_t serverThread;
	char msg[MAXPACKETSIZE];
	static std::string Message;


	TCPServer();
	~TCPServer();

	void setup(int port);
	std::string receive();
	std::string getMessage();
	void Send(std::string msg);
	void detach();
	void clean();
	
};

#endif