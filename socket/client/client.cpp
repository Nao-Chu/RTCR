#include "../inc/my_socket.h"

#include <pthread.h>
#include <string>
#include <iostream>

#include <string.h>
#include <sys/socket.h>
 
using namespace std;
 
pthread_t client_id;
void* recvll(void* p);
class BB
{
public:
	int tt(void *p);
};

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
	test.ClientRecvData(p);
	BB hh;
	//hh.tt(p);

}

int BB::tt(void *p)
{
	Client* client = (Client*)p;
	int socket = client->GetSocket();
	cout << "socket = " << socket << endl;

	char buff[1024];
	memset(buff, 0, 1024);
	int x= recv(socket, buff, 40, 0);
	cout << "x = " << x << endl;
	cout << "buff = " << buff << endl;

	return 0;
}
