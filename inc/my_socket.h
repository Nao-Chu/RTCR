#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_


#include <sys/socket.h>
#include <arpa/inet.h>
typedef struct sockaddr_in SAIN;
typedef struct sockaddr SA;

class MySocket
{
public:
	virtual SAIN GetAddr() = 0;
	virtual int GetSocket() = 0;
	virtual void SetAddr(SAIN &addr) = 0;
private:

};


class MyConnect
{
public:
	MyConnect();
	MyConnect(MySocket* socket) { 
		tcp_socket_ = socket->GetSocket();
		tcp_addr_   = socket->GetAddr();
	}
	void TcpConnect();
	int TimeoutConnect();
	int Fcntl(int flag, int get = 0);
private:
	int tcp_socket_;
	SAIN tcp_addr_;
};


class Client : public MySocket
{
public:
	virtual int GetSocket()
	{
		return client_socket_;
	}
	virtual SAIN GetAddr()
	{
		return client_addr_;
	}
	virtual void SetAddr(const char* addr, int port);
	Client();
	void DoMain();
private:
	int client_socket_;
	SAIN client_addr_;
};

class Server: public MySocket
{
public:
private:
	int server_socket_;
};

#endif
