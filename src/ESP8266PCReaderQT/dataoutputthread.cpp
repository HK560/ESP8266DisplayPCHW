#include "dataoutputthread.h"


dataOutputThread::dataOutputThread(QObject *parent):QObject(parent)
{
    // serial=new QSerialPort;
}

void dataOutputThread::openCom()
{
    qDebug()<<"dataOutputThread::openCom()";
    if(serial != nullptr){
        serial->close();
        delete serial;
    }
    serial= new QSerialPort;
    serial->setPortName(aida64ReaderForESP8266::portName);
    // if(serial->){
    //     emit shsOpen()owMessage("串口已打开");
    //     return;
    // };
    serial->open(QIODevice::ReadWrite);
    if(serial->isOpen()==false){
        emit showMessage("串口未打开或未找到，请确认串口能否正常通信");
        emit outputState(false);
        qDebug()<<"comOpenFailed";
        return;}
    emit execResult(true);
    serial->setBaudRate(1500000);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

void dataOutputThread::outputData()
{
    qDebug()<<"dataOutputThread::outputData()";
    if(serial->isOpen()==false){
        emit showMessage("串口未打开或未找到，请确认串口能否正常通信");
        emit outputState(false);
        config::startpush=false;
        qDebug()<<"comOpenFailed";
        return;
    }
    if(config::imageInfo==true&&imgInfoList==nullptr){
        emit showMessage("勾选了播放图片或动画,但并没有加载图片,请先加载图片文件再勾选播放");
        emit outputState(false);
        config::startpush=false;
        return;
    }

    while(emit outputState(config::startpush),config::startpush){//判断是否启动推送
        qDebug( )<<"config::startpush"<<config::startpush;

        QTimer timer;
        if(config::hardwareInfo==true){//输出硬件信息
            config::hardwareInfoReload();
            QByteArray value;
            int DPtime=config::hardwareInfoDPtime;
            while(DPtime-->0){
                qDebug( )<<"config::hardwareInfoDPtime："<<config::hardwareInfoDPtime;
                for (int k = 0; config::hardwareInfo==true&&k<10; ) {

                    qDebug()<< allValueQT[k].name << allValueQT[k].state<<endl;
                    if (allValueQT[k].state == true) {
                        timer.start(config::hardwareInfoDPlastTime);
//                        qDebug()<<"发送"<<allValueQT[k].name;
                        while (timer.remainingTime()>0 &&config::startpush ) {
                            // qDebug()<< timer.remainingTime() << " times"<<endl;
                            //!DA#NAME=VALUE?
                            //!DA#CPU_Volt=1.2?
                            if(aida64ReaderForESP8266::readReg(allValueQT[k].strValueName,value )==true){ //  if(Pushdata(allValueQT[k].strValueName,value )==true){ 
                                serial->write("!");
                                serial->write("DA");
                                serial->write("#");
                                serial->write(allValueQT[k].name.toUtf8());
                                serial->write("=");
                                serial->write(value);
                                serial->write("?");
//                                qDebug()<<"发送"<<allValueQT[k].name;
                                if(!serial->waitForBytesWritten())   //这一句很关键，决定是否能发送成功
                                {
                                    qDebug()<<"serial write error";
                                }
                            }else
                                qDebug()<<"发送失败";
                            // Sleep(100);
                        }
                    }
                    k++;
                }
            }
        }



        ///这里添加其他功能
        ///
        if(config::imageInfo==true){
            //加载设置的函数
            qDebug()<<"输出图片";
            for(int tm=0;tm<config::imageInfoLoopTime;tm++){
                qDebug()<<"图片循环次数"<<tm;
                for(int i=0;i<imgListSize&& config::startpush;i++){
                    //for(int e=0;e<1;e++){
                        //            char *tt=new char(0xAA);
                        //            serial->write(tt);
                        //            tt=new char(0x55);
                        //            serial->write(tt);
                    if(config::imageInfo!=true)
                        break;
                    //@$XXXXXXXXXXXXXXXXXXXXX
                        QByteArray fir,ed;
                        fir.resize(2);
                        ed.resize(2);
                        fir[0]=ed[0]='@';//0xAA
                        fir[1]='$';//0x55
                        ed[1]='&';//0x22
                        serial->write(fir);
                        if(!serial->waitForBytesWritten(-1))   //这一句很关键，决定是否能发送成功
                        {
                            qDebug()<<"serial write error";
                        }

                        serial->write(imgInfoList[i].XBM_DATA);
                        serial->waitForBytesWritten(-1);
                        //serial->write(ed);
                        //serial->waitForBytesWritten(-1);
                        qDebug()<<"outputData";
                        //            tt=new char(0x22);
                        //            serial->write(tt);
                    //}
                    QTime t;
                    t.start();
                    while(t.elapsed()<(1000.0/config::imageFps))
                        QCoreApplication::processEvents();
                }
            }

        }
    }
}



void dataOutputThread::closeCom()
{
    if(serial){
        serial->close();
        delete serial;
    }

}


