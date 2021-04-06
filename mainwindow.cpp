#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aida64readerforesp8266.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comChoBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comChoBox->addItem(info.portName());
    }

    QFileInfo info("./config.ini");
    //bool fileExit=info.exists();
    QSettings *configFile=new QSettings("./config.ini",QSettings::IniFormat);
    if(info.exists()==false){
        qDebug()<<"建立设定config";
        configFile->setValue("COM","COM1");
        configFile->setValue("AUTOSETUP",false);
        configFile->setValue("OutputSetting/HARDWAREINFO",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_TIME",2);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUuti",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUvolt",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUvolt",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUclk",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUpkg",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUtmp",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUMCuti",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUtmp",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUuti",false);
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_MENuti",false);


    }else
    {
        qDebug()<<"读取config";
        int index=ui->comChoBox->findText(configFile->value("COM").toString(),Qt::MatchExactly);

        if(index!=-1){
            aida64ReaderForESP8266::portName=configFile->value("COM").toString();
            ui->comChoBox->setCurrentIndex(index);
        }


        if(configFile->value("AUTOSETUP").toBool()==true){
            ui->autoBox->setCheckState(Qt::Checked);
            config::setupPush=true;
        }else{
            ui->autoBox->setCheckState(Qt::Unchecked);
            config::setupPush=false;
        }

        if(configFile->value("OutputSetting/HARDWAREINFO").toBool()==true){
            ui->hwChkBox->setCheckState(Qt::Checked);
            config::hardwareInfo=true;
        }else{
            ui->hwChkBox->setCheckState(Qt::Unchecked);
            config::hardwareInfo=false;
        }

        config::hardwareInfoDPtime=configFile->value("HARDWAREINFO/HARDWAREINFO_TIME").toInt();
        ui->hwCycleTime->setValue(configFile->value("HARDWAREINFO/HARDWAREINFO_TIME").toInt());

        bool TmpState;//临时使用储存状态值

        TmpState=config::hardwareInfo_CPUuti=configFile->value("HARDWAREINFO/HARDWAREINFO_CPUuti").toBool();
        if(TmpState==true)
            ui->CPUutiChk->setCheckState(Qt::Checked);
        else
            ui->CPUutiChk->setCheckState(Qt::Unchecked);

        TmpState=config::hardwareInfo_CPUvolt=configFile->value("HARDWAREINFO/HARDWAREINFO_CPUvolt").toBool();
        if(TmpState==true)
            ui->CPUvoltChk->setCheckState(Qt::Checked);
        else
            ui->CPUvoltChk->setCheckState(Qt::Unchecked);

        TmpState=config::hardwareInfo_GPUvolt=configFile->value("HARDWAREINFO/HARDWAREINFO_GPUvolt").toBool();
        if(TmpState==true)
            ui->GPUvoltChk->setCheckState(Qt::Checked);
        else
            ui->GPUvoltChk->setCheckState(Qt::Unchecked);


        TmpState=config::hardwareInfo_CPUclk=configFile->value("HARDWAREINFO/HARDWAREINFO_CPUclk").toBool();
        if(TmpState==true)
            ui->CPUclkChk->setCheckState(Qt::Checked);
        else
            ui->CPUclkChk->setCheckState(Qt::Unchecked);


        TmpState=config::hardwareInfo_CPUpkg=configFile->value("HARDWAREINFO/HARDWAREINFO_CPUpkg").toBool();
        if(TmpState==true)
            ui->CPUpkgChk->setCheckState(Qt::Checked);
        else
            ui->CPUpkgChk->setCheckState(Qt::Unchecked);


        TmpState=config::hardwareInfo_CPUtmp=configFile->value("HARDWAREINFO/HARDWAREINFO_CPUtmp").toBool();
        if(TmpState==true)
            ui->CPUtmpChk->setCheckState(Qt::Checked);
        else
            ui->CPUtmpChk->setCheckState(Qt::Unchecked);


        TmpState=config::hardwareInfo_GPUMCuti=configFile->value("HARDWAREINFO/HARDWAREINFO_GPUMCuti").toBool();
        if(TmpState==true)
            ui->GPUMCutiChk->setCheckState(Qt::Checked);
        else
            ui->GPUMCutiChk->setCheckState(Qt::Unchecked);

        TmpState=config::hardwareInfo_GPUtmp=configFile->value("HARDWAREINFO/HARDWAREINFO_GPUtmp").toBool();
        if(TmpState==true)
            ui->GPUtmpChk->setCheckState(Qt::Checked);
        else
            ui->GPUtmpChk->setCheckState(Qt::Unchecked);


        TmpState=config::hardwareInfo_GPUuti=configFile->value("HARDWAREINFO/HARDWAREINFO_GPUuti").toBool();
        if(TmpState==true)
            ui->GPUutiChk->setCheckState(Qt::Checked);
        else
            ui->GPUutiChk->setCheckState(Qt::Unchecked);

        TmpState=config::hardwareInfo_MENuti=configFile->value("HARDWAREINFO/HARDWAREINFO_MENuti").toBool();
        if(TmpState==true)
            ui->MENutiChk->setCheckState(Qt::Checked);
        else
            ui->MENutiChk->setCheckState(Qt::Unchecked);



    }

    delete  configFile;
    connect(&THC,&ThreadController::singal_showMeg,this,&MainWindow::singalMsg);


    connect(ui->CPUclkChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->CPUutiChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->CPUvoltChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->CPUpkgChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->CPUtmpChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->GPUvoltChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->GPUutiChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->GPUtmpChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->GPUMCutiChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);
    connect(ui->MENutiChk,&QCheckBox::stateChanged,this,&MainWindow::saveHardwareInfoSetting);



    if(config::setupPush==true){
        qDebug()<<"执行自动推送";
        THC.startOpenCom();
        THC.startOutput();
    }
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_openComBtn_clicked()
{
    //openComPort();
    qDebug("THC.startOpenCom()");
    aida64ReaderForESP8266::portName=ui->comChoBox->currentText();
    THC.startOpenCom();
}

void MainWindow::on_autoSetMsgBtn_clicked()
{
    config::hardwareInfoDPtime=ui->hwCycleTime->value();
    if(ui->hwChkBox->checkState()==Qt::Checked){
        config::hardwareInfo=true;
    }else
        config::hardwareInfo=false;

    if(ui->autoBox->checkState()==Qt::Checked){
        config::setupPush=true;
    }else
        config::setupPush=false;

    qDebug()<<"THC.startOutput()";
    THC.startOutput();

}

void MainWindow::on_closeBtn_clicked()
{
    //closeComPort();
    THC.startCloseCom();
    QMessageBox::about(NULL,"提示","已经关闭串口");
}

void MainWindow::on_setMsgBtn_clicked()
{
    //serial->write(ui->msgTextEdit->toPlainText().toUtf8());
}

void MainWindow::openComPort()
{

}

void MainWindow::closeComPort()
{
    //serial->close();
    //THC.startCloseCom();
}

void MainWindow::on_hwChkBox_clicked(bool checked)
{
    //    if(checked==true)
    //    {aida64ReaderForESP8266::ifStopSignal=false;
    //    THC.startOutput();
    //    }
    //    else
    //        aida64ReaderForESP8266::ifStopSignal=true;

    if(ui->hwChkBox->checkState()==Qt::Checked){
        config::hardwareInfo=true;
    }else
        config::hardwareInfo=false;


}

void MainWindow::on_serComBtn_clicked()
{
    ui->comChoBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comChoBox->addItem(info.portName());
    }
}

void MainWindow::singalMsg(QString str)
{
    QMessageBox::about(NULL,"信息",str);
}

void MainWindow::on_autoBox_clicked(bool checked)
{

}

void MainWindow::on_autoBox_stateChanged(int arg1)
{

}


void MainWindow::on_saveBtn_clicked()
{
    QFileInfo info("./config.ini");
    //bool fileExit=info.exists();
    QSettings *configFile=new QSettings("./config.ini",QSettings::IniFormat);

    configFile->setValue("COM",ui->comChoBox->currentText());

    if(ui->autoBox->checkState()==Qt::Checked)
        configFile->setValue("AUTOSETUP",true);
    else
        configFile->setValue("AUTOSETUP",false);

    if(ui->hwChkBox->checkState()==Qt::Checked)
        configFile->setValue("OutputSetting/HARDWAREINFO",true);
    else
        configFile->setValue("OutputSetting/HARDWAREINFO",false);


    configFile->setValue("HARDWAREINFO/HARDWAREINFO_TIME",ui->hwCycleTime->value());

    if(ui->CPUutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUuti=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUuti",true);
    }else{
        config::hardwareInfo_CPUuti=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUuti",false);
    }

    if(ui->CPUvoltChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUvolt=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUvolt",true);
    }else{
        config::hardwareInfo_CPUvolt=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUvolt",false);
    }

    if(ui->MENutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_MENuti=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_MENuti",true);
    }else{
        config::hardwareInfo_MENuti=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_MENuti",false);
    }

    if(ui->CPUclkChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUclk=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUclk",true);
    }else{
        config::hardwareInfo_CPUclk=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUclk",false);
    }

    if(ui->CPUpkgChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUpkg=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUpkg",true);
    }else{
        config::hardwareInfo_CPUpkg=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUpkg",false);
    }

    if(ui->CPUtmpChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUtmp=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUtmp",true);
    }else{
        config::hardwareInfo_CPUtmp=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_CPUtmp",false);
    }

    if(ui->GPUtmpChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUtmp=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUtmp",true);
    }else{
        config::hardwareInfo_GPUtmp=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUtmp",false);
    }

    if(ui->GPUutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUuti=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUuti",true);
    }else{
        config::hardwareInfo_GPUuti=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUuti",false);
    }

    if(ui->GPUvoltChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUvolt=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUvolt",true);
    }else{
        config::hardwareInfo_GPUvolt=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUvolt",false);
    }

    if(ui->GPUMCutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUMCuti=true;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUMCuti",true);
    }else{
        config::hardwareInfo_GPUMCuti=false;
        configFile->setValue("HARDWAREINFO/HARDWAREINFO_GPUMCuti",false);
    }

    delete  configFile;
}

void MainWindow::on_hwCycleTime_valueChanged(int arg1)
{
    qDebug("hwCycleTimechange");
    config::hardwareInfoDPtime=arg1;
}

void MainWindow::on_MainWindow_destroyed()
{

}

void MainWindow::saveHardwareInfoSetting()
{
    //QSettings *configFile=new QSettings("./config.ini",QSettings::IniFormat)

    if(ui->CPUclkChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUclk=true;
    }else
        config::hardwareInfo_CPUclk=false;

    if(ui->CPUpkgChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUpkg=true;
    }else
        config::hardwareInfo_CPUpkg=false;

    if(ui->CPUtmpChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUtmp=true;
    }else
        config::hardwareInfo_CPUtmp=false;

    if(ui->CPUutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUuti=true;
    }else
        config::hardwareInfo_CPUuti=false;

    if(ui->CPUvoltChk->checkState()==Qt::Checked){
        config::hardwareInfo_CPUvolt=true;
    }else
        config::hardwareInfo_CPUvolt=false;

    if(ui->GPUtmpChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUtmp=true;
    }else
        config::hardwareInfo_GPUtmp=false;

    if(ui->GPUutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUuti=true;
    }else
        config::hardwareInfo_GPUuti=false;

    if(ui->GPUvoltChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUvolt=true;
    }else
        config::hardwareInfo_GPUvolt=false;

    if(ui->GPUMCutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_GPUMCuti=true;
    }else
        config::hardwareInfo_GPUMCuti=false;

    if(ui->MENutiChk->checkState()==Qt::Checked){
        config::hardwareInfo_MENuti=true;
    }else
        config::hardwareInfo_MENuti=false;

    config::hardwareInfoReload();

    //delete [] configFile;
}


void MainWindow::on_aboutBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://blog.hk560.top/2021/03/26/Aida64ForEsp8266/"));
}
