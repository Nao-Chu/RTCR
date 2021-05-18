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
    
private slots:
    void on_quit_clicked();

    void on_sure_clicked();
private:
    Ui::SignUp *ui;

public:
    MySocket* temp_client_;


};

#endif // SIGNUP_H
