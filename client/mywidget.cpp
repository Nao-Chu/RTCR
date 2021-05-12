#include "mywidget.h"
#include "ui_mywidget.h"

#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_signUpButton_clicked()
{
    qDebug("push button sign up");

    this->close();
    SignUp *signup = new SignUp();
    signup->show();
    signup->setWindowTitle("注册");
}

void MyWidget::on_signInButton_clicked()
{
    qDebug("push button sign in");
    QString user,passwd;

    user = ui->lineUsers->text();
    passwd = ui->linePasswd->text();


    MySocket* client = new Client();
    client->SetAddr();

    MyConnect* client_tcp = new MyConnect(client);
    client_tcp->TcpConnect();

    QString send_data = "in#" + user + "#" + passwd + '\0';
    QByteArray ba = send_data.toLatin1();
    client->SetData((char*)ba.data());
    qDebug("buff = %s",ba.data());


    pthread_t send;
    if (pthread_create(&send, NULL, Data::ClientSendData, (void*)client) == -1)
        qDebug("pthread_create send error");

    pthread_join(send,NULL);
    char buff[12];
    memset(buff, 0, 12);
    recv(client->GetSocket(), buff, 12, 0);

    if (buff[0] != '#' )
    {
        qDebug("recv error");
        return;
    }

    if(buff[1] == 't')
    {
        this->close();
        CommunicationRoom *croom = new CommunicationRoom();
        croom->show();
        croom->setWindowTitle("Robot Team Communication Room");
    }


    if (buff[1] == 'f')
    {
        QMessageBox::information(this,"错误!","账号或则秘密错误");
    }

}
