#include "../inc/my_socket.h"

#include <iostream>
 
using namespace std;
 
int main()
{
	int port = 8889;
	MySocket* server = new Server();
	server->SetAddr(NULL,port);

	int socket = server->GetSocket();
	int opt = SO_REUSEADDR;
	setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	MyConnect* server_tcp = new MyConnect(server);
        server_tcp->Listen();	

	Data server_data;
	int max = Data::max_;
	int all_socket[max] = {0};
	while(true)
	{
		int client_socket;
		if((client_socket = server_tcp->Accept()) == -1)
			continue;
		
		for (int i = 0; i < max; i++){
			if(all_socket[i] == 0){
				all_socket[i] = client_socket;
				break;
			}
		}

		server_data.ServerRecvData(client_socket,all_socket);
	}
 
 
	return 0;
}
