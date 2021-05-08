#include "../inc/my_socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <netinet/tcp.h>

#include <iostream>
#include <string>

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

void MyConnect::Listen()
{
	int ret = -1;
	do{
		socklen_t len_addr = sizeof(tcp_addr_);
		if (bind(tcp_socket_, (SA*)&tcp_addr_, len_addr) == -1)
			break;

		if (listen(tcp_socket_, 5) == -1)
			break;

		ret = 0;
	}while(0);
	if (ret == -1)
		close(tcp_socket_);
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
int Data::all_socket[Data::user_max_] = {0};
Data::Data()
{
}

Data::~Data()
{
}

void* Data::ClientRecvData(void* s)
{
	int socket = *(int*)s;
	char buff[recv_max_data_];
	int recv_len;
	while(1)
	{
		memset(buff,0,recv_max_data_);
		recv_len = recv(socket,buff,recv_max_data_ - 1,0);
		if (recv_len <= 0){
			std::cout << "recv end\n"; 
			break;
		}
		std::cout << "$:" << buff << std::endl;
	}
}

void* Data::ClientSendData(void* s)
{
	int socket = *(int*)s;
	int send_len;
	while(1)
	{
		std::string str;
		std::getline(std::cin, str);
		if(str == "quit"){
			std::cout << "byby\n";
			exit(0);
		}
		const char* buff = str.c_str();
		send_len = send(socket,buff,sizeof(str),0);
		if (send_len < 0){
			std::cout << "send end\n";
			break;
		}
	}
}

void* Data::ServerRecvData(void* s)
{
	int socket = *(int *)s;
	char buff[recv_max_data_];
	int recv_len;
	while(true)
	{
		memset(buff, 0, recv_max_data_);
		recv_len = recv(socket, buff, recv_max_data_ - 1, 0);
		usleep(10000);
		std::cout << "recv: " << buff << std::endl;
		if (recv_len <= 0){
			std::cout << "recv end\n"; 
			all_socket[socket] = 0;
			break;
		}
		
		ServerSendData(buff);
	}
}

void Data::ServerSendData(char* b)
{
	char buff[send_max_data_];
	memset(buff, 0, recv_max_data_);

	int send_len = 0;
	for (; b[send_len] != '\0'; ++send_len)
	{
		buff[send_len] = b[send_len];
	}
	buff[++send_len] = '\0';

	for(int i = 0; i < user_max_; i++)
	{
		if (all_socket[i] == 0)
			continue;

		send_len = send(all_socket[i],buff,send_len,0);
		if(send_len < 0)
		{
			std::cout << "send error\n";
		}
	}
}

