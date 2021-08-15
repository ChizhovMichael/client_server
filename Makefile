server:
	clang++ -Wall -Wextra -Werror -o server server.cpp -I ./inc/ TCPServer.cpp TCPClient.cpp -std=c++11 -lpthread

client:
	clang++ -Wall -Wextra -Werror -o client client.cpp -I ./inc/ TCPServer.cpp TCPClient.cpp -std=c++11 -lpthread

clean:
	rm -f client server

re: clean server client