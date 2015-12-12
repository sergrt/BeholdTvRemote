#include "bectrl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BeCtrl w;
    w.show();
    return a.exec();
}
