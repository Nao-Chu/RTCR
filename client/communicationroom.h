#ifndef COMMUNICATIONROOM_H
#define COMMUNICATIONROOM_H

#include <QWidget>
#include <my_socket.h>

namespace Ui {
class CommunicationRoom;
}

class CommunicationRoom : public QWidget
{
    Q_OBJECT
    
public:
    explicit CommunicationRoom(QWidget *parent = 0);
    ~CommunicationRoom();
    
private slots:
    void on_sendButton_clicked();
    void on_recvBrowser_textChanged();

private:
    Ui::CommunicationRoom *ui;
    MySocket* client_;

public:
    void Communicate();
    void SetClient(MySocket* client);
};

#endif // COMMUNICATIONROOM_H
