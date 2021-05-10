#include "mywidget.h"
#include "ui_mywidget.h"
#include "mysql.h"

#include <my_socket.h>
#include <pthread.h>
#include <QDebug>

void* SignInUp(void *s);
void* Accept(void* t);
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    OpenServer();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::OpenServer()
{
    MySocket* server = new Server();
    server->SetAddr();

    int socket = server->GetSocket();
    int opt = SO_REUSEADDR;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    MyConnect* server_tcp = new MyConnect(server);
    if (!server_tcp->Listen())
    {
        ui->sConnect->setStyleSheet("color:red");
        ui->sConnect->setText("连接失败");
        return;
    }
    ui->sConnect->setStyleSheet("color:blue");
    ui->sConnect->setText("连接成功");
    pthread_t server_accept;
    if(pthread_create(&server_accept, NULL, Accept, (void*)server_tcp) == -1)
    {
        qDebug("pthread error");
    }
}

void* Accept(void* t)
{
    MyConnect* server_tcp = (MyConnect*)t;
    pthread_t server_id;
    pthread_t server_sign;
    int accept_socket;

    while(true)
    {
        if ((accept_socket = server_tcp->Accept()) == -1)
            continue;

        qDebug("accept accept_socket = %d",accept_socket);
        Data::all_socket[accept_socket] = accept_socket;
        if (pthread_create(&server_sign, NULL, SignInUp, (void*)&accept_socket) == -1)
            continue;
        pthread_join(server_sign, NULL);
        pthread_create(&server_id, NULL, Data::ServerRecvData, (void*)&accept_socket);
    }

}

void* SignInUp(void* s)
{

    MySql *mysql = new MySql();
    int socket = *(int*)s;
    qDebug("socket = %d ",socket);
    char buff[30];
    int recv_len;
    memset(buff, 0, 30);
    recv_len = recv(socket, buff, 30, 0);
    if (recv_len <= 0)
    {
        qDebug("recv fail");
        return 0;
    }

    QString data = QString(QLatin1String(buff));
    qDebug("recv data = %s",qPrintable(data));

    QStringList list = data.split("#");
    if (list.length() != 3)
        return 0;

    QString user = list[1];
    QString passwd = list[2];
    bool ret = false;

    if (list[0] == "up")
        ret = mysql->SignUpOp(user, passwd);
    else if (list[0] == "in")
        ret = mysql->SignInOp(user, passwd);
    else
        return 0;

    const char* sendbuff;
    if (ret)
        sendbuff = "#t";
    else
        sendbuff = "#f";
    qDebug("send = %s",sendbuff);
    send(socket, sendbuff, 8, 0);
    return 0;
}

void MyWidget::on_autoRun_clicked(bool checked)
{
    qDebug("%d",checked);
}