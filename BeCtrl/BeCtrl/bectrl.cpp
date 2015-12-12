#include "bectrl.h"
#include "Datagram.h"
#include <QDateTime>
const unsigned short SERVER_PORT = 12889;

BeCtrl::BeCtrl(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    serverSocket.bind(QHostAddress::AnyIPv4, SERVER_PORT);
    connect(&serverSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

BeCtrl::~BeCtrl() {
    
}

void BeCtrl::readPendingDatagrams() {
    while (serverSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(serverSocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        serverSocket.readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
        pendingData += datagram;
        
        Datagram d(pendingData);
        connect(&d, &Datagram::putLog, this, &BeCtrl::putLog);
        d.process();
    }
}
void BeCtrl::putLog(const QString& s) {
    const QString dateTime = QDateTime::currentDateTime().toString("yyyyMMddThhmmss");
    ui.logView->insertPlainText("[" + dateTime + "] " + s + "\n");
}