#include "sendmessstate.h"

MySocket* SENDMESSFNC::temp_client = NULL;
int SENDMESSFNC::SendDataToServer(const QString& head, const QString& senddata, const MySocket* c)
{
    Client* client = (Client*)c;
    QString send_data = head + "#" + senddata;
    QByteArray ba = send_data.toLatin1();

    client->SetData((char*)ba.data());
    client->SetSendLen(send_data.length());
    qDebug("buff = %s",ba.data());

    Data data;
    if (data.ClientSendData(client) == -1){
        qDebug("ClientSendData error");
        return -1;
    }

    return 0;
}

char SENDMESSFNC::SignInUpRequest(const QString& type, const QString& user, const QString& passwd)
{
    MySocket* client = new Client();
    client->SetAddr();

    MyConnect* client_tcp = new MyConnect(client);
    client_tcp->TcpConnect();

    QString head = type == "in" ? QString::fromUtf8(MESS::signin) : QString::fromUtf8(MESS::signup);
    QString senddata = user + '#' + passwd + '\0';

    if (SendDataToServer(head, senddata, client) == -1)
    {
        return 'e';
    }

    Data data;
    if (data.ClientRecvData(client) == -1)
    {
        qDebug("ClientRecvData error");
        return 'e';
    }

    char* buff = new char;
    memset(buff, 0 ,8);
    buff = (char*)client->GetData();

    if (QString::localeAwareCompare(type,"up") == 0)
        client->CloseSocket();
    else
        SENDMESSFNC::temp_client = client;

    delete client_tcp;

    if (buff[0] != '#' )
    {
        qDebug("recv error");
        return 'e';
    }

    qDebug("recv success, buff = %s", buff);
    return buff[1];
}
