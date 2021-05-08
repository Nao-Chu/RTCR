#include "../inc/my_socket.h"

#include <unistd.h>

#include <iostream>
 
using namespace std;
 
int main()
{
	MySocket* server = new Server();
	server->SetAddr();

	int socket = server->GetSocket();
	int opt = SO_REUSEADDR;
	setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	MyConnect* server_tcp = new MyConnect(server);
        server_tcp->Listen();	

	pthread_t server_id;
	int accept_socket;
	while(true)
	{
		if((accept_socket = server_tcp->Accept()) == -1)
			continue;
		
		Data::all_socket[accept_socket] = accept_socket;

		pthread_create(&server_id, NULL, Data::ServerRecvData, (void*)&accept_socket);
	}

	std::cout << "byby\n" << endl;
	close(accept_socket);
 
 
	return 0;
}
