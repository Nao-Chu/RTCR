#include "recvmessstate.h"

int MESSFNC::Communicate(const QString& senddata)
{
    QString head = MESS::communicate;
    QString send = head + "#" + senddata;
    QByteArray ba = send.toLatin1();

    Data data;
    int ret = data.ServerSendData(ba.data(), send.length());
    if (ret == -1)
    {
        qDebug("ServerRecvData error");
    }
    return ret;
}

int MESSFNC::SignInUp(MySql* ptr, bool (MySql::*func)(const QString&, const QString&),
             const QString& name, const QString& passwd, const int socket)
{
    bool ret = (ptr->*func)(name, passwd);

    if (!ret)
    {
        qDebug("(*func)(user, passwd) error");
        return -1;
    }

    const char* sendbuff = ret ? "#t" : "#f";
    qDebug("send = %s",sendbuff);
    send(socket, sendbuff, 2, 0);
    return 0;
}

int MESSFNC::Users(const int socket, QString user)
{
    User* temp = User::GetSingleton();
    temp->AddUserInf(socket, user.toStdString());
    std::list<std::string> names = temp->GetName();

    std::list<std::string>::const_iterator it = names.begin();
    QString senddata = QString::fromStdString(*(it++));
    for (; it != names.end(); ++it)
    {
        senddata += "#";
        senddata += QString::fromStdString(*it);
    }
    senddata += "\0";

    QString head = MESS::users;
    QString send = head + "#" + senddata;
    QByteArray ba = send.toLatin1();

    Data data;
    int ret = data.ServerSendData(ba.data(), send.length());
    if (ret == -1)
    {
        qDebug("ServerRecvData error");
    }
    return ret;
}
