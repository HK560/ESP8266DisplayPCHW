#include "dataoutputthread.h"


dataOutputThread::dataOutputThread(QObject *parent):QObject(parent)
{
    // serial=new QSerialPort;
    socket = new QUdpSocket(parent);
}

void dataOutputThread::openCom()
{
    qDebug()<<"dataOutputThread::openCom()";
    if(serial != nullptr){
        serial->close();
        delete serial;
    }
    serial= new QSerialPort(this);
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
    if(config::comEnabled&&serial->isOpen()==false){
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
       QHostAddress address;
    if(config::udpEnabled){
        address.setAddress(config::udpAddress);
    }


    if(!config::comEnabled&&!config::udpEnabled){
        //如果都没开启结束
        config::startpush=false;
        emit showMessage("串口通信和UDP通信都未启用，停止发送数据");
        emit outputState(false);
        return;
    }

    while(emit outputState(config::startpush),config::startpush){//判断是否启动推送
        // qDebug( )<<"config::startpush"<<config::startpush;

        QTimer timer;
        if(config::hardwareInfo==true){//输出硬件信息
            config::hardwareInfoReload();//获取硬件信息输出设置
            QByteArray value;
            QByteArray udpData;
//            udpData.clear();
            int DPtime=config::hardwareInfoDPtime;
            while(DPtime-->0){//硬件信息循环次数
                // qDebug( )<<"config::hardwareInfoDPtime："<<config::hardwareInfoDPtime;
                for (int k = 0; config::hardwareInfo==true&&k<10; ) {//轮询查询能输出的信息项目
                    // qDebug()<< allValueQT[k].name << allValueQT[k].state<<endl;
                    if (allValueQT[k].state == true) {
                        timer.start(config::hardwareInfoDPlastTime);//计时
                        while (timer.remainingTime()>0 &&config::startpush ) {//没到时就循环发送
                            //!DA#NAME=VALUE?
                            //!DA#CPU_Volt=1.2?
                            if(aida64ReaderForESP8266::readReg(allValueQT[k].strValueName,value )==true){ //读取值到value
                                //  if(Pushdata(allValueQT[k].strValueName,value )==true){ 
                                if(config::comEnabled){
                                    serial->write("!");
                                    serial->write("DA");
                                    serial->write("#");
                                    serial->write(allValueQT[k].name.toUtf8());
                                    serial->write("=");
                                    serial->write(value);
                                    serial->write("?");
                                    if (!serial->waitForBytesWritten())  //这一句很关键，决定是否能发送成功
                                        qDebug() << "serial write error";
                                }
                                if(config::udpEnabled){
                                    udpData.clear();
                                    udpData.append("!DA#");
                                    udpData.append(allValueQT[k].name.toUtf8());
                                    udpData.append("=");
                                    udpData.append(value);
                                    udpData.append("?");
                                    if(socket->writeDatagram(udpData,address,56000) < 0)
                                        qDebug() <<"udp write error";
                                }

                            }else
                                qDebug()<<"读取数据失败";
                            Sleep(100);
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
                    if(config::imageInfo)
                    //@$XXXXXXXXXXXXXXXXXXXXX

                    if(config::comEnabled){
                        QByteArray fir,ed;
                        fir.resize(2);
                        ed.resize(2);
                        fir[0]=ed[0]='@';//0xAA
                        fir[1]='$';//0x55
                        ed[1]='&';//0x22
                        serial->write(fir);
                        if(!serial->waitForBytesWritten(-1))   //这一句很关键，决定是否能发送成功
                            qDebug()<<"serial write error";
                        serial->write(imgInfoList[i].XBM_DATA);
                        serial->waitForBytesWritten(-1);
                        //serial->write(ed);
                        //serial->waitForBytesWritten(-1);
                        qDebug()<<"outputData";
                    }

                    if(config::udpEnabled){
                        QByteArray udpDataImage;
                        udpDataImage.append("@$");
                        udpDataImage.append(imgInfoList[i].XBM_DATA);
                        if (socket->writeDatagram(udpDataImage, address, 56000) < 0)
                            qDebug() << "udp write error";
                    }
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


