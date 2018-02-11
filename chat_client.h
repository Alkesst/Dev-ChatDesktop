#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

#include <QWidget>
#include "client_info.h"
#include "dbmanager.h"
#include "message_chat.h"

namespace Ui {
class ChatClient;
}

class ChatClient : public QWidget {
    Q_OBJECT

public:
    explicit ChatClient(Server server, QWidget *parent = 0);
    ~ChatClient();

private:
    Ui::ChatClient *ui;
    ClientInfo* client;
private slots:
    void printMessage(QString username, QString message);
};

#endif // CHAT_CLIENT_H
