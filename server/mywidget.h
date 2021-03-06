#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void OpenServer();

    
private slots:
    void on_autoRun_clicked(bool checked);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
