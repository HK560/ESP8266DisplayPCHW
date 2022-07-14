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
#include"binarization.h"
#include "imageinfo.h"

#include <QFileDialog>

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

    void outputState(bool run);

    bool execState(const bool &state);

    void on_autoBox_clicked(bool checked);

    void on_autoBox_stateChanged(int arg1);



    void on_saveBtn_clicked();

    void on_hwCycleTime_valueChanged(int arg1);

    void on_MainWindow_destroyed();

    void saveHardwareInfoSetting();

    void saveImageInfoSetting();



    void on_aboutBtn_clicked();

    void on_hideBtn_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void on_minniChk_stateChanged(int arg1);

    void on_hwChkBox_stateChanged(int arg1);

    void on_stopBtn_clicked();

    void on_picNameBtn_clicked();

    void on_imgShowChk_stateChanged(int arg1);

    void saveImageFilePathToConfig();//保护图片文件的路径到配置文件
    void loadImageFilePathFromConfig();//读取配置

    void on_imgLoopTime_valueChanged(int arg1);

    void on_fps_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    ThreadController THC;
    QSystemTrayIcon* mySysTrayIcon;
};
#endif // MAINWINDOW_H
