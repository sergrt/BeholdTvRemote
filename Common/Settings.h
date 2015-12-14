#pragma once
#include <QString>
#include <QSettings>

class Settings {
public:
    Settings();
    virtual ~Settings();

    unsigned short serverPort;
protected:
    QSettings s;
};