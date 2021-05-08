#ifndef COMMUNICATIONROOM_H
#define COMMUNICATIONROOM_H

#include <QWidget>

namespace Ui {
class CommunicationRoom;
}

class CommunicationRoom : public QWidget
{
    Q_OBJECT
    
public:
    explicit CommunicationRoom(QWidget *parent = 0);
    ~CommunicationRoom();
    
private:
    Ui::CommunicationRoom *ui;
};

#endif // COMMUNICATIONROOM_H
