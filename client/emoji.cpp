#include "emoji.h"
#include "ui_emoji.h"

Emoji::Emoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Emoji)
{
    ui->setupUi(this);
}

Emoji::~Emoji()
{
    delete ui;
}
