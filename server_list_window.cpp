#include "server_list_window.h"
#include "ui_server_list_window.h"

using namespace std;

ServerListWindow::ServerListWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ServerListWindow) {
    ui->setupUi(this);
}

ServerListWindow::~ServerListWindow() { delete ui; }

void ServerListWindow::on_pushButton_2_clicked() {
    // TODO OPEN NEW WINDOW ASKING FOR WHOLE DATA REQUIRED TO ADD A NEW SERVER.
}

