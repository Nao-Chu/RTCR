#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_


#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

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
	virtual int GetSocket() const = 0;
	virtual SAIN GetAddr() const = 0;
	virtual void SetAddr() = 0;
	virtual void* GetData() const = 0;
	virtual void SetData(char*) = 0;
	virtual void CloseSocket() const = 0;
	virtual int GetSendLen() const = 0;
	virtual void SetSendLen(const int sendlen) = 0;
};


class Client : public MySocket
{
public:
	Client();
	virtual ~Client();
	virtual int GetSocket() const
	{
		return client_socket_;
	}
	virtual SAIN GetAddr() const
	{
		return client_addr_;
	}
	virtual void SetAddr();
	virtual void* GetData() const
	{
		return (void*)client_data_;
	}
	virtual void SetData(char* data)
	{
		memset(client_data_, 0, 1024);
		strcpy(client_data_, data);
	}

	virtual void CloseSocket() const
	{
		close(client_socket_);
	}
	virtual int GetSendLen() const
	{
		return client_sendlen_;
	}
	virtual void SetSendLen(const int sendlen)
	{
		client_sendlen_ = sendlen;
	}
private:
	int client_socket_;
	SAIN client_addr_;
	char client_data_[1024];
	int client_sendlen_;
};

class Server: public MySocket
{
public:
	Server();
	virtual ~Server();
	virtual int GetSocket() const
	{
		return server_socket_;
	}

	virtual SAIN GetAddr() const
	{
		return server_addr_;
	}
	virtual void SetAddr();
	

	virtual void* GetData() const
	{
		return (void*)server_data_;
	}
	virtual void SetData(char* data)
	{
		memset(server_data_, 0, 1024);
		strcpy(server_data_, data);
	}

	virtual void CloseSocket() const
	{
		close(server_socket_);
	}

	virtual int GetSendLen() const
	{
		return server_sendlen_;
	}
	virtual void SetSendLen(const int sendlen)
	{
		server_sendlen_ = sendlen;
	}
private:
	int server_socket_;
	SAIN server_addr_;
	char server_data_[1024];
	int server_sendlen_;
};


class MyConnect
{
public:
	MyConnect();
	MyConnect(const MySocket* socket) { 
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
	int ServerRecvData(int socket);
	int ServerSendData(char* b, int len);
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

namespace MESS 
{
	extern const char* communicate;
	extern const char* signin;
	extern const char* signup;
	extern const char* users;
}

#endif
