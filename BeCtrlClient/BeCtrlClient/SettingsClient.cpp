#include "SettingsClient.h"

SettingsClient::SettingsClient() {
    s.beginGroup("Network");
    hostAddress  = s.value("hostname", "127.0.0.1").toString();
    clientPort   = s.value("clientPort", 12888).toUInt();
    killOnExit   = s.value("killOnExit", false).toBool();
    s.endGroup();
}
