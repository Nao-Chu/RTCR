#include "communicationroom.h"
#include "ui_communicationroom.h"

void* RecvServerData(void* p);
typedef struct PthreadData
{
    MySocket* c;
    Ui::CommunicationRoom* u;
}PthreadData;

CommunicationRoom::CommunicationRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommunicationRoom)
{
    ui->setupUi(this);
    ui->nameLabel->setText("Robot Team Communication Room");
}

CommunicationRoom::~CommunicationRoom()
{
    if (client_ != NULL)
        delete client_;
    delete ui;
}

void CommunicationRoom::on_sendButton_clicked()
{
    QString text_data = ui->sendEdit->toPlainText();
    ui->sendEdit->clear();

    QByteArray ba = text_data.toLatin1();
    client_->SetData(ba.data());
    client_->SetSendLen(text_data.length() + 1);

    qDebug("data = %s",ba.data());
    qDebug("dlen = %d",text_data.length());
    Data data;
    if (data.ClientSendData(client_) == -1)
        qDebug("ClientSendData error");

}

void CommunicationRoom::Communicate()
{
    pthread_t recv_data;
    PthreadData* pd = new PthreadData;
    pd->c = client_;
    pd->u = ui;

    if (pthread_create(&recv_data, NULL, RecvServerData, (void*)pd) == -1)
        qDebug("pthread_create RecvServerData error ");
}

void CommunicationRoom::SetClient(MySocket* client)
{
    client_ = client;
    Communicate();
}

void CommunicationRoom::on_recvBrowser_textChanged()
{
    ui->recvBrowser->moveCursor(QTextCursor::End);
}

void* RecvServerData(void* p)
{
    PthreadData pd = *(PthreadData*)p;
    Client* client = (Client*)pd.c;

    Data data;
    while(true)
    {
        if (data.ClientRecvData(client) == -1)
        {
            qDebug("clientRecvData error");
            break;
        }
        qDebug("Getdata = %p", (void*)client);
        char* buff = (char*)client->GetData();
        qDebug("Getdata = %s", buff);
        pd.u->recvBrowser->append(buff);
    }

    if (p != NULL)
        delete (PthreadData*)p;
    return (void*)0;
}
