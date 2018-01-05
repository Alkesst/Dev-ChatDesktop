#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <sstream>

DBManager::DBManager(const QString& path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    bool success = false;
    if (db.open()){
        qDebug() << "Database: connection ok";
        QSqlQuery query;
        success = query.exec(
           "CREATE TABLE IF NOT EXISTS SERVER("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "name VARCHAR(50) NOT NULL,"
           "hostname VARCHAR(250) NOT NULL,"
           "port INTEGER NOT NULL,"
           "certName VARCHAR(250) NOT NULL,"
           "username VARCHAR(25) NOT NULL"
           ")"
         );
        if(!success){
            qDebug() << "ERROR: Something went wrong creating the database: "
                   << query.lastError();
        } else {
            qDebug() << "Database created successfully";
        }
    } else{
        qDebug() << "Error: failed to connect with database";
    }
}
void DBManager::addNewServer(Server& server){
    QSqlQuery query;
    query.prepare("INSERT INTO SERVER (name, hostname, port, certName, username)"
                  "VALUES (:name, :host, :port, :cert, :user)");
    query.bindValue(":name", server.name);
    query.bindValue(":host", server.hostname);
    query.bindValue(":port", server.port);
    query.bindValue(":user", server.username);
    query.bindValue(":cert", server.certName);
    if(!query.exec()){
        qDebug() << "ERROR: Something went wrong when adding the server into the database: "
               << query.lastError();
    } else {
        int rowId = query.lastInsertId().toInt();
        query.prepare("SELECT id FROM SERVER WHERE rowid = :rowid");
        query.bindValue(":rowid", rowId);
        query.exec();
        query.next();
        server.id = query.value(query.record().indexOf("id")).toInt();
    }
}

void DBManager::deleteServer(const Server& server){
    QSqlQuery query;
    bool success = false;
    // Adapted from https://stackoverflow.com/questions/10219225/c-create-string-of-text-and-variables
    std::ostringstream oss;
    oss << "DELETE FROM SERVER WHERE id = " << server.id;
    // Adapted from https://stackoverflow.com/questions/4338067/convert-stdstring-to-qstring
    QString os = QString::fromStdString(oss.str());
    success = query.exec(os);
    if(!success){
        qDebug() << "ERROR: Something went wrong when deleting the server from the database:"
               << query.lastError();
    }
}

Server DBManager::getServerFromDB(Server& server){
    QSqlQuery query;
    query.prepare("SELECT * from server where id = :server_id");
    query.bindValue(":server_id", server.id);
    if(!query.exec()){
        qDebug() << "ERROR: Something went wrong when obtaining the server from the database:"
               << query.lastError();
    } else{
        if(query.next()){
            server.name = query.value(query.record().indexOf("name")).toString();
            server.hostname = query.value(query.record().indexOf("hostname")).toString();
            server.port = query.value(query.record().indexOf("port")).toInt();
            server.certName = query.value(query.record().indexOf("certName")).toString();
            server.username = query.value(query.record().indexOf("username")).toString();
        } else {
            server.id = -1;
        }
    }
    return server;
}

QList<Server> DBManager::getAllServers(){
    QList<Server> serverList;
    QSqlQuery query;
    query.prepare("SELECT * from server");
    if(!query.exec()){
        qDebug() << "ERROR while getting all the data from the data base: "
                 << query.lastError();
    } else {
        while(query.next()){
            Server server;
            server.name = query.value(query.record().indexOf("name")).toString();
            server.hostname = query.value(query.record().indexOf("hostname")).toString();
            server.port = query.value(query.record().indexOf("port")).toInt();
            server.certName = query.value(query.record().indexOf("certName")).toString();
            server.username = query.value(query.record().indexOf("username")).toString();
            serverList.append(server);
        }
    }
    return serverList;
}

DBManager::~DBManager(){
    db.close();
}
