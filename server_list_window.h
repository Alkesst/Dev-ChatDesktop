#ifndef SERVER_LIST_WINDOW_H
#define SERVER_LIST_WINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "client_info.h"
#include "chat_client.h"

namespace Ui {
class ServerListWindow;
}

class ServerListWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ServerListWindow(QWidget *parent = 0);
    ~ServerListWindow();

private slots:
    void loadFromDB(Ui::ServerListWindow* ui, DBManager db);

   // void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_AddServer_clicked();

    void on_JoinServer_clicked();

private:
    Ui::ServerListWindow *ui;
};

#endif // SERVER_LIST_WINDOW_H
