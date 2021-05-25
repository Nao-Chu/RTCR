#include "recvmessstate.h"

#include <QFile>
#include <QDebug>

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

int MESSFNC::File(int socket, const QByteArray& senddata)
{
    QList<QByteArray> list = senddata.split('#');

    QString username = QString(list[1]);
    int len = QString(list[2]).toInt();

    qDebug("file len = %d", len);
    QByteArray filedata = senddata;

    int filelen = list[0].length() + list[1].length() + list[2].length() + 3;
    filedata.remove(0, filelen);
    while(true)
    {
        if(filedata.length() >= len)
        {
            qDebug("recv file end");
            break;
        }
        char buff[1024];
        memset(buff, 0, 1024);
        int recvlen = recv(socket, buff, 1024, 0);
        if(recvlen <= 0)
        {
            qDebug("recv end \n");
            break;
        }
        filedata += QByteArray(buff, recvlen);
        qDebug("filedata len = %d", filedata.length());
    }

    QFile* recvfile = new QFile("./files/6.png");
    if (!recvfile->open(QFile::WriteOnly))
    {
        qDebug("write error\n");
        return -1;
    }
    recvfile->write(filedata);
    recvfile->close();
    qDebug() << filedata.toHex();

    /*
    QString head = MESS::file;
    head += "#" + QString(username);
    QByteArray ba = head.toLocal8Bit() + filedata;
    qDebug("file send data: %s",qPrintable(ba));

    Data data;
    int ret = data.ServerSendData(ba.data(), ba.length());
    if (ret == -1)
    {
        qDebug("ServerSendData error");
    }
*/
    return 0;
}

