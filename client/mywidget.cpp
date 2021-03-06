#include "mywidget.h"
#include "ui_mywidget.h"
#include "sendmessstate.h"

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

    char buff = SENDMESSFNC::SignInUpRequest(QString("in"), user, passwd);

    if (user == "123"&& passwd == "123")
        buff = 't';
    else if (user == "234" && passwd == "234")
        buff = 't';

    if(buff == 't')
    {
        qDebug("sign in success");
        this->close();
        CommunicationRoom *croom = new CommunicationRoom();
        croom->SetUserName(user);
        croom->SetClient(SENDMESSFNC::temp_client);
        croom->setWindowTitle("RTCR");
        croom->show();

        return;
    }

    if (buff == 'f')
    {
        QMessageBox::information(this,"错误!","账号或则秘密错误");
    }

}
