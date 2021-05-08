#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_


#include <sys/socket.h>
#include <arpa/inet.h>
typedef struct sockaddr_in SAIN;
typedef struct sockaddr SA;


class MySocket
{
public:
	virtual int GetSocket() = 0;
	virtual SAIN GetAddr() = 0;
	virtual void SetAddr() = 0;

protected:
	const int port_ = 5180;

};


class Client : public MySocket
{
public:
	Client();
	virtual ~Client();
	virtual int GetSocket()
	{
		return client_socket_;
	}
	virtual SAIN GetAddr()
	{
		return client_addr_;
	}
	virtual void SetAddr();
private:
	int client_socket_;
	SAIN client_addr_;
};

class Server: public MySocket
{
public:
	Server();
	virtual ~Server();
	virtual int GetSocket()
	{
		return server_socket_;
	}
	virtual SAIN GetAddr()
	{
		return server_addr_;
	}
	virtual void SetAddr();
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
	int Listen();
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
	static void* ServerRecvData(void* s);
	static void ServerSendData(char* b);
	static const int user_max_ = 100;
	static int all_socket[user_max_];

private:
	static const int send_max_data_ = 1024;
	static const int recv_max_data_ = 1024;

};

#endif
