#include "Settings.h"
const QString INI_NAME = "settings.ini";

Settings::Settings()
    : s(INI_NAME, QSettings::IniFormat) {

    s.beginGroup("Network");
    serverPort   = s.value("serverPort", 12889).toUInt();
    s.endGroup();
}

Settings::~Settings() {
}