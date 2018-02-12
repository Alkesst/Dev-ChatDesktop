#include <QListWidgetItem>
#include "chat_client.h"
#include "ui_chat_client.h"

ChatClient::ChatClient(Server server, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatClient) {
    // working correctly
    server.hostname = "pi.servidor.io";
    server.certName = "/Users/alec/Downloads/public.pem";
    server.port = 8081;
    server.username = "Alec";
    this->client = new ClientInfo(server.username, server.certName, server.hostname, server.port);
    ui->setupUi(this);
    connect(client, SIGNAL(receivedMessage(QString, QString)), SLOT(printMessage(QString, QString)));
}

void ChatClient::printMessage(QString username, QString message){
    if(!message.isEmpty()){
        formatMessageReceived(username, message);
        /*QListWidgetItem* item = new QListWidgetItem();
        MessageChat* it = new MessageChat();
        QString formattedMessage = '[' + username + "]: " + message.remove('\n');
        qDebug() << formattedMessage;
        it->setData(formattedMessage);
        ui->messageHistory->addItem(item);
        ui->messageHistory->setItemWidget(item, it);*/
    }
}

ChatClient::~ChatClient(){
    delete ui;
}

void ChatClient::on_message_textChanged(const QString &message){
    ui->pushButton->setAutoFillBackground(true);
    if(!message.isEmpty()){
        //ui->pushButton->setDisabled(false);
        ui->pushButton->setFlat(false);
    } else {
        //ui->pushButton->setDisabled(true);
        ui->pushButton->setFlat(true);
    }
}

void ChatClient::on_message_returnPressed(){
    QString message = ui->message->text();
    if(!message.isEmpty()){
        formatMessageSent(client->getUsername(), message);
        this->ui->message->clear();
        this->client->sendMessage(message);
    }
}

QString ChatClient::formatMessageReceived(QString username, QString message){
    QListWidgetItem* item = new QListWidgetItem();
    MessageChat* it = new MessageChat();
    QString formattedMessage = '[' + username + "]: " + message.remove('\n');
    it->setData(formattedMessage);
    ui->messageHistory->addItem(item);
    ui->messageHistory->setItemWidget(item, it);
    return formattedMessage;
}

void ChatClient::formatMessageSent(QString username, QString message){
    QListWidgetItem* item = new QListWidgetItem();
    MessageChat* it = new MessageChat();
    QString formattedMessage = '(' + username + "): " + message.remove('\n');
    it->setData(formattedMessage);
    ui->messageHistory->addItem(item);
    ui->messageHistory->setItemWidget(item, it);
}

void ChatClient::on_pushButton_clicked(){
    this->on_message_returnPressed();
    this->ui->message->clear();
}
