#include <QListWidgetItem>
#include "chat_client.h"
#include "ui_chat_client.h"

ChatClient::ChatClient(Server server, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatClient) {
    // working correctly
    server.hostname = "pi.servidor.io";
    server.certName = "/Volumes/1315BDE/Programas/Dev-Chat Release/public.pem";
    server.port = 8081;
    server.username = "Alec";
    this->client = new ClientInfo(server.username, server.certName, server.hostname, server.port);
    ui->setupUi(this);
    connect(client, SIGNAL(receivedMessage(QString, QString)), SLOT(printMessage(QString, QString)));
}

void ChatClient::printMessage(QString username, QString message){
    if(!message.isEmpty()){
        QListWidgetItem* item = new QListWidgetItem();
        MessageChat* it = new MessageChat();
        QString formattedMessage = '[' + username + "]: " + message.remove('\n');
        qDebug() << formattedMessage;
        it->setData(formattedMessage);
        ui->messageHistory->addItem(item);
        ui->messageHistory->setItemWidget(item, it);
    }
}

ChatClient::~ChatClient(){
    delete ui;
}
