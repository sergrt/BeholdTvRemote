#ifndef BECTRLCLIENT_H
#define BECTRLCLIENT_H

#include <QtWidgets/QMainWindow>
#include "ui_bectrlclient.h"
#include <QUdpSocket>
//#include <QSystemTrayIcon>
#include "Settings.h"

class BeCtrlClient : public QMainWindow {
    Q_OBJECT

public:
    BeCtrlClient(QWidget *parent = 0);
    ~BeCtrlClient();

private:
    Ui::BeCtrlClientClass ui;
    QUdpSocket clientSocket;
    void sendCmd(const QString& cmd);

    //QSystemTrayIcon trayIcon;
    void closeEvent(QCloseEvent *event);

    Settings settings;
public slots:
    void onChannelSet();
    void onChannelUp();
    void onChannelDown();
    void onStartRec();
    void onStop();
};

#endif // BECTRLCLIENT_H
