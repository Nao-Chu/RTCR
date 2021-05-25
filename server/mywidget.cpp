#include "mywidget.h"
#include "ui_mywidget.h"
#include "recvmessstate.h"

#include <pthread.h>
#include <QDebug>

void* MessageState(void *s);
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
    pthread_t server_Mes;
    int accept_socket;
    while(true)
    {
        if ((accept_socket = server_tcp->Accept()) == -1)
            continue;

        if (pthread_create(&server_Mes, NULL, MessageState, (void*)&accept_socket) == -1)
            qDebug("pthread_create server_Mes error");
    }

}

void* MessageState(void* s)
{
    int socket = *(int*)s;
    int ret = 0;
    while(true)
    {
        char buff[1024];
        int recv_len = recv(socket, buff, 1024, 0);
        if (recv_len <= 0)
        {
            qDebug("recv fail");
            ret = MESSFNC::Users(&MESSFNC::DelUser, socket, NULL);
            break;
        }
        QString data = QString::fromLocal8Bit(buff);
        qDebug("recv len = %d ; data = %s",recv_len, qPrintable(data));
        qDebug("QByteArray len = %d ",QByteArray(buff, recv_len).length());

        qDebug() << QByteArray(buff, recv_len).toHex();
        QStringList list = data.split("#");

        if (list[0] == MESS::communicate){
            ret = MESSFNC::Communicate(list[1]);

        } else if (list[0] == MESS::signin){
            MySql mysql;
            ret = MESSFNC::SignInUp(&mysql, &MySql::SignInOp, list[1], list[2], socket);

        } else if (list[0] == MESS::signup){
            MySql mysql;
            ret = MESSFNC::SignInUp(&mysql, &MySql::SignUpOp, list[1], list[2], socket);

        } else if (list[0] == MESS::users){
            ret = MESSFNC::Users(&MESSFNC::AddUser, socket, list[1]);

        } else if (list[0] == MESS::emoji){
            ret = MESSFNC::Communicate(list[1]);

        } else if (list[0] == MESS::file){
            ret = MESSFNC::File(socket, QByteArray(buff, recv_len));

        }else {
            qDebug("server recv error");
            break;
        }

        if(ret != 0)
        {
            qDebug("ret != 0");
            break;
        }
    }

    return ret == 0 ? (void*)0 : (void*)-1;
}

void MyWidget::on_autoRun_clicked(bool checked)
{
    qDebug("%d",checked);
}
