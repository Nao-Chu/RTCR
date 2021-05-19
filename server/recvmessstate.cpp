#include "recvmessstate.h"

int MESSFNC::Communicate(const QString& senddata)
{
    QString head = MESS::communicate;
    QString send = head + "#" + senddata + '\0';
    QByteArray ba = send.toLatin1();
    qDebug("Communicate send data: %s",qPrintable(send));

    Data data;
    int ret = data.ServerSendData(ba.data(), send.length());
    if (ret == -1)
    {
        qDebug("ServerSendData error");
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
    }

    const char* sendbuff = ret ? "#t\0" : "#f\0";
    qDebug("send = %s",sendbuff);
    send(socket, sendbuff, 3, 0);
    return 0;
}

int MESSFNC::Users(const int socket, QString user)
{
    qDebug("recv user = %s, to string = %s",qPrintable(user), user.toStdString());
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
    qDebug("Users send : %s",qPrintable(send));

    Data data;
    int ret = data.ServerSendData(ba.data(), send.length());
    if (ret == -1)
    {
        qDebug("ServerSendData error");
    }
    return ret;
}
