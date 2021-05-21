#ifndef EMOJI_H
#define EMOJI_H

#include <QWidget>

namespace Ui {
class Emoji;
}

class Emoji : public QWidget
{
    Q_OBJECT
    
public:
    explicit Emoji(QWidget *parent = 0);
    ~Emoji();
    
private:
    Ui::Emoji *ui;
};

#endif // EMOJI_H
