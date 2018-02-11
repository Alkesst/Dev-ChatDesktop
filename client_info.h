#ifndef CLIENT_INFO_H
#define CLIENT_INFO_H

#include <QSslSocket>
#include <iostream>
#include <QString>


class ClientInfo: public QObject {
    Q_OBJECT

    QSslSocket* socket;
    QString username;

public:
    ClientInfo(QString username, QString cert, QString hostname, int port);
    QString getUsername();
    void sendMessage(QString message);
signals:
    void receivedMessage(QString username, QString message);
    void certificateNotFound(QString message);
private slots:
    void sslErrors(QList<QSslError> errors);
    void disconnect();
    void encrypted();
    void fromServer();
};

#endif // CLIENT_INFO_H
