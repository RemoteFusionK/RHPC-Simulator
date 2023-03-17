#include <simdevicegui.h>

#include <qtHeaders.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimDeviceGUI w;
    w.StartUpUI(); // This line is changed from w.show() to w.StartUpUI() to preprocess GUI as we want.
    return a.exec();
}
