#ifndef SIMDEVICEGUI_H
#define SIMDEVICEGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimDeviceGUI; }
QT_END_NAMESPACE

class SimDeviceGUI : public QMainWindow
{
    Q_OBJECT

public:
    SimDeviceGUI(QWidget *parent = nullptr);
    ~SimDeviceGUI();

private:
    Ui::SimDeviceGUI *ui;
};
#endif // SIMDEVICEGUI_H
