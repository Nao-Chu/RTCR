#include <iostream>
#include "my_socket.h"
 
using namespace std;
 
void recvAndShow()
{
	int r, i = 0;
	char buff[256];
	//ofstream out;
	while (1)
	{
		memset(buff, 0, 256);
		r = recv(serverSocket, buff, 255, NULL);
		if (r > 0)
		{
		//	out.open("QQ.txt", ios::app||ios::_Nocreate);
		//	out << buff << endl;
			//outtextxy(0, i * 20, buff);
			i++;
			//out.close();
		}
	}
}
 
int main(int argc, char** argv)
{
	int port; char* addr;
	MySocket* client = new Client();
	client->SetAddr(addr, port);

	MyConnect* client_tcp = new Connect(client);
	client_tcp.TcpConnect();
 
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)recvAndShow, NULL, NULL, NULL);
 
	char buff[256];
	while (1)
	{
		memset(buff, 0, 256);
		cout << "你要发啥？\n" << endl;
		cin >> buff;
		r = send(serverSocket, buff, strlen(buff), NULL);
		if (r > 0)
		{
			cout << "发送" << r << "字节到服务器成功！\n" << endl;
		}
 
	}
	//closesocket(serverSocket);
	//WSACleanup();
	return 0;
}
