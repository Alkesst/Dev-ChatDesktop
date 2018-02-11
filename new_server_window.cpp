#include "new_server_window.h"
#include "ui_new_server_window.h"

NewServerWindow::NewServerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewServerWindow)
{
    ui->setupUi(this);
}

NewServerWindow::~NewServerWindow()
{
    delete ui;
}
