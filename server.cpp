#include <iostream>
#include "inc/TCPServer.hpp"

TCPServer tcp;

void *loop(void * m)
{
	(void)m;
	pthread_detach(pthread_self());
	while (1)
	{
		srand(time(NULL));
		char ch = 'a' + rand() % 26;
		std::string s(1, ch);
		std::string str = tcp.getMessage();
		if (str != "")
		{
			std::cout << "Message: " << str << std::endl;
			tcp.Send(" [client message: " + str + "] " + s);
			tcp.clean();
		}
		usleep(1000);
	}
	tcp.detach();
}

int main(int argc, char const *argv[])
{
	pthread_t msg;

	(void)argc;
	(void)argv;

	tcp.setup(11999);
	if (pthread_create(&msg, NULL, loop, (void *)0) == 0)
	{
		tcp.receive();
	}
	return 0;
}