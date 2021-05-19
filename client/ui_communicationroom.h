/********************************************************************************
** Form generated from reading UI file 'communicationroom.ui'
**
** Created: Wed May 19 15:47:25 2021
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATIONROOM_H
#define UI_COMMUNICATIONROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicationRoom
{
public:
    QTextBrowser *recvBrowser;
    QTextEdit *sendEdit;
    QListWidget *listWidget;
    QLabel *nameLabel;
    QFrame *line;
    QPushButton *sendButton;

    void setupUi(QWidget *CommunicationRoom)
    {
        if (CommunicationRoom->objectName().isEmpty())
            CommunicationRoom->setObjectName(QStringLiteral("CommunicationRoom"));
        CommunicationRoom->resize(900, 665);
        recvBrowser = new QTextBrowser(CommunicationRoom);
        recvBrowser->setObjectName(QStringLiteral("recvBrowser"));
        recvBrowser->setGeometry(QRect(0, 40, 741, 431));
        sendEdit = new QTextEdit(CommunicationRoom);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(0, 470, 741, 151));
        listWidget = new QListWidget(CommunicationRoom);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(740, 40, 161, 631));
        nameLabel = new QLabel(CommunicationRoom);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(350, 10, 271, 17));
        line = new QFrame(CommunicationRoom);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 30, 901, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        sendButton = new QPushButton(CommunicationRoom);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(640, 626, 91, 31));

        retranslateUi(CommunicationRoom);

        QMetaObject::connectSlotsByName(CommunicationRoom);
    } // setupUi

    void retranslateUi(QWidget *CommunicationRoom)
    {
        CommunicationRoom->setWindowTitle(QApplication::translate("CommunicationRoom", "Form", 0));
        nameLabel->setText(QApplication::translate("CommunicationRoom", "TextLabel", 0));
        sendButton->setText(QApplication::translate("CommunicationRoom", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class CommunicationRoom: public Ui_CommunicationRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONROOM_H
