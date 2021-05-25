#include "../inc/my_socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <netinet/tcp.h>
#include <errno.h>
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
	std::cout << "Clinet: \n";
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

	char buff[1024];
	memset(buff, 0, 1024);

	int len = recv(socket, buff, 1024, 0);
	if (len <= 0){
		std::cout << "recv end\n"; 
		return -1;
	}
	std::cout << "recv = " << buff << std::endl;
	client->SetData(buff);
	
	return 0;
}

int Data::ClientSendData(void* p)
{
	Client* client = (Client*)p;
	std::cout << "client&= " << (void*)client << std::endl;
	int socket = client->GetSocket();
	int send_len = client->GetSendLen();
	std::string senddata = client->GetData();
	std::cout << "t data&= " << &senddata << std::endl;

	std::cout << "send len= " << send_len<< std::endl;
	std::cout << "send data= " << senddata<< std::endl;
	send_len = send(socket, senddata, send_len, 0);
	if (send_len <= 0){
		std::cout << "send error\n";
		return -1;
	}
	std::cout << "send len = " << send_len << std::endl;
	return 0;
}

int Data::ServerRecvData(int socket)
{
	char buff[1024];

	User* temp = User::GetSingleton();
	int ret = 0;
	while(true)
	{
		memset(buff, 0, sizeof(buff));
		int recv_len = recv(socket, buff, sizeof(buff), 0);
		std::cout << "sock: " << socket << std::endl;
		if (recv_len <= 0){
			std::cout << "recv end\n"; 
			temp->DelUserInf(socket);
			ret = -1;
			break;
		}
		
		ret = ServerSendData(buff, recv_len);
	}
	return ret;
}

int Data::ServerSendData(char* b, int len)
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
			return -1;
		}
	}
	return 0;
}




/* 
 * class :  User 
 * author:  ZZP
 */
User::User()
{
}
User* User::user_ = new User;

void User::AddUserInf(int socket, std::string name)
{
	user_inf_.insert(std::pair<int, std::string>(socket, name));
}

void User::DelUserInf(int socket)
{
	user_inf_.erase(socket);
}

std::list<int> User::GetSocket()
{
	std::list<int> key;
	std::map<int, std::string>::const_iterator it = user_inf_.begin();
	for( ; it != user_inf_.end(); ++it)
	{
		key.push_back(it->first);
	}
	return key;
}

std::list<std::string> User::GetName()
{
	std::list<std::string> value;
	std::map<int, std::string>::const_iterator it = user_inf_.begin();
	for( ; it != user_inf_.end(); ++it)
	{
		value.push_back(it->second);
	}
	return value;
}

std::string User::FindName(int i)
{
	std::map<int, std::string>::iterator it = user_inf_.find(i);
	return it->second;
}

const char* MESS::communicate = "communicate";
const char* MESS::signin = "signin"; 
const char* MESS::signup = "signup";
const char* MESS::users  = "users";
const char* MESS::emoji  = "emoji";
const char* MESS::file   = "file";
