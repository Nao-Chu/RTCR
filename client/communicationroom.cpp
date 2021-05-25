#include "communicationroom.h"
#include "ui_communicationroom.h"

#include "sendmessstate.h"

#include <QFileDialog>
#include <QDebug>

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
    QString head_data = QString::fromUtf8(MESS::communicate) + "#" + GetUserName() + ":\n";
    QByteArray send_data = ui->sendEdit->toPlainText().toLocal8Bit() + '\0';
    ui->sendEdit->clear();

    SENDMESSFNC::SendDataToServer(head_data, send_data, client_);
}

void CommunicationRoom::on_fileButton_clicked()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("file"), "", tr("(*.*)"));

    if (!filename.isNull())
    {
        QFile* sendfile = new QFile(filename);
        if (!sendfile->open(QFile::ReadOnly))
        {
            delete sendfile;
            qDebug("open file fail");
            return;
        }

        QByteArray outBlock;
        outBlock = sendfile->read(sendfile->size());
        QString outlen = QString::number(outBlock.length()) + "#";
        QString head_data = QString::fromUtf8(MESS::file) + "#" + GetUserName() + ":\n#" + outlen;
        SENDMESSFNC::SendDataToServer(head_data, outBlock, client_);

        delete sendfile;
    }
    qDebug("file = %s",qPrintable(filename));

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

    QString head_data = QString::fromUtf8(MESS::users) + "#";
    SENDMESSFNC::SendDataToServer(head_data, m_name_.toLocal8Bit() + '\0', client_);
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

        QString data = QString::fromStdString(client->GetData());
        qDebug("recv data = %s",qPrintable(data));
        QStringList list = data.split("#");

        if (list[0] == MESS::communicate){
            qDebug("Getdata = %s", qPrintable(list[1]));
            pd.u->recvBrowser->append(list[1]);

        } else if (list[0] == MESS::users){
            list.removeFirst();
            pd.u->listWidget->clear();
            pd.u->listWidget->insertItems(0, list);

        } else if (list[0] == MESS::file){
            qDebug("Getfile = %s", qPrintable(list[1]));
            pd.u->recvBrowser->append(list[1]);
            //QFile file(list[1]);
            //QTextStream in(&file);
            //pd.u->recvBrowser->setHtml(in.readAll());
            //pd.u->recvBrowser->setDocument();

        }else {
            qDebug("client recv error");
            break;
        }

    }

    if (p != NULL)
        delete (PthreadData*)p;
    return (void*)0;
}
