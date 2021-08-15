#include <iostream>
#include <signal.h>
#include "TCPClient.hpp"

TCPClient tcp;

void sig_exit(int s)
{
	(void)s;
	tcp.exit();
	exit(0);
}

int main(int argc, char const *argv[])
{
	(void)argv;
	(void)argc;
	// Обработчик выхода
	signal(SIGINT, sig_exit);

	tcp.setup("127.0.0.1", 11999);
	while(1)
	{
		srand(time(NULL));
		tcp.Send(std::to_string(rand() % 25000));
		std::string rec = tcp.receive();
		if (rec != "")
		{
			std::cout << "Server response: " << rec << std::endl;
		}
		sleep(1);
	}
	return 0;
}