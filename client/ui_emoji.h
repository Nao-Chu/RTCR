/********************************************************************************
** Form generated from reading UI file 'emoji.ui'
**
** Created: Fri May 21 16:27:40 2021
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOJI_H
#define UI_EMOJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Emoji
{
public:
    QTableWidget *emojiWidget;

    void setupUi(QWidget *Emoji)
    {
        if (Emoji->objectName().isEmpty())
            Emoji->setObjectName(QStringLiteral("Emoji"));
        Emoji->resize(140, 140);
        Emoji->setMaximumSize(QSize(140, 140));
        Emoji->setBaseSize(QSize(140, 140));
        emojiWidget = new QTableWidget(Emoji);
        if (emojiWidget->columnCount() < 4)
            emojiWidget->setColumnCount(4);
        if (emojiWidget->rowCount() < 4)
            emojiWidget->setRowCount(4);
        emojiWidget->setObjectName(QStringLiteral("emojiWidget"));
        emojiWidget->setGeometry(QRect(0, 0, 141, 141));
        emojiWidget->setShowGrid(true);
        emojiWidget->setGridStyle(Qt::SolidLine);
        emojiWidget->setSortingEnabled(false);
        emojiWidget->setWordWrap(true);
        emojiWidget->setCornerButtonEnabled(true);
        emojiWidget->setRowCount(4);
        emojiWidget->setColumnCount(4);
        emojiWidget->horizontalHeader()->setVisible(false);
        emojiWidget->horizontalHeader()->setCascadingSectionResizes(false);
        emojiWidget->horizontalHeader()->setDefaultSectionSize(34);
        emojiWidget->horizontalHeader()->setHighlightSections(true);
        emojiWidget->horizontalHeader()->setMinimumSectionSize(25);
        emojiWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        emojiWidget->horizontalHeader()->setStretchLastSection(true);
        emojiWidget->verticalHeader()->setVisible(false);
        emojiWidget->verticalHeader()->setDefaultSectionSize(34);
        emojiWidget->verticalHeader()->setHighlightSections(true);
        emojiWidget->verticalHeader()->setMinimumSectionSize(25);

        retranslateUi(Emoji);

        QMetaObject::connectSlotsByName(Emoji);
    } // setupUi

    void retranslateUi(QWidget *Emoji)
    {
        Emoji->setWindowTitle(QApplication::translate("Emoji", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Emoji: public Ui_Emoji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOJI_H
