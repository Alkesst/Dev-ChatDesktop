#ifndef SERVER_LIST_WINDOW_H
#define SERVER_LIST_WINDOW_H

#include <QMainWindow>

namespace Ui {
class ServerListWindow;
}

class ServerListWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ServerListWindow(QWidget *parent = 0);
    ~ServerListWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ServerListWindow *ui;
};

#endif // SERVER_LIST_WINDOW_H
