#include "message_chat.h"
#include "ui_message_chat.h"

MessageChat::MessageChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageChat)
{
    ui->setupUi(this);
}

MessageChat::~MessageChat()
{
    delete ui;
}

void MessageChat::setData(QString formattedMessage) {
    this->messageText = formattedMessage;
    ui->message->setText(formattedMessage);
}
