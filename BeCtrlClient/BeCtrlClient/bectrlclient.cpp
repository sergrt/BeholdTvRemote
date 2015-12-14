#include "bectrlclient.h"
#include <QByteArray>
#include <QMessageBox>
#include <QCloseEvent>
#include <qt_windows.h>
#include "BhMsg.h"
#include "CustomMsg.h"
const QString DELIMITER = "\1";
const QString DELIMITER_PACKET = "\2";

BeCtrlClient::BeCtrlClient(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    clientSocket.bind(QHostAddress::AnyIPv4, settings.clientPort);
    connect(ui.channelNo, &QPushButton::clicked, this, &BeCtrlClient::onChannelSet);
    connect(ui.channelUp, &QPushButton::clicked, this, &BeCtrlClient::onChannelUp);
    connect(ui.channelDown, &QPushButton::clicked, this, &BeCtrlClient::onChannelDown);
    connect(ui.startRec, &QPushButton::clicked, this, &BeCtrlClient::onStartRec);
    connect(ui.stop, &QPushButton::clicked, this, &BeCtrlClient::onStop);
    connect(ui.startApp, &QPushButton::clicked, this, &BeCtrlClient::onStartApp);

    //trayIcon.show();
}

BeCtrlClient::~BeCtrlClient() {
    if (settings.killOnExit)
        onStop();
    //trayIcon.hide();
}

void BeCtrlClient::sendCmd(const QByteArray& cmd) {
    QHostAddress serverAddress;
    serverAddress.setAddress(settings.hostAddress);
    clientSocket.writeDatagram(cmd, serverAddress, settings.serverPort);
}

void BeCtrlClient::onChannelSet() {
    QByteArray cmd;
    cmd += QString("%1").arg(WM_BHCMD).toLocal8Bit();
    cmd += DELIMITER;
    cmd += QString("%1").arg(WMBH_CHNLN).toLocal8Bit();
    cmd += DELIMITER;
    cmd += ui.channelNoEdit->text();
    cmd += DELIMITER_PACKET;
    
    sendCmd(cmd);
}

void BeCtrlClient::onChannelUp() {
    int channel = ui.channelNoEdit->text().toUInt();
    ++channel;
    ui.channelNoEdit->setText(QString("%1").arg(channel));

    onChannelSet();
}

void BeCtrlClient::onChannelDown() {
    int channel = ui.channelNoEdit->text().toUInt();
    --channel;
    if (channel > 0) {
        ui.channelNoEdit->setText(QString("%1").arg(channel));
        onChannelSet();
    }
}

void BeCtrlClient::onStartRec() {
    QByteArray cmd;
    cmd += QString("%1").arg(WM_BHCMD).toLocal8Bit();
    cmd += DELIMITER;
    cmd += QString("%1").arg(WMBH_RECVSTART).toLocal8Bit();
    cmd += DELIMITER;
    cmd += "0";
    cmd += DELIMITER_PACKET;
    
    sendCmd(cmd);
}

void BeCtrlClient::onStop() {
    QByteArray cmd;
    cmd += QString("%1").arg(WM_CLOSE).toLocal8Bit();
    cmd += DELIMITER;
    cmd += QString("%1").arg(0).toLocal8Bit();
    cmd += DELIMITER;
    cmd += "0";
    cmd += DELIMITER_PACKET;
    
    sendCmd(cmd);
}

void BeCtrlClient::closeEvent(QCloseEvent *event) {
    //hide();
    //event->ignore();
}

void BeCtrlClient::onStartApp() {
    QByteArray cmd;
    cmd += QString("%1").arg(WMCM_STARTAPP).toLocal8Bit();
    cmd += DELIMITER;
    cmd += QString("%1").arg(0).toLocal8Bit();
    cmd += DELIMITER;
    cmd += "0";
    cmd += DELIMITER_PACKET;
    
    sendCmd(cmd);
}