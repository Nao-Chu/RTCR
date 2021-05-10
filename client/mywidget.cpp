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

    if (0)
    {
        QMessageBox::information(this,"错误!","账号或则秘密错误");
        return;
    }

    this->close();
    CommunicationRoom *croom = new CommunicationRoom();
    croom->show();
    croom->setWindowTitle("Robot Team Communication Room");
}