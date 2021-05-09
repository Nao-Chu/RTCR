#include "signup.h"
#include "ui_signup.h"

#include "mywidget.h"

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
}
