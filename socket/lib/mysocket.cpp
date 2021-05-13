#include "../inc/my_socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <netinet/tcp.h>

#include <iostream>


/* 
 * class :  MySocket
 * author:  ZZP
 */
MySocket::~MySocket()
{

}

/* 
 * class :  Client 
 * author:  ZZP
 */

Client::Client()
{
	client_socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client_socket_ == -1)
	{
		printf("socket file\n");
		return;
	}
}

Client::~Client()
{
}

void Client::SetAddr()
{
	memset(&client_addr_, 0, sizeof(client_addr_));
	client_addr_.sin_family = AF_INET;
	client_addr_.sin_port   = htons(port_);
	client_addr_.sin_addr.s_addr = INADDR_ANY;
}





/* 
 * class :  Server 
 * author:  ZZP
 */
Server::Server()
{
	server_socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server_socket_ == -1)
	{
		printf("socket file\n");
		return;
	}
}

Server::~Server()
{
}

void Server::SetAddr()
{
	memset(&server_addr_, 0, sizeof(server_addr_));
	server_addr_.sin_family = AF_INET;
	server_addr_.sin_port   = htons(port_);
	server_addr_.sin_addr.s_addr = INADDR_ANY;
}










/* 
 * class :  MyConncet 
 * author:  ZZP
 */
void MyConnect::TcpConnect()
{
	int ret = 0;
	do{
		int flag = Fcntl(F_GETFD, true); 
		if ((ret = Fcntl(flag | O_NONBLOCK) ) == -1)
			break;

		if ((ret = TimeoutConnect() ) == -1)
			break;

		if ((ret = Fcntl(flag & (~O_NONBLOCK)) ) == -1)
			break;

	} while(0);

	if (ret == -1){
		close(tcp_socket_);
	}
}

int MyConnect::TimeoutConnect()
{
	socklen_t len_addr = sizeof(tcp_addr_);
	if (connect(tcp_socket_, (SA*)&tcp_addr_, len_addr) == 0)
		return 0;

	if (!(errno == EINPROGRESS))
		return -1;

	fd_set fdw;
	FD_ZERO(&fdw);
	FD_SET(tcp_socket_, &fdw);

	struct timeval timeout;
	timeout.tv_sec = 6;
	timeout.tv_usec = 0;

	if (select(tcp_socket_+1, NULL, &fdw, NULL, &timeout) <= 0){
		return -1;
	}
	return 0;
}

int MyConnect::Fcntl(int flag, int get)
{
	int ret;
	if(get) 
	{
		ret = fcntl(tcp_socket_, flag);
	} else {
		ret = fcntl(tcp_socket_, F_SETFD, flag);
	}
	if (ret == -1){
		printf("set flags error\n");
		return -1;
	}
	return ret;
}

int MyConnect::Listen()
{
	int ret = 0;
	do{
		socklen_t len_addr = sizeof(tcp_addr_);
		if (bind(tcp_socket_, (SA*)&tcp_addr_, len_addr) == -1)
			break;

		if (listen(tcp_socket_, 5) == -1)
			break;

		ret = 1;
	}while(0);
	if (ret ==  0)
		close(tcp_socket_);
	
	return ret;
}

int MyConnect::Accept()
{
	int client_socket;
	SAIN client_addr;
	socklen_t len_addr = sizeof(client_addr);
	client_socket = accept(tcp_socket_, (SA*)&client_addr, &len_addr);
	return client_socket;
}





/* 
 * class :  Data
 * author:  ZZP
 */
Data::Data() 
{
}

Data::~Data()
{
}

int Data::ClientRecvData(void* p)
{
	Client* client = (Client*)p;

	int socket = client->GetSocket();

	char buff[recv_max_data_];
	memset(buff, 0, recv_max_data_);

	int len = recv(socket, buff, recv_max_data_, 0);
	if (len <= 0){
		std::cout << "recv end\n"; 
		return -1;
	}
	std::cout << "buff: " << buff << std::endl;
	client->SetData(buff);
	std::cout << "client &: " << (void*)client<< std::endl;
	
	return 0;
}

int Data::ClientSendData(void* p)
{
	Client client = *(Client*)p;
	int socket = client.GetSocket();
	int send_len = client.GetSendLen();

	send_len = send(socket, client.GetData(), send_len, 0);
	if (send_len <= 0){
		std::cout << "send end\n";
		return -1;
	}
	std::cout << "send end\n";
	return 0;
}

void* Data::ServerRecvData(void* s)
{
	int socket = *(int *)s;
	char buff[recv_max_data_];
	int recv_len;

	User* temp = User::GetSingleton();
	while(true)
	{
		memset(buff, 0, sizeof(buff));
		recv_len = recv(socket, buff, sizeof(buff), 0);
		std::cout << "sock: " << socket << std::endl;
		if (recv_len <= 0){
			std::cout << "recv end\n"; 
			temp->DelSocket(socket);
			break;
		}
		
		ServerSendData(buff, recv_len);
	}
	return 0;
}

void Data::ServerSendData(char* b, int len)
{
	User* temp = User::GetSingleton();
	std::list<int> s = temp->GetSocket();
	std::list<int>::iterator it = s.begin();

	for (; it != s.end(); ++it)
	{
		std::cout << "send buff: " << b;
		std::cout << " \nsocket = " << *it << std::endl;
		len = send(*it, b, len, 0);
		if(len <= 0)
		{
			std::cout << "send error\n";
		}
	}
}




/* 
 * class :  User 
 * author:  ZZP
 */
User::User()
{
}
User* User::user_ = new User;

void User::AddSocket(int socket)
{
	sockets_.push_back(socket);
}

void User::DelSocket(int socket)
{
	sockets_.remove(socket);
}

std::list<int> User::GetSocket()
{
	return sockets_;
}
