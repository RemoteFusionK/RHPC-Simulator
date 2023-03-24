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
    void ValidateRoomPositions();
    void AddDeviceStateValuesInList();
    void AddOperationModeValuesInList();
    void AddDeviceControllerInList();
    void AddRoomNamesInList();
    void SetInitCheckBoxes();
    void ShowIcon();

    // Connector Function
    void Connections();

public slots:
    void RunButtonClicked();
    void StopButtonClicked();
    void NewButtonClicked();
    void SaveButtonClicked();
    void LoadButtonClicked();

private:
    Ui::SimDeviceGUI *gui;
};



#endif // SIMDEVICEGUI_H
