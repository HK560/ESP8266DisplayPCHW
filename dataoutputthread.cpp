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
         qDebug()<<"comOpenFailed";
        return;}
    serial->setBaudRate(QSerialPort::Baud115200);
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
        qDebug()<<"comOpenFailed";
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






    }

}



void dataOutputThread::closeCom()
{
    serial->close();

}


