#include "bectrlclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BeCtrlClient w;
    w.show();
    return a.exec();
}
