#include "recvmessstate.h"

int MESSFNC::Communicate(const QString& senddata)
{
    QString head = MESS::communicate;
    QString send = head + "#" + senddata + '\0';
    QByteArray ba = send.toLocal8Bit();
    qDebug("Communicate send data: %s",qPrintable(send));

    Data data;
    int ret = data.ServerSendData(ba.data(), ba.length());
    if (ret == -1)
    {
        qDebug("ServerSendData error");
    }
    return ret;
}

int MESSFNC::SignInUp(MySql* ptr, inupFunc f,
             const QString& name, const QString& passwd, const int socket)
{
    bool ret = (ptr->*f)(name, passwd);

    if (!ret)
    {
        qDebug("(*func)(user, passwd) error");
    }

    const char* sendbuff = ret ? "#t\0" : "#f\0";
    qDebug("send = %s",sendbuff);
    send(socket, sendbuff, 3, 0);
    return 0;
}

User* MESSFNC::AddUser(const int socket, QString user)
{
    User* temp = User::GetSingleton();
    qDebug("recv user = %s",qPrintable());

    temp->AddUserInf(socket, user.toStdString());
    return temp;
}

User* MESSFNC::DelUser(const int socket, QString user)
{
    User* temp = User::GetSingleton();
    user = QString::fromStdString(temp->FindName(socket));
    qDebug("quit user is %s",qPrintable(user));

    temp->DelUserInf(socket);
    return temp;
}

int MESSFNC::Users(User* (*func) (int s, QString u),const int socket, QString user)
{
    User* temp = (*func)(socket, user);
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
    QByteArray ba = send.toLocal8Bit();
    qDebug("Users send : %s",qPrintable(send));

    Data data;
    int ret = data.ServerSendData(ba.data(), ba.length());
    if (ret == -1)
    {
        qDebug("ServerSendData error");
    }
    return ret;
}
