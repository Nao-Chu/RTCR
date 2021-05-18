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
    QString m_name_;

public:
    void Communicate();
    void SetClient(MySocket* client);
    void SetUserName(QString name)
    {
        m_name_ = name + ": \n    ";
    }
    QString GetUserName()
    {
        return m_name_;
    }

};

#endif // COMMUNICATIONROOM_H
