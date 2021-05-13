#include "signinup.h"
#include "ui_signup.h"

#include "mywidget.h"

#include <pthread.h>
#include <unistd.h>

#include <QMessageBox>


SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}


void SignUp::on_quit_clicked()
{
    qDebug("push button is quit");
    MyWidget *fater = new MyWidget();
    this->close();
    fater->show();
}


void SignUp::on_sure_clicked()
{
    qDebug("push button is sure");
    QString user,passwd,cpasswd;

    user = ui->lineUser->text();
    passwd = ui->linePasswd->text();
    cpasswd = ui->lineCPasswd->text();

    if (user.isEmpty())
    {
        QMessageBox::information(this, "提示！","用户名不能为空");
        return;
    }
    if (passwd.isEmpty())
    {
        QMessageBox::information(this,"提示！","密码不能为空");
        return;
    }
    if (cpasswd.isEmpty())
    {
        QMessageBox::information(this,"提示！","确认密码不能为空");
        return;
    }

    if (QString::localeAwareCompare(passwd,cpasswd) != 0)
    {
        QMessageBox::information(this, "错误！","两次密码不一致");
        return;
    }


    char buff = SignInUpRequest(QString("up"), user, passwd);
    if(buff == 't')
    {
        qDebug("sign up success");
        on_quit_clicked();
    }

    if(buff == 'f')
    {
        qDebug("sign up fail");
    }
}

char SignUp::SignInUpRequest(QString type, QString user, QString passwd)
{
    MySocket* client = new Client();
    client->SetAddr();

    MyConnect* client_tcp = new MyConnect(client);
    client_tcp->TcpConnect();
    QString send_data = type + "#" + user + "#" + passwd + '\0';
    QByteArray ba = send_data.toLatin1();

    client->SetData((char*)ba.data());
    qDebug("buff = %s",ba.data());

    pthread_t send;
    if (pthread_create(&send, NULL, Data::ClientSendData, (void*)client) == -1)
        qDebug("pthread_create send error");

    pthread_join(send,NULL);
    char buff[8];
    memset(buff, 0, 8);
    recv(client->GetSocket(), buff, 8, 0);
    if (QString::localeAwareCompare(type,"up") == 0)
        client->CloseSocket();
    else
        temp_client_ = client;

    delete client_tcp;

    if (buff[0] != '#' )
    {
        qDebug("recv error");
        return 'e';
    }

    return buff[1];

}
