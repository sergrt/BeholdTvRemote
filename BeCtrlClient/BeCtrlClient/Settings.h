#include <QString>
#include <QSettings>

class Settings {
public:
    Settings();
    ~Settings();

    QString hostAddress;
    unsigned short clientPort;
    unsigned short serverPort;
    QString beholdTvPath;
    bool killOnExit;
private:
    QSettings s;
};