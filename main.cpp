#include "server_list_window.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ServerListWindow w;
    w.show();

    return a.exec();
}
