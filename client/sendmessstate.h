#ifndef SENDMESSSTATE_H
#define SENDMESSSTATE_H

#include <my_socket.h>
#include <QString>

namespace SENDMESSFNC
{
    extern MySocket* temp_client;

    int SendDataToServer(const QString& headdata, const QByteArray& senddata, const MySocket* c);

    char SignInUpRequest(const QString& type, const QString& user, const QString& passwd);

}

#endif // SENDMESSSTATE_H
