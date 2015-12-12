#include "Datagram.h"
#include <QProcess>
const char DELIMETER = '\1';

Datagram::Datagram(QByteArray& data) {
    const int firstPos = data.indexOf(DELIMETER);
    
    if (firstPos != -1) {
        localData = data.left(firstPos);
        data.remove(0, firstPos + 1);
    }
}

Datagram::~Datagram() {
}

void Datagram::process() {
    emit putLog(localData);
    QProcess::startDetached(localData);
    localData.clear();
}
