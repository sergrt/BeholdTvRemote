#include "Datagram.h"
#include <QProcess>
#include "CustomMsg.h"
#include "SettingsServer.h"
const char DELIMETER = '\1';
const char DELIMETER_PACKET = '\2';
const int REQUIRED_PARAMS_COUNT  = 3;

Datagram::Datagram(QByteArray& data) {
    const int firstPos = data.indexOf(DELIMETER_PACKET);
    
    if (firstPos != -1) {
        localData = data.left(firstPos);
        data.remove(0, firstPos + 1);
    }
}

Datagram::~Datagram() {
}

HWND Datagram::getWnd() {
    return FindWindow(L"TMain", L"BeholdTV");
}

void Datagram::process() {
    QByteArrayList sl = localData.split(DELIMETER);
    if (sl.size() != REQUIRED_PARAMS_COUNT) {
        emit putLog("Incorrect command");
    } else {
        emit putLog("Cmd = " + sl[0] + " / wParam = " + sl[1] + " / lParam = " + sl[2]);
        UINT cmd = sl[0].toUInt();

        if (cmd == WMCM_STARTAPP) {
            QProcess::startDetached(SettingsServer().beholdTvPath);
        } else {
            HWND wnd = getWnd();
            if (!wnd) {
                emit putLog("wnd not found");
            } else {
                UINT wParam = sl[1].toUInt();
                UINT lParam = sl[2].toUInt();
                PostMessage(wnd, cmd, wParam, lParam);
            }
        }
    }
    localData.clear();
}
