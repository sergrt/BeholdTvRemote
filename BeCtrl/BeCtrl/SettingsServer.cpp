#include "SettingsServer.h"

SettingsServer::SettingsServer() {
    s.beginGroup("Network");
    beholdTvPath = s.value("beholdTvPath", "c:\\Progra~1\\BeholdTV\\BeholdTV.exe").toString();
    s.endGroup();
}

SettingsServer::~SettingsServer() {
}