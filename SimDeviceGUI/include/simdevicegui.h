/**
* \file SimDeviceGUI.h
* \brief Main UI class
* \author Jinwook Kim, Soumik Sarkar @ ITER Organization
*/


#ifndef SIMDEVICEGUI_H
#define SIMDEVICEGUI_H

#include <qtHeaders.hpp>
#include <cppHeaders.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class SimDeviceGUI; }
QT_END_NAMESPACE

class SimDeviceGUI : public QMainWindow
{
    Q_OBJECT

public:
    SimDeviceGUI(QWidget *parent = nullptr);
    ~SimDeviceGUI();

    // Startup Functions
    void StartUpUI();
    void PrepareGraphics();
    void AddDeviceStateValuesInList();
    void AddOperationModeValuesInList();
    void AddDeviceControllerInList();
    void AddRoomNamesInList();

    // Connector Function
    void Connections();

public slots:
    void DoThisWhenButtonClicked();

private:
    Ui::SimDeviceGUI *gui;
};
#endif // SIMDEVICEGUI_H
