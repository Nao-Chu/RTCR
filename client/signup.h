#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <my_socket.h>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT
    
public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();
    char SignInUpRequest(QString type, QString user, QString passwd);
    
private slots:
    void on_quit_clicked();

    void on_sure_clicked();

    void on_cPasswd_linkActivated(const QString &link);

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
