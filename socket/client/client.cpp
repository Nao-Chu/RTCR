#include "../inc/my_socket.h"

#include <pthread.h>
#include <string>
#include <iostream>

#include <string.h>
#include <sys/socket.h>
 
using namespace std;

void* recvll(void* p);
int main(int argc, char** argv)
{
	MySocket* client = new Client();
	client->SetAddr();

	MyConnect* client_tcp = new MyConnect(client);
	client_tcp->TcpConnect();
 
	int socket = client->GetSocket();
	std::cout << "client socket = " << client->GetSocket() << "\n";

	pthread_t recvid;
	pthread_create(&recvid, NULL, recvll, (void*)client);
	Data test;
	while(1)
	{
		char* data = new char;
		std::cin >> data;
		std::cout << "data = " << data << std::endl;
		client->SetData(data);
		client->SetSendLen(sizeof(data));
		test.ClientSendData(client);
	}
 
	return 0;
}

void* recvll(void* p)
{
	Data test;
	Client* client = (Client*)p;
	if(test.ClientRecvData(client) == -1)
	{
		cout << "error\n";
	}
	char* buff = (char*)client->GetData();
	cout << "data = " << buff << endl;

}

