#include "simdevicegui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimDeviceGUI w;
    w.show();
    return a.exec();
}
