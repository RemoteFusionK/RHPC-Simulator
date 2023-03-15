#include "simdevicegui.h"
#include "./ui_simdevice.h"

SimDeviceGUI::SimDeviceGUI(QWidget *parent)
    : QMainWindow(parent)
    , gui(new Ui::SimDeviceGUI)
{
    gui->setupUi(this);
    Connections();
}

SimDeviceGUI::~SimDeviceGUI()
{
    delete gui;
}


void SimDeviceGUI::Connections()
{
    connect(gui->yesButton, SIGNAL(clicked()), this, SLOT(DoThisWhenButtonClicked()));
}



void SimDeviceGUI::DoThisWhenButtonClicked()
{
    if (gui->ckBoxSoumik->isChecked())
    {
        gui->ckBoxSoumik->setChecked(false);
    }
    else
    {
        gui->ckBoxSoumik->setChecked(true);
    }
}