#include "communicationroom.h"
#include "ui_communicationroom.h"

CommunicationRoom::CommunicationRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommunicationRoom)
{
    ui->setupUi(this);
    ui->nameLabel->setText("Robot Team Communication Room");
    Communicate();
}

CommunicationRoom::~CommunicationRoom()
{
    if (client_ != NULL)
        delete client_;
    delete ui;
}

void CommunicationRoom::on_sendButton_clicked()
{
    QString data = ui->sendEdit->toPlainText();
    qDebug("data = %s",qPrintable(data));
    ui->recvBrowser->append(data);
    ui->sendEdit->clear();
    qDebug("socket %d",client_->GetSocket());
}

void CommunicationRoom::Communicate()
{

}

void CommunicationRoom::SetClient(MySocket* client)
{
    client_ = client;
}

void CommunicationRoom::on_recvBrowser_textChanged()
{
    ui->recvBrowser->moveCursor(QTextCursor::End);
}
