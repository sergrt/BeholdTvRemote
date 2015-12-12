#include "Settings.h"
const QString INI_NAME = "settings.ini";

Settings::Settings()
    : s(INI_NAME, QSettings::IniFormat) {
    
    s.beginGroup("Network");
    hostAddress  = s.value("hostname", "127.0.0.1").toString();
    clientPort   = s.value("clientPort", 12888).toUInt();
    serverPort   = s.value("serverPort", 12889).toUInt();
    beholdTvPath = s.value("beholdTvPath", "c:\\Progra~1\\BeholdTV\\BeholdTV.exe").toString();
    killOnExit   = s.value("killOnExit", false).toBool();
    s.endGroup();
}
Settings::~Settings() {
    /*
    s.beginGroup("Network");
    s.setValue("hostname", hostAddress);
    s.setValue("clientPort", clientPort);
    s.setValue("serverPort", serverPort);
    s.setValue("beholdTvPath", beholdTvPath);
    s.setValue("killOnExit", killOnExit);
    s.endGroup();
    */
}