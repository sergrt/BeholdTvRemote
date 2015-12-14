#pragma once
#include <QObject>
#include <QByteArray>
#include <qt_windows.h>

class Datagram : public QObject {
    Q_OBJECT

public:
    Datagram(QByteArray& data);
    ~Datagram();
    void process();
private:
    QByteArray localData;
    HWND getWnd();
signals:
    void putLog(const QString& s);
};
