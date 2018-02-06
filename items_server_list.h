#ifndef ITEMS_SERVER_LIST_H
#define ITEMS_SERVER_LIST_H

#include <QWidget>
#include "dbmanager.h"

namespace Ui {
class itemsServerList;
}

class itemsServerList : public QWidget
{
    Q_OBJECT

public:
    explicit itemsServerList(QWidget *parent = 0);
    void setData(Server info_server);
    ~itemsServerList();

private:
    Ui::itemsServerList *ui;
};

#endif // ITEMS_SERVER_LIST_H
