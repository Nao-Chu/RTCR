#ifndef RECVMESSSTATE_H
#define RECVMESSSTATE_H

#include "mysql.h"

#include <QString>
#include <list>
#include <string>
#include <my_socket.h>

namespace MESSFNC
{
    int Communicate(const QString& senddata);

    int SignInUp(MySql* ptr, bool (MySql::*func)(const QString&, const QString&),
                 const QString& name, const QString& passwd, const int socket);

    int Users(const int socket, QString user);
}
#endif // RECVMESSSTATE_H
