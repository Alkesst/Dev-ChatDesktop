#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QList>

struct Server{
    int id;
    QString name;
    QString hostname;
    int port;
    QString certName;
    QString username;
};


class DBManager {
private:
    QSqlDatabase db;
public:
    DBManager(const QString& path);
    void addNewServer(Server& server);
    void deleteServer(const Server& server);
    Server getServerFromDB(Server& server);
    QList<Server> getAllServers();
    ~DBManager();
};

#endif // DBMANAGER_H
