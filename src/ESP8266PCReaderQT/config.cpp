#include "config.h"


bool config::startpush=false;
bool config::setupPush=false;
bool config::setupMinimize=false;
bool config::hardwareInfo=false;
int config::hardwareInfoDPtime=2;
unsigned int config::hardwareInfoDPlastTime = 1000; //每一项持续时间ms


bool config::hardwareInfo_CPUuti=false;
bool config::hardwareInfo_CPUvolt=false;
bool config::hardwareInfo_GPUvolt=false;
bool config::hardwareInfo_CPUclk=false;
bool config::hardwareInfo_CPUpkg=false;
bool config::hardwareInfo_CPUtmp=false;
bool config::hardwareInfo_GPUMCuti=false;
bool config::hardwareInfo_GPUtmp=false;
bool config::hardwareInfo_GPUuti=false;
bool config::hardwareInfo_MENuti=false;

bool config::imageReady=false;
bool config::imageInfo=false;
int config::imageInfoLoopTime=1;
double config::imageFps=25;

config::config()
{
    QFileInfo info("./config.ini");
    //bool fileExit=info.exists();
    configFile=new QSettings("./config.ini",QSettings::IniFormat);
    if(info.exists()==false){
        configFile->setValue("COM","COM1");
        configFile->setValue("AUTOSETUP",true);
    }else
    {
        aida64ReaderForESP8266::portName=configFile->value("COM").toString();
    }


}

void config::hardwareInfoReload(){

    qDebug()<<"config::hardwareInfoReload()";
    // qDebug()<<"值："<<hardwareInfo_CPUvolt;
    allValueQT[0].state=hardwareInfo_CPUvolt;
    //qDebug()<<"实际值："<<allValueQT[0].state;
    allValueQT[1].state=hardwareInfo_GPUvolt;
    allValueQT[2].state=hardwareInfo_CPUuti;
    allValueQT[3].state=hardwareInfo_CPUtmp;
    allValueQT[4].state=hardwareInfo_CPUpkg;
    allValueQT[5].state=hardwareInfo_CPUclk;
    allValueQT[6].state=hardwareInfo_GPUuti;
    allValueQT[7].state=hardwareInfo_GPUMCuti;
    allValueQT[8].state=hardwareInfo_GPUtmp;
    allValueQT[9].state=hardwareInfo_MENuti;

}

void config::imageInfoReload()
{

}
