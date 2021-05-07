#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_


#include <sys/socket.h>
#include <arpa/inet.h>
typedef struct sockaddr_in SAIN;
typedef struct sockaddr SA;

#define SIZE	10240
#define MYKEY	12345


class MySocket
{
public:
	virtual int GetSocket() = 0;
	virtual SAIN GetAddr() = 0;
	virtual void SetAddr(const char* addr, int port) = 0; 
private:

};


class Client : public MySocket
{
public:
	Client();
	~Client();
	virtual int GetSocket()
	{
		return client_socket_;
	}
	virtual SAIN GetAddr()
	{
		return client_addr_;
	}
	virtual void SetAddr(const char* addr, int port);
private:
	int client_socket_;
	SAIN client_addr_;
};

class Server: public MySocket
{
public:
	Server();
	~Server();
	virtual int GetSocket()
	{
		return server_socket_;
	}
	virtual SAIN GetAddr()
	{
		return server_addr_;
	}
	virtual void SetAddr(const char* addr, int port);
private:
	int server_socket_;
	SAIN server_addr_;
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
	void Listen();
	int Accept();
private:
	int tcp_socket_;
	SAIN tcp_addr_;
};

class Data
{
public: 
	Data();
	~Data();
	static void* ClientRecvData(void* s);
	static void* ClientSendData(void* s);
	void ServerRecvData(int s,int* ss);
	void ServerSendData(int* s);
	static const int max_ = 100;

private:
	char recv_data_[1024];
};

#endif
