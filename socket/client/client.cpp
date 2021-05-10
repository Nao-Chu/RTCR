#include "../inc/my_socket.h"

#include <pthread.h>

#include <iostream>
 
using namespace std;
 
pthread_t client_id;
int main(int argc, char** argv)
{
	MySocket* client = new Client();
	client->SetAddr();

	MyConnect* client_tcp = new MyConnect(client);
	client_tcp->TcpConnect();
 
	int socket = client->GetSocket();
	std::cout << "client socket = " << client->GetSocket() << "\n";

	char* data = "test";
	client->SetData(data);
	pthread_create(&client_id, NULL, Data::ClientSendData, (void*)client);
	pthread_create(&client_id, NULL, Data::ClientRecvData, (void*)client);
	while(1)
	{
	}
 
	return 0;
}
