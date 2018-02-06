#include "items_server_list.h"
#include "ui_items_server_list.h"
#include "dbmanager.h"

itemsServerList::itemsServerList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemsServerList){
    ui->setupUi(this);
}

void itemsServerList::setData(Server info_server) {
    ui->server->setText(info_server.name);
    ui->username->setText(info_server.username);
    ui->port->setText(QString::number(info_server.port));
}

itemsServerList::~itemsServerList(){
    delete ui;
}
