#pragma once
#include "Settings.h"

class SettingsServer : public Settings {
public:
    SettingsServer();
    ~SettingsServer();
    QString beholdTvPath;
};