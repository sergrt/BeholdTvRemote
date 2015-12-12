#include "bectrlclient.h"
#include <QByteArray>
#include <QMessageBox>
#include <QCloseEvent>
const QString DELIMITER = "\1";

BeCtrlClient::BeCtrlClient(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    clientSocket.bind(QHostAddress::AnyIPv4, settings.clientPort);
    connect(ui.channelNo, &QPushButton::clicked, this, &BeCtrlClient::onChannelSet);
    connect(ui.channelUp, &QPushButton::clicked, this, &BeCtrlClient::onChannelUp);
    connect(ui.channelDown, &QPushButton::clicked, this, &BeCtrlClient::onChannelDown);
    connect(ui.startRec, &QPushButton::clicked, this, &BeCtrlClient::onStartRec);
    connect(ui.stop, &QPushButton::clicked, this, &BeCtrlClient::onStop);

    //trayIcon.show();
}

BeCtrlClient::~BeCtrlClient() {
    if (settings.killOnExit)
        onStop();
    //trayIcon.hide();
}

void BeCtrlClient::sendCmd(const QString& cmd) {
    QHostAddress serverAddress;
    serverAddress.setAddress(settings.hostAddress);
    clientSocket.writeDatagram((cmd + DELIMITER).toLocal8Bit(), serverAddress, settings.serverPort);
}

void BeCtrlClient::onChannelSet() {
    sendCmd(settings.beholdTvPath + " -ch:" + ui.channelNoEdit->text());
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
    sendCmd(settings.beholdTvPath + " -r:video");
}

void BeCtrlClient::onStop() {
    sendCmd("taskkill /F /IM BeholdTV.exe");
}

void BeCtrlClient::closeEvent(QCloseEvent *event) {
    //hide();
    //event->ignore();
}