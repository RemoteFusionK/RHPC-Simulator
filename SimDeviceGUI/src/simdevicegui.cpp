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

    AddDeviceControllerInList();
    AddDeviceStateValuesInList();
    AddOperationModeValuesInList();
    AddRoomNamesInList();
    ValidateRoomPositions();
    SetInitCheckBoxes();

    // Edit Soumik: Moved your commands from this function to their custom functions...
    
    // Delete this as well.
    std::cout << "Graphics Ready" << std::endl; // Can't have an empty function.....
}

void SimDeviceGUI::AddDeviceControllerInList()
{
    // Add 32 device controllers: 151 ~ 182
    int deviceController = 32;
    for (int i = 151; i < 151 + deviceController; i++)
    {
        gui->deviceController->addItem(std::to_string(i).c_str());
    }
}

void SimDeviceGUI::AddRoomNamesInList()
{
    // TODO Soumik: will move this to a txt file instead of a long list.
    // Related to database
    // keep as it is for now

    QString string = "GALLERY 1, SP1, SP2, SP3, SP4, SP5, SP6, SP7, SP8, SP9, SP10, SP11, SP12, HOT-CELL 1, HOT-CELL 2, HOT-CELL 3, NB CELL 1, NB CELL 2, PORT CELL MOCK-UP, GALLERY 2, In-VV 1, In-VV2, PC 12, PC 15, PC 16, PC 17, LPC 01, LPC 02, LPC 03, DC 01, RESCUE";
    QStringList rooms = string.split(",");

    gui->roomList->addItems(rooms);
    
    // Delete this as well.
    std::cout << "AddItems to Room List Ready" << std::endl; // Can't have an empty function.....
}

void SimDeviceGUI::AddDeviceStateValuesInList()
{
    gui->deviceState->addItem("SAFE");
    gui->deviceState->addItem("READY");
    gui->deviceState->addItem("ENABLED");
    gui->deviceState->addItem("OFF");

    // Delete this as well.
    std::cout << "AddItems to DeviceState Ready" << std::endl; // Can't have an empty function.....
}

void SimDeviceGUI::AddOperationModeValuesInList()
{
    gui->operationMode->addItem("IDLE");
    gui->operationMode->addItem("NOMINAL");
    gui->operationMode->addItem("RESCUE");
    gui->operationMode->addItem("RECOVERY");
    gui->operationMode->addItem("MAINTENANCE");
    gui->operationMode->addItem("HANDS ON");
    gui->operationMode->addItem("COMMISSIONING");
    gui->operationMode->addItem("OFF");

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




void SimDeviceGUI::ValidateRoomPositions()
{
    gui->xPos->setValidator(new QIntValidator(0, 9999, this));
    gui->yPos->setValidator(new QIntValidator(0, 9999, this));
    gui->zPos->setValidator(new QIntValidator(0, 9999, this));
}


void SimDeviceGUI::SetInitCheckBoxes()
{
    gui->guardInactive->setChecked(true);
    gui->guardActive->setChecked(false);
}




void SimDeviceGUI::DoThisWhenButtonClicked()
{

    gui->deviceTable->setDisabled(true);
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