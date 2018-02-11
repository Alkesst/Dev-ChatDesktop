#ifndef MESSAGE_CHAT_H
#define MESSAGE_CHAT_H

#include <QWidget>
#include <QString>

namespace Ui {
class messageChat;
}

class MessageChat : public QWidget
{
    Q_OBJECT

public:
    explicit MessageChat(QWidget *parent = 0);
    ~MessageChat();
    void setData(QString formattedMessage);
    QString getData() { return this->messageText; }

private:
    Ui::messageChat *ui;
    QString messageText;
};

#endif // MESSAGE_CHAT_H
