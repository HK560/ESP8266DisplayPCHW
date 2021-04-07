#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSerialPort/QtSerialPort>
#include<QSerialPortInfo>
#include <QMainWindow>
#include <QThread>
#include "threadController.h"
#include<QDesktopServices>
//#include "config.h"

#include <QSettings>
#include<QFileInfo>
#include<QWidget>
#include<QtGui>
#include <QSystemTrayIcon>


//#include "ThreadDoWork.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openComBtn_clicked();

    void on_autoSetMsgBtn_clicked();

    void on_closeBtn_clicked();

    void on_setMsgBtn_clicked();

    void openComPort();
    void closeComPort();

    void on_hwChkBox_clicked(bool checked);

    void on_serComBtn_clicked();

    void singalMsg(QString str);

    void on_autoBox_clicked(bool checked);

    void on_autoBox_stateChanged(int arg1);



    void on_saveBtn_clicked();

    void on_hwCycleTime_valueChanged(int arg1);

    void on_MainWindow_destroyed();

    void saveHardwareInfoSetting();



    void on_aboutBtn_clicked();

    void on_hideBtn_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    ThreadController THC;
    QSystemTrayIcon* mySysTrayIcon;
};
#endif // MAINWINDOW_H
