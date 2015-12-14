#ifndef BECTRL_H
#define BECTRL_H

#include <QtWidgets/QMainWindow>
#include <QUdpSocket>
#include "ui_bectrl.h"

class BeCtrl : public QMainWindow {
    Q_OBJECT

public:
    BeCtrl(QWidget *parent = 0);
    ~BeCtrl();

private:
    Ui::BeCtrlClass ui;
    QUdpSocket serverSocket;
    QByteArray pendingData;

public slots:
    void readPendingDatagrams();
    void putLog(const QString& s);
};

#endif // BECTRL_H
