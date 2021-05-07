#include <iostream>
#include <socket.h>
#include "stdlib.h"
#include "stdio.h"
#include "string"
 
using namespace std;
 
 
SOCKET clientSocket[1024];
int k = 0;
 
void communication(LPVOID n)
{
	char buff[256];
	int r;
	int i = (int)n;
	//cout << i << ":" << endl;
	while (1)
	{
 
		memset(buff, 0, 256);
		r = recv(clientSocket[i - 1], buff, 255, NULL);
		if (r > 0)
		{
			cout << i << ":" << buff << endl;
			for (int j = 0; j < k; j++)
			{
				send(clientSocket[j], buff, strlen(buff), NULL);
			}
		}
 
	}
}
 
 
int main()
{
 
	//加载socket库 版本号
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData) != 0;//成功==0
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		cout << "请求版本失败！\n" << endl;
		return -1;
	}
	cout << "请求版本成功!\n" << endl;
	//创建socket
	//sockSer = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);//AF=Address family ,ipv4,TCP,0
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		cout << "创建socket失败！\n" << endl;
		return -1;
	}
	cout << "创建socket成功！\n" << endl;
	//addrSer.sin_addr.S_un.S_addr
	SOCKADDR_IN addr = { 0 };
 
	//初始化地址
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");// htonl(INADDR_ANY);//inet_addr("192.168.0.13");//dec--->2进制-->网络字节序
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10086);//端口号~65535
	//绑定Socket
	int r = bind(serverSocket, (SOCKADDR*)&addr, sizeof(addr));
	if (r == -1)
	{
		cout << "bind失败！\n" << endl;
		return -1;
	}
	cout << "bind成功！\n" << endl;
	//listen
	r = listen(serverSocket, 10);
	if (r == -1)
	{
		cout << "listen失败！\n" << endl;
		return -1;
	}
	cout << "listen成功！\n" << endl;
	//连接
	//地址族
	SOCKADDR_IN cAddr = { 0 };
	int len = sizeof cAddr;
 
	//SOCKET clientSocket[1024];
	int i = 0;
	while (i < 1024)
	{
		clientSocket[i++] = accept(serverSocket, (sockaddr*)&cAddr, &len);
		k++;
		if (clientSocket[i - 1] == SOCKET_ERROR)
		{
			cout << "错误的客户端！\n" << endl;
			closesocket(serverSocket);
			WSACleanup();
			return -1;
		}
		cout << "有客户端接入进来！" << inet_ntoa(cAddr.sin_addr) << endl;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)communication, (LPVOID)i, NULL, NULL);
	}
 
 
	//closesocket(clientSocket);
	//closesocket(serverSocket);
	//WSACleanup();
	return 0;
}
