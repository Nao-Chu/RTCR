#include "communicationroom.h"
#include "ui_communicationroom.h"

#include "sendmessstate.h"

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
    QString head = QString::fromUtf8(MESS::communicate);
    QString name = GetUserName();
    QString text_data = name + ":\n" + ui->sendEdit->toPlainText();
    ui->sendEdit->clear();

    SENDMESSFNC::SendDataToServer(head, text_data, client_);
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

    QString head = QString::fromUtf8(MESS::users);
    SENDMESSFNC::SendDataToServer(head, m_name_, client_);

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
        qDebug("test");
        if (data.ClientRecvData(client) == -1)
        {
            qDebug("clientRecvData error");
            break;
        }
        qDebug("test1");
        QString data = QString(QLatin1String((char*)client->GetData()) );
        qDebug("recv data = %s",qPrintable(data));
        QStringList list = data.split("#");

        if (list[0] == MESS::communicate){
            qDebug("Getdata = %s", qPrintable(list[1]));
            pd.u->recvBrowser->append(list[1]);

        } else if (list[0] == MESS::users){
            list.removeFirst();
            pd.u->listWidget->clear();
            pd.u->listWidget->insertItems(0, list);

        } else {
            qDebug("client recv error");
            break;
        }

    }

    if (p != NULL)
        delete (PthreadData*)p;
    return (void*)0;
}
