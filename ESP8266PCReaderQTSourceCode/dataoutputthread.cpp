#include "dataoutputthread.h"


dataOutputThread::dataOutputThread(QObject *parent):QObject(parent)
{
    serial=new QSerialPort;
}

void dataOutputThread::openCom()
{
    qDebug()<<"dataOutputThread::openCom()";
    serial= new QSerialPort;
    serial->setPortName(aida64ReaderForESP8266::portName);
    serial->open(QIODevice::ReadWrite);
    if(serial->isOpen()==false){
        emit showMessage("串口未打开或未找到，请确认串口能否正常通信");
        emit outputState(false);
        qDebug()<<"comOpenFailed";
        return;}
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

    while(emit outputState(config::startpush),config::startpush==true){//判断是否启动推送
        qDebug( )<<"config::startpush"<<config::startpush;


        if(config::hardwareInfo==true){//输出硬件信息
            config::hardwareInfoReload();
            QByteArray value;
            int DPtime=config::hardwareInfoDPtime;
            while(DPtime-->0){
                qDebug( )<<"config::hardwareInfoDPtime："<<config::hardwareInfoDPtime;
                for (int k = 0; config::hardwareInfo==true&&k<10; ) {

                    qDebug()<< allValue[k].name << allValue[k].state<<endl;
                    if (allValue[k].state == true) {
                        for (int i=0;i<aida64ReaderForESP8266::cycletime ;i++ ) {
                            qDebug()<< i << " times"<<endl;
                            if(Pushdata(allValue[k].strValueName,value )==true){
                                serial->write("!");
                                serial->write("DA");
                                serial->write("#");
                                serial->write(allValue[k].name.toUtf8());
                                serial->write("=");
                                serial->write(value);
                                serial->write("?");
                                qDebug()<<"发送"<<allValue[k].name;
                                if(!serial->waitForBytesWritten())   //这一句很关键，决定是否能发送成功
                                {
                                    qDebug()<<"serial write error";
                                }
                            }else
                                qDebug()<<"发送失败";
                            Sleep(1000);
                        }
                    }
                    k++;
                    //                                        if(allValue[k].end != false){
                    //                                            k=0;}
                }
            }
        }



        ///这里添加其他功能
        ///
        if(config::imageInfo==true){
            //加载设置的函数
            for(int tm=0;tm<config::imageInfoLoopTime;tm++){
                for(int i=0;i<imgListSize;i++){
                    for(int e=0;e<1;e++){
                        //            char *tt=new char(0xAA);
                        //            serial->write(tt);
                        //            tt=new char(0x55);
                        //            serial->write(tt);
                        QByteArray fir,ed;
                        fir.resize(2);
                        ed.resize(2);
                        fir[0]=ed[0]=0xAA;
                        fir[1]=0x55;
                        ed[1]=0x22;
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
                    }
                    QTime t;
                    t.start();
                    while(t.elapsed()<50)
                        QCoreApplication::processEvents();
                }
            }

        }










    }

}



void dataOutputThread::closeCom()
{
    serial->close();

}


