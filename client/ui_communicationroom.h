/********************************************************************************
** Form generated from reading UI file 'communicationroom.ui'
**
** Created: Fri May 21 17:25:20 2021
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicationRoom
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_main;
    QWidget *widget_top;
    QGridLayout *gridLayout_6;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_left;
    QTextBrowser *recvBrowser;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *emojiButton;
    QPushButton *fileButton;
    QPushButton *dalayButton_2;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *sendEdit;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendButton;
    QListWidget *listWidget;

    void setupUi(QWidget *CommunicationRoom)
    {
        if (CommunicationRoom->objectName().isEmpty())
            CommunicationRoom->setObjectName(QStringLiteral("CommunicationRoom"));
        CommunicationRoom->resize(900, 670);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommunicationRoom->sizePolicy().hasHeightForWidth());
        CommunicationRoom->setSizePolicy(sizePolicy);
        CommunicationRoom->setMinimumSize(QSize(900, 670));
        CommunicationRoom->setBaseSize(QSize(900, 670));
        gridLayout_2 = new QGridLayout(CommunicationRoom);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_main = new QGridLayout();
        gridLayout_main->setSpacing(0);
        gridLayout_main->setObjectName(QStringLiteral("gridLayout_main"));
        widget_top = new QWidget(CommunicationRoom);
        widget_top->setObjectName(QStringLiteral("widget_top"));
        gridLayout_6 = new QGridLayout(widget_top);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        nameLabel = new QLabel(widget_top);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_6->addWidget(nameLabel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(389, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        line = new QFrame(widget_top);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(389, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_main->addWidget(widget_top, 0, 0, 1, 2);

        verticalLayout_left = new QVBoxLayout();
        verticalLayout_left->setSpacing(0);
        verticalLayout_left->setObjectName(QStringLiteral("verticalLayout_left"));
        verticalLayout_left->setContentsMargins(0, -1, -1, -1);
        recvBrowser = new QTextBrowser(CommunicationRoom);
        recvBrowser->setObjectName(QStringLiteral("recvBrowser"));
        recvBrowser->setOpenExternalLinks(true);

        verticalLayout_left->addWidget(recvBrowser);

        frame_2 = new QFrame(CommunicationRoom);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(7, 0, 0, 0);
        emojiButton = new QPushButton(frame_2);
        emojiButton->setObjectName(QStringLiteral("emojiButton"));
        emojiButton->setMinimumSize(QSize(0, 22));
        emojiButton->setMaximumSize(QSize(30, 16777215));
        emojiButton->setBaseSize(QSize(0, 0));
        emojiButton->setMouseTracking(false);
        emojiButton->setStyleSheet(QStringLiteral("border-image: url(:/emoji/emoji.png);"));
        emojiButton->setIconSize(QSize(16, 16));
        emojiButton->setAutoRepeatDelay(300);
        emojiButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(emojiButton);

        fileButton = new QPushButton(frame_2);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileButton->sizePolicy().hasHeightForWidth());
        fileButton->setSizePolicy(sizePolicy1);
        fileButton->setMinimumSize(QSize(0, 22));
        fileButton->setMaximumSize(QSize(30, 16777215));
        fileButton->setStyleSheet(QStringLiteral("border-image: url(:/emoji/file.jpeg);"));

        horizontalLayout_2->addWidget(fileButton);

        dalayButton_2 = new QPushButton(frame_2);
        dalayButton_2->setObjectName(QStringLiteral("dalayButton_2"));
        dalayButton_2->setMinimumSize(QSize(0, 22));
        dalayButton_2->setMaximumSize(QSize(30, 16777215));
        dalayButton_2->setStyleSheet(QStringLiteral("border-image: url(:/emoji/dalay.jpeg);"));

        horizontalLayout_2->addWidget(dalayButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_left->addWidget(frame_2);

        sendEdit = new QTextEdit(CommunicationRoom);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setEnabled(true);
        sendEdit->setTabChangesFocus(false);
        sendEdit->setUndoRedoEnabled(true);

        verticalLayout_left->addWidget(sendEdit);

        frame = new QFrame(CommunicationRoom);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(551, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        sendButton = new QPushButton(frame);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout_left->addWidget(frame);

        verticalLayout_left->setStretch(0, 9);
        verticalLayout_left->setStretch(2, 4);

        gridLayout_main->addLayout(verticalLayout_left, 1, 0, 1, 1);

        listWidget = new QListWidget(CommunicationRoom);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_main->addWidget(listWidget, 1, 1, 1, 1);

        gridLayout_main->setColumnStretch(0, 5);
        gridLayout_main->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout_main, 0, 0, 1, 1);


        retranslateUi(CommunicationRoom);

        QMetaObject::connectSlotsByName(CommunicationRoom);
    } // setupUi

    void retranslateUi(QWidget *CommunicationRoom)
    {
        CommunicationRoom->setWindowTitle(QApplication::translate("CommunicationRoom", "Form", 0));
        nameLabel->setText(QApplication::translate("CommunicationRoom", "TextLabel", 0));
        emojiButton->setText(QString());
        fileButton->setText(QString());
        dalayButton_2->setText(QString());
        sendButton->setText(QApplication::translate("CommunicationRoom", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class CommunicationRoom: public Ui_CommunicationRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONROOM_H
