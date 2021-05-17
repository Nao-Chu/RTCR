#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_


#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <list>
#include <string>
#include <map>

typedef struct sockaddr_in SAIN;
typedef struct sockaddr SA;
const int port_ = 5180;

class MySocket
{
public:
	virtual ~MySocket() = 0;
	virtual int GetSocket() = 0;
	virtual SAIN GetAddr() = 0;
	virtual void SetAddr() = 0;
	virtual void* GetData() = 0;
	virtual void SetData(void*) = 0;
	virtual void CloseSocket() = 0;
	virtual int GetSendLen() = 0;
	virtual void SetSendLen(int sendlen) = 0;
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
	virtual void* GetData()
	{
		return client_data_;
	}
	virtual void SetData(void* data)
	{
		client_data_ = data;
	}
	virtual void CloseSocket()
	{
		close(client_socket_);
	}
	virtual int GetSendLen()
	{
		return client_sendlen_;
	}
	virtual void SetSendLen(int sendlen)
	{
		client_sendlen_ = sendlen;
	}
private:
	int client_socket_;
	SAIN client_addr_;
	void* client_data_;
	int client_sendlen_;
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
	virtual void* GetData()
	{
		return server_data_;
	}
	virtual void SetData(void* data)
	{
		server_data_ = data;
	}
	virtual void CloseSocket()
	{
		close(server_socket_);
	}
	virtual int GetSendLen()
	{
		return server_sendlen_;
	}
	virtual void SetSendLen(int sendlen)
	{
		server_sendlen_ = sendlen;
	}
private:
	int server_socket_;
	SAIN server_addr_;
	void* server_data_;
	int server_sendlen_;
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
	int ClientRecvData(void* p);
	int ClientSendData(void* p);
	static void* ServerRecvData(void* s);
	static void ServerSendData(char* b, int len);

private:
	static const int send_max_data_ = 1024;
	static const int recv_max_data_ = 1024;

};

class User
{
public: 
	void AddUserInf(int socket, std::string name);
	void DelUserInf(int socket);
	std::list<int> GetSocket();
	std::list<std::string> GetName();
	std::string FindName(int i);
	static User* GetSingleton()
	{
		return user_;
	}

private:
	std::map<int, std::string> user_inf_;
	User();
	static User* user_;
};
#endif
