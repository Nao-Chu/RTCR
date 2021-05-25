#include "sendmessstate.h"
#include <QFile>
#include <QDebug>
#include <string>
#include <QStringList>

MySocket* SENDMESSFNC::temp_client = NULL;

int SENDMESSFNC::SendDataToServer(const QString& headdata, const QByteArray& senddata, const MySocket* c)
{
    Client* client = (Client*)c;
    QByteArray headba = headdata.toLocal8Bit();
    QByteArray sendba = headba + senddata;
    std::string setdata(sendba.constData(), sendba.length());
    client->SetData(setdata);
    qDebug("send = %s",sendba.data());
    client->SetSendLen(sendba.length());

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
    head += "#";
    QString senddata = user + '#' + passwd + '\0';
    if (SendDataToServer(head, senddata.toLocal8Bit(), client) == -1)
    {
        return 'e';
    }

    Data data;
    if (data.ClientRecvData(client) == -1)
    {
        qDebug("ClientRecvData error");
        return 'e';
    }

    std::string buff = client->GetData();
    qDebug("recv success, buff = %s", buff.c_str());

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
