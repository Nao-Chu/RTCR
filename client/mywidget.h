#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include <signinup.h>
#include <communicationroom.h>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    
private slots:
    void on_signUpButton_clicked();

    void on_signInButton_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
