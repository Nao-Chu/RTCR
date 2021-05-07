#include "../inc/my_socket.h"

#include <pthread.h>

#include <iostream>
 
using namespace std;
 
pthread_t client_id;
int main(int argc, char** argv)
{
	int port = 8889; const char* addr = "192.168.43.5";
	MySocket* client = new Client();
	client->SetAddr(addr, port);

	MyConnect* client_tcp = new MyConnect(client);
	client_tcp->TcpConnect();
 
	int socket = client->GetSocket();
	pthread_create(&client_id, NULL, Data::ClientSendData, (void*)&socket);
	pthread_create(&client_id, NULL, Data::ClientRecvData, (void*)&socket);
	while(1)
	{
	}
 
	return 0;
}
