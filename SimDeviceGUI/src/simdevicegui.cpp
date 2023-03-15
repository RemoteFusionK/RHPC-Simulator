#include "simdevicegui.h"
#include "./ui_simdevice.h"

SimDeviceGUI::SimDeviceGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimDeviceGUI)
{
    ui->setupUi(this);
}

SimDeviceGUI::~SimDeviceGUI()
{
    delete ui;
}

