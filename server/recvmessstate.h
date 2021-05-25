#ifndef RECVMESSSTATE_H
#define RECVMESSSTATE_H

#include "mysql.h"

#include <QString>
#include <list>
#include <string>
#include <my_socket.h>

namespace MESSFNC
{
    typedef bool (MySql::*inupFunc)(const QString&, const QString&);
    int Communicate(const QString& senddata);

    int SignInUp(MySql* ptr, inupFunc f,const QString& name, const QString& passwd, const int socket);

    User* AddUser(const int socket, QString user);
    User* DelUser(const int socket, QString user);
    int Users(User* (*func) (int, QString), const int socket, QString user);

    int File(int socket, const QByteArray& senddata);
}
#endif // RECVMESSSTATE_H
