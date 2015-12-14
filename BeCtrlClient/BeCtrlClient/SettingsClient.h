#include "Settings.h"

class SettingsClient : public Settings {
public:
    SettingsClient();

    QString hostAddress;
    unsigned short clientPort;
    bool killOnExit;
};