#include "communicationroom.h"
#include "ui_communicationroom.h"

CommunicationRoom::CommunicationRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommunicationRoom)
{
    ui->setupUi(this);
}

CommunicationRoom::~CommunicationRoom()
{
    delete ui;
}
