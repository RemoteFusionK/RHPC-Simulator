/**
* \file SimDeviceGUI.cpp
* \brief Functions in SimDeviceGUI
* \author Jinwook Kim, Soumik Sarkar @ ITER Organization
*/




#include <simdevicegui.h>
#include "./ui_simdevice.h"

SimDeviceGUI::SimDeviceGUI(QWidget *parent)
    : QMainWindow(parent)
    , gui(new Ui::SimDeviceGUI)
{
    gui->setupUi(this);
}


void SimDeviceGUI::StartUpUI()
{
    Connections(); // Estabilish all connections.
    
    PrepareGraphics(); 

    // Keep this function, as this will show the UI to the screen.
    // Can also use showMaximised() if you want to see full screen version.. Not recommended.
    show();
    this->setFixedSize(this->geometry().width(), this->geometry().height());

}

void SimDeviceGUI::PrepareGraphics()
{
    // Prepare some specific graphics for example add column header names for the device status table.
    // add list members to the several drop down lists we will add in the table.
    // These include graphic objects or data, which do not change throughout the execution.
    // You can prepare separate function like AddDeviceStateValuesInList() and call them here
    // AddDeviceStateValuesInList()
    // To be completed by Jinwook.
    // Delete these comments when done!



    // Delete this as well.
    std::cout << "Graphics Ready" << std::endl; // Can't have an empty function.....
}


void SimDeviceGUI::AddDeviceStateValuesInList()
{
    // When the GUI layout is ready,
    // If you have a drop down list (combo box)
    // called deviceState.
    // You can do the following: 

    // gui->deviceState->addItem("Off");
    // gui->deviceState->addItem("Ready");
    // etc....
    // To be filled by Jinwook
    // Delete these comments when done!



    // Delete this as well.
    std::cout << "AddItems to DeviceState Ready" << std::endl; // Can't have an empty function.....
}

SimDeviceGUI::~SimDeviceGUI()
{
    delete gui;
}


void SimDeviceGUI::Connections()
{
    // connect(gui->yesButton, SIGNAL(clicked()), this, SLOT(DoThisWhenButtonClicked()));
    connect(gui->newButton, SIGNAL(clicked()), this, SLOT(DoThisWhenButtonClicked()));
}



void SimDeviceGUI::DoThisWhenButtonClicked()
{
    
    /*
    if (gui->ckBoxSoumik->isChecked())
    {
        gui->ckBoxSoumik->setChecked(false);
    }
    else
    {
        gui->ckBoxSoumik->setChecked(true);
    }*/
}