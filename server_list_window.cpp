#include "server_list_window.h"
#include "items_server_list.h"
#include "ui_server_list_window.h"
#include <QListWidgetItem>
#include <QDebug>

using namespace std;

ServerListWindow::ServerListWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ServerListWindow) {
    ui->setupUi(this);
    QString path = "/Users/alec/database.db";
    DBManager mngr = DBManager(path);
    loadFromDB(ui, mngr);
}

ServerListWindow::~ServerListWindow() { delete ui; }



void ServerListWindow::loadFromDB(Ui::ServerListWindow* ui, DBManager db){
    /*
     * adapted from https://stackoverflow.com/questions/26199374/add-qwidget-to-qlistwidget
     */
    QList<Server> serverList;
    serverList = db.getAllServers();
    serverList.append({ 1, "Paco", "paco.local", 1234, "", "Cktehg1" });
    serverList.append({ 2, "Manolo", "manolo.local", 1122, "", "Alekss" });
    serverList.append({ 8, "jesús", "galera.local", 1234, "", "Lopez" });
    serverList.append({ 3, "Mestro", "ofpuppt.local", 12, "", "masterrr" });
    QString temp = 0;
    for(int i = 0; i < serverList.length(); i++) {
        QListWidgetItem* item = new QListWidgetItem();
        itemsServerList* it = new itemsServerList();
        it->setData(serverList[i]);
        ui->serverList->addItem(item);
        ui->serverList->setItemWidget(item, it);
    }
}


void ServerListWindow::on_AddServer_clicked(){
    //TODO NEW VIEW FOR ADDING A SERVER

}

void ServerListWindow::on_JoinServer_clicked(){
    QString path = "/Volumes/1315BDE/Programas/Dev-Chat Release/Cert/public.pem";
    QString username = "Alkesstt";
    QString hostname = "pi.servidor.io";
    int port = 8081;
    ClientInfo* a = new ClientInfo(username, path, hostname, port);
}
