#include "client_info.h"


ClientInfo::ClientInfo(QString username, QString cert, QString hostname, int port) {
    this->username = std::move(username);
    this->socket = new QSslSocket();
    if(socket->addCaCertificates(cert)){
        socket->setLocalCertificate(cert);
        socket->setPeerVerifyMode(QSslSocket::VerifyNone);
        socket->connectToHostEncrypted(hostname, static_cast<quint16>(port));
        connect(socket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(sslErrors(QList<QSslError>)));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
        connect(socket, SIGNAL(encrypted()), this, SLOT(encrypted()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(fromServer()));
    } else {
        emit certificateNotFound("Certificate not found: " + cert);
    }

}

void ClientInfo::sslErrors(QList<QSslError> errors){
    qDebug() << "Fuck! something went wrong";
    for(auto error: errors){
        qDebug() << error;
    }
}

void ClientInfo::encrypted(){
    emit receivedMessage("<<Console>>", "connection stablished with the server...");
}

QString ClientInfo::getUsername() { return username; }

void ClientInfo::sendMessage(QString message) {
    QString formattedMessage = '(' + username + ')' + ':' +message + '\n';
    socket->write(formattedMessage.toUtf8());
}

void ClientInfo::fromServer(){
    if(this->socket->canReadLine()){
        QString lineRead = this->socket->readLine();
        lineRead = lineRead.replace('\n', "");
        if(lineRead.startsWith("Send me")){
            QString user = username + '\n';
            socket->write(user.toUtf8());
        } else if(lineRead.startsWith("This username")){
            emit receivedMessage("<<Server>>", lineRead);
            socket->close();
        } else {
            auto stdLineRead = lineRead.toStdWString();
            auto pos = stdLineRead.find(':');
            if(pos != std::wstring::npos){
                auto username = stdLineRead.substr(1, pos-2);
                auto message = stdLineRead.substr(pos+1);
                QString usrnm = QString::fromStdWString(username);
                QString mssg = QString::fromStdWString(message);
                emit receivedMessage(usrnm, mssg);
            } else {
                emit receivedMessage("<<Server>>", lineRead);
            }
        }
    }
}

void ClientInfo::disconnect() {
    emit receivedMessage("<<Console>>", "disconnected from server...");
}
