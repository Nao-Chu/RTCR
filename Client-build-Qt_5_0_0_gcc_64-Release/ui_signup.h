/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created: Fri May 21 09:17:08 2021
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_SignUp
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *users;
    QLineEdit *lineUser;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwd;
    QLineEdit *linePasswd;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cPasswd;
    QLineEdit *lineCPasswd;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sure;
    QSpacerItem *horizontalSpacer;
    QPushButton *quit;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QStringLiteral("SignUp"));
        SignUp->resize(400, 300);
        widget = new QWidget(SignUp);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 20, 256, 248));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        users = new QLabel(widget_2);
        users->setObjectName(QStringLiteral("users"));

        horizontalLayout->addWidget(users);

        lineUser = new QLineEdit(widget_2);
        lineUser->setObjectName(QStringLiteral("lineUser"));

        horizontalLayout->addWidget(lineUser);


        gridLayout->addWidget(widget_2, 0, 0, 1, 2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        passwd = new QLabel(widget_3);
        passwd->setObjectName(QStringLiteral("passwd"));

        horizontalLayout_3->addWidget(passwd);

        linePasswd = new QLineEdit(widget_3);
        linePasswd->setObjectName(QStringLiteral("linePasswd"));

        horizontalLayout_3->addWidget(linePasswd);


        gridLayout->addWidget(widget_3, 1, 0, 1, 2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cPasswd = new QLabel(widget_4);
        cPasswd->setObjectName(QStringLiteral("cPasswd"));

        horizontalLayout_2->addWidget(cPasswd);

        lineCPasswd = new QLineEdit(widget_4);
        lineCPasswd->setObjectName(QStringLiteral("lineCPasswd"));

        horizontalLayout_2->addWidget(lineCPasswd);


        gridLayout->addWidget(widget_4, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sure = new QPushButton(widget_5);
        sure->setObjectName(QStringLiteral("sure"));

        horizontalLayout_4->addWidget(sure);

        horizontalSpacer = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        quit = new QPushButton(widget_5);
        quit->setObjectName(QStringLiteral("quit"));

        horizontalLayout_4->addWidget(quit);


        gridLayout->addWidget(widget_5, 4, 0, 1, 2);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Form", 0));
        users->setText(QApplication::translate("SignUp", "   \347\224\250\346\210\267\345\220\215  \357\274\232", 0));
        passwd->setText(QApplication::translate("SignUp", "     \345\257\206\347\240\201     \357\274\232", 0));
        cPasswd->setText(QApplication::translate("SignUp", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        sure->setText(QApplication::translate("SignUp", "\347\241\256\345\256\232", 0));
        quit->setText(QApplication::translate("SignUp", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
