#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aida64readerforesp8266.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //设置托盘图标
    mySysTrayIcon=new QSystemTrayIcon(this);
    QIcon icon=QIcon(":/icon/avatar_hk560.jpg");
    mySysTrayIcon->setIcon(icon);
    mySysTrayIcon->setToolTip("ESP8266PCReader");
    mySysTrayIcon->show();


    ui->setupUi(this);
    ui->comChoBox->clear();

    //找到可用串口
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comChoBox->addItem(info.portName());
    }

    //读取配置文件
    QFileInfo info("./config.ini");
    //bool fileExit=info.exists();
    QSettings *configFile=new QSettings("./config.ini",QSettings::IniFormat);
    if(info.exists()==false){//如果不存在就新建
        qDebug()<<"建立设定config";
        configFile->setValue("COM","COM1");
        configFile->setValue("AUTOSETUP",false);
        configFile->setValue("AUTOMinimize",false);
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

        configFile->setValue("OutputSetting/IMAGEINFO",false);
        configFile->setValue("IMAGEINFO/LOOP_TIME",1);
        //在这里需要添加新项目

    }else
    {
        qDebug()<<"读取config";
        int index=ui->comChoBox->findText(configFile->value("COM").toString(),Qt::MatchExactly);

        if(index!=-1){
            aida64ReaderForESP8266::portName=configFile->value("COM").toString();
            ui->comChoBox->setCurrentIndex(index);
        }


        if(configFile->value("AUTOMinimize").toBool()==true){
            ui->minniChk->setCheckState(Qt::Checked);
            config::setupMinimize=true;
        }else{
            ui->minniChk->setCheckState(Qt::Unchecked);
            config::setupMinimize=false;
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

        //IMAGE INFO

        TmpState=config::imageInfo=configFile->value("OutputSetting/IMAGEINFO").toBool();
        if(TmpState==true)
            ui->imgShowChk->setCheckState(Qt::Checked);
        else
            ui->imgShowChk->setCheckState(Qt::Unchecked);

//        TmpState=config::imageInfo=configFile->value("IMAGEINFO/LOOP_TIME").toBool();
//        if(TmpState==true)
//            ui->imgCycChk->setCheckState(Qt::Checked);
//        else
//            ui->imgCycChk->setCheckState(Qt::Unchecked);

        config::imageInfoLoopTime=configFile->value("IMAGEINFO/LOOP_TIME").toInt();
        ui->imgLoopTime->setValue(configFile->value("IMAGEINFO/LOOP_TIME").toInt());

    }

    delete  configFile;
    connect(&THC,&ThreadController::singal_showMeg,this,&MainWindow::singalMsg);
    connect(&THC,&ThreadController::singal_outputState,this,&MainWindow::outputState);


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

    connect(ui->imgShowChk,&QCheckBox::stateChanged,this,&MainWindow::saveImageInfoSetting);
    //connect(ui->imgLoopTime,&QSpinBox::valueChanged,this,&MainWindow::saveImageInfoSetting);

    connect(mySysTrayIcon,&QSystemTrayIcon::activated,this,&MainWindow::on_activatedSysTrayIcon);


    if(config::setupPush==true){
        qDebug()<<"执行自动推送";
        config::startpush=true;
        THC.startOpenCom();
        THC.startOutput();
    }

    //this->setFixedSize(390,500);

}

MainWindow::~MainWindow()
{

    delete ui;
}

//打开串口
void MainWindow::on_openComBtn_clicked()
{
    //openComPort();
    qDebug("THC.startOpenCom()");
    aida64ReaderForESP8266::portName=ui->comChoBox->currentText();
    THC.startOpenCom();

}

//启动推送信息
void MainWindow::on_autoSetMsgBtn_clicked()
{
    ui->outputStateLB->setText("启动中");
    config::hardwareInfoDPtime=ui->hwCycleTime->value();
    config::startpush=true;

    if(ui->hwChkBox->checkState()==Qt::Checked){
        config::hardwareInfo=true;
    }else
        config::hardwareInfo=false;

//    if(ui->autoBox->checkState()==Qt::Checked){
//        config::setupPush=true;
//    }else
//        config::setupPush=false;

    qDebug()<<"THC.startOutput()";
    THC.startOutput();

}

//关闭串口
void MainWindow::on_closeBtn_clicked()
{
    //closeComPort();
    THC.startCloseCom();
    config::startpush=false;
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

//是否显示硬件信息
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

//打印可用串口
void MainWindow::on_serComBtn_clicked()
{
    ui->comChoBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comChoBox->addItem(info.portName());
    }
}
//返回信息
void MainWindow::singalMsg(QString str)
{
    QMessageBox::about(NULL,"信息",str);
}

//显示状态
void MainWindow::outputState(bool run)
{
    if(run==true){
        ui->outputStateLB->setText("运行中");
    }else{
        ui->outputStateLB->setText("未运行");
    }
}

void MainWindow::on_autoBox_clicked(bool checked)
{

}

void MainWindow::on_autoBox_stateChanged(int arg1)
{

}

//保存设置按钮
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


    if(ui->minniChk->checkState()==Qt::Checked){
        configFile->setValue("AUTOMinimize",true);
    }else{
        configFile->setValue("AUTOMinimize",false);
    }


     //IMAGE

    if(ui->imgShowChk->checkState()==Qt::Checked){
        config::imageInfo=true;
        configFile->setValue("OutputSetting/IMAGEINFO",true);
    }else{
        config::imageInfo=false;
        configFile->setValue("OutputSetting/IMAGEINFO",false);
    }

//    if(ui->imgCycChk->checkState()==Qt::Checked){
//        config::imageInfoLoop=true;
//        configFile->setValue("IMAGEINFO/LOOP_TIME",true);
//    }else{
//        config::imageInfoLoop=false;
//        configFile->setValue("IMAGEINFO/LOOP_TIME",false);
//    }

    configFile->setValue("IMAGEINFO/LOOP_TIME",ui->imgLoopTime->value());




    QMessageBox::about(NULL,"信息","已保存设置到程序根目录下的配置文件");
    delete  configFile;
}

//更改了硬件信息循环时间
void MainWindow::on_hwCycleTime_valueChanged(int arg1)
{
    qDebug("hwCycleTimechange");
    config::hardwareInfoDPtime=arg1;
}

void MainWindow::on_MainWindow_destroyed()
{

}

//保存硬件信息输出设置
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
    //需要添加加载图片参数的函数

    //delete [] configFile;
}

void MainWindow::saveImageInfoSetting()
{
    //image
    if(ui->imgShowChk->checkState()==Qt::Checked){
        config::imageInfo=true;
    }else
        config::imageInfo=false;

//    if(ui->imgCycChk->checkState()==Qt::Checked){
//        config::imageInfoLoop=true;
//    }else
//        config::imageInfoLoop=false;
    config::imageInfoLoopTime=ui->imgLoopTime->value();
    //需要添加加载图片参数的函数
}

//关于信息按钮
void MainWindow::on_aboutBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://esp8266pcreader.hk560.workers.dev/"));
}

//最小化
void MainWindow::on_hideBtn_clicked()
{
    this->hide();
//    mySysTrayIcon=new QSystemTrayIcon(this);
//    QIcon icon=QIcon(":/icon/avatar_hk560.jpg");
//    mySysTrayIcon->setIcon(icon);
//    mySysTrayIcon->setToolTip("ESP8266PCReader");
//    mySysTrayIcon->show();


}
//点击托盘图标恢复
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    if(reason==QSystemTrayIcon::Trigger){
        this->show();
    }
}

void MainWindow::on_minniChk_stateChanged(int arg1)
{
//    if(ui->minniChk->checkState()==Qt::Checked){

//    }
}

void MainWindow::on_hwChkBox_stateChanged(int arg1)
{

}
//停止输出信息
void MainWindow::on_stopBtn_clicked()
{
    if(config::startpush==false){
        ui->outputStateLB->setText("未运行");
    }else{
        ui->outputStateLB->setText("停止中");
        config::startpush=false;
    }



}

void MainWindow::on_picNameBtn_clicked()
{
    if(config::imageInfo==true){
         QMessageBox::warning(this,"警告","请先取消勾选“显示动画/图片”");
         return;
    }
    config::imageReady=false;
    if(imgInfoList!=nullptr){
        delete [] imgInfoList;
        imgInfoList=nullptr;
    }
    ui->imgNum->setText("未选择图片");
    ui->imageShow->setText("（无图片信息）");
    QStringList files = QFileDialog::getOpenFileNames(
                this,
                "选择一个或者多个图片",
                QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    if(files.isEmpty()){
        QMessageBox::warning(this,"提示","选择图片失败");
        return;
    }
    QImage imageToUse;
    for(int i=0;i<files.size();i++){
        qDebug()<<files.at(i).toUtf8();
        if(imageToUse.load(files.at(i))==false)
            QMessageBox::warning(this,"错误","读取图片失败，请检查选择的是否是图片");
        if(imageToUse.height()>64||imageToUse.width()>128){
            QMessageBox::warning(this,"错误","分辨率超过128x64");
            return;
        }
    }

    qDebug()<<"readFilesList";
    //    if(imgInfoList!=NULL)
    //        delete [] imgInfoList;


    imgInfoList=new imageInfo[files.size()];
    imgListSize=files.size();
    ui->imgNum->setText(QString("图片数:%1").arg(files.size()));
    for(int i=0;i<files.size();i++){
        imgInfoList[i].fileName=files.at(i);
        imgInfoList[i].XBM_DATA.resize(1024);
        CBinarization* binImg=new CBinarization(files.at(i));

        binImg->alterImage=false;

        QImage* grayImage = binImg->grayScaleImg();//获取灰度图
        int threshold=binImg->Otsu(grayImage);//计算阈值
        binImg->threshold=threshold;//阈值
        int bytePerLine = grayImage->bytesPerLine();

        imgInfoList[i].binData=new unsigned char[bytePerLine * grayImage->height()];
        //imgInfoList[i].XBM_DATA=new QByteArray[1024];//给bindata new新的空间
        //uchar* imgData=nullptr;
        //imgData= new unsigned char[bytePerLine * grayImage->height()];
        QImage* binaryImg = binImg->process(grayImage, imgInfoList[i].binData,imgInfoList[i].XBM_DATA);//二值化处理,图片存储到binaryImg,位图数组在binData

        QImage f1=binaryImg->scaled(ui->imageShow->size(),Qt::KeepAspectRatio);//显示出图片
        ui->imageShow->setPixmap(QPixmap::fromImage(f1));
        qDebug()<<"calXBM";
        //        int sum=0;
        //        for(int k=0;k<grayImage->height();++k){
        //            for(int j=0;j<grayImage->width();++j){
        //                //qDebug()<<uchar(imgInfoList[i].binData[ k * bytePerLine + j])<<" ";
        //                sum++;
        //            }
        //        }
        //        qDebug()<<"图片："<<i;
        //        for(int gg=0;gg<1024;gg++){
        //            qDebug()<<hex<<uchar(imgInfoList[i].XBM_DATA[gg]);
        //            //ui->textEdit->append()
        //        }
        this->repaint();//刷新组件
        //        qDebug()<<sum;





        //ui->textEdit->append()
        //}
        //        if(!serial->waitForBytesWritten())   //这一句很关键，决定是否能发送成功
        //        {
        //            qDebug()<<"serial write error";
        //        }
        //        QByteArray aaa;
        //        aaa[0]=0xAA;
        //        aaa[1]=0x22;
        //        serial->write(aaa);
        //serial->waitForBytesWritten();
        //serial->close();
        delete [] binImg;

        //delete  tt;
       // delete  binaryImg;
        //delete  grayImage;
        qDebug()<<"pic:"<<i<<"END";
        config::imageReady=true;
    }



    //grayImage.save("D:/grayimg.png");
    //QPixmap image(files.first());
    //QImage f1=grayImage;
    //QPixmap image;
    //image.fromImage(grayImage);
    //QPixmap outputImage=image.scaled(ui->label->size(),Qt::KeepAspectRatio);


    //qDebug()<<uchar(imgData[0]);
    qDebug()<<"end";
}

void MainWindow::on_imgShowChk_stateChanged(int arg1)
{
    if(arg1==Qt::Checked&&config::imageReady==false){
        ui->imgShowChk->setCheckState(Qt::Unchecked);
        QMessageBox::warning(this,"错误","未加载图片，请先选择图片文件后再勾选");
        MainWindow::saveImageInfoSetting();
        return;
    }
}
