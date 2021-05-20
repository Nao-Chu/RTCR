#include "sendmessstate.h"

MySocket* SENDMESSFNC::temp_client = NULL;
int SENDMESSFNC::SendDataToServer(const QString& head, const QString& senddata, const MySocket* c)
{
    Client* client = (Client*)c;
    QString send_data = head + "#" + senddata + '\0';
    QByteArray ba = send_data.toLocal8Bit();
    client->SetData(ba.data());
    client->SetSendLen(ba.length());
    qDebug("SendDataToServer: buff = %s",ba.data());

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

    char* buff = (char*)client->GetData();
    qDebug("recv success, buff = %s", buff);

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


    return buff[1];
}
