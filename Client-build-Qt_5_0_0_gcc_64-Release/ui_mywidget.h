/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Fri May 21 09:17:08 2021
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QWidget *widget_Main;
    QGridLayout *gridLayout;
    QWidget *widget_User;
    QHBoxLayout *horizontalLayout;
    QLabel *users;
    QLineEdit *lineUsers;
    QWidget *widget_Passwd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwd;
    QLineEdit *linePasswd;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_Button;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *signUpButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *signInButton;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(442, 294);
        widget_Main = new QWidget(MyWidget);
        widget_Main->setObjectName(QStringLiteral("widget_Main"));
        widget_Main->setGeometry(QRect(70, 40, 277, 198));
        gridLayout = new QGridLayout(widget_Main);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_User = new QWidget(widget_Main);
        widget_User->setObjectName(QStringLiteral("widget_User"));
        horizontalLayout = new QHBoxLayout(widget_User);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        users = new QLabel(widget_User);
        users->setObjectName(QStringLiteral("users"));

        horizontalLayout->addWidget(users);

        lineUsers = new QLineEdit(widget_User);
        lineUsers->setObjectName(QStringLiteral("lineUsers"));

        horizontalLayout->addWidget(lineUsers);


        gridLayout->addWidget(widget_User, 0, 0, 1, 2);

        widget_Passwd = new QWidget(widget_Main);
        widget_Passwd->setObjectName(QStringLiteral("widget_Passwd"));
        horizontalLayout_2 = new QHBoxLayout(widget_Passwd);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passwd = new QLabel(widget_Passwd);
        passwd->setObjectName(QStringLiteral("passwd"));

        horizontalLayout_2->addWidget(passwd);

        linePasswd = new QLineEdit(widget_Passwd);
        linePasswd->setObjectName(QStringLiteral("linePasswd"));
        linePasswd->setCursor(QCursor(Qt::IBeamCursor));
        linePasswd->setEchoMode(QLineEdit::Password);
        linePasswd->setReadOnly(false);

        horizontalLayout_2->addWidget(linePasswd);


        gridLayout->addWidget(widget_Passwd, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        widget_Button = new QWidget(widget_Main);
        widget_Button->setObjectName(QStringLiteral("widget_Button"));
        horizontalLayout_3 = new QHBoxLayout(widget_Button);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        signUpButton = new QPushButton(widget_Button);
        signUpButton->setObjectName(QStringLiteral("signUpButton"));

        horizontalLayout_3->addWidget(signUpButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        signInButton = new QPushButton(widget_Button);
        signInButton->setObjectName(QStringLiteral("signInButton"));

        horizontalLayout_3->addWidget(signInButton);


        gridLayout->addWidget(widget_Button, 3, 0, 1, 2);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", 0));
        users->setText(QApplication::translate("MyWidget", "\347\224\250\346\210\267\345\220\215:", 0));
        passwd->setText(QApplication::translate("MyWidget", "  \345\257\206\347\240\201   :", 0));
        signUpButton->setText(QApplication::translate("MyWidget", "\346\263\250\345\206\214", 0));
        signInButton->setText(QApplication::translate("MyWidget", "\347\231\273\351\231\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
