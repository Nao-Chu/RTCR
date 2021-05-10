/********************************************************************************
** Form generated from reading UI file 'communicationroom.ui'
**
** Created: Mon May 10 10:55:08 2021
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicationRoom
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_4;
    QFrame *frame_3;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *CommunicationRoom)
    {
        if (CommunicationRoom->objectName().isEmpty())
            CommunicationRoom->setObjectName(QStringLiteral("CommunicationRoom"));
        CommunicationRoom->resize(907, 666);
        gridLayout = new QGridLayout(CommunicationRoom);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(CommunicationRoom);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 10, 611, 421));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(660, 20, 191, 611));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 440, 601, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(frame_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 551, 101));
        widget = new QWidget(frame_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 140, 581, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(689, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        frame_2->raise();
        frame_4->raise();
        widget->raise();
        frame_3->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(CommunicationRoom);

        QMetaObject::connectSlotsByName(CommunicationRoom);
    } // setupUi

    void retranslateUi(QWidget *CommunicationRoom)
    {
        CommunicationRoom->setWindowTitle(QApplication::translate("CommunicationRoom", "Form", 0));
        pushButton->setText(QApplication::translate("CommunicationRoom", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class CommunicationRoom: public Ui_CommunicationRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONROOM_H
