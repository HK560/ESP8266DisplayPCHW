#include "config.h"



bool config::setupPush=false;
bool config::hardwareInfo=false;
int config::hardwareInfoDPtime=2;

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
    allValue[0].state=hardwareInfo_CPUvolt;
    allValue[1].state=hardwareInfo_GPUvolt;
    allValue[2].state=hardwareInfo_CPUuti;
    allValue[3].state=hardwareInfo_CPUtmp;
    allValue[4].state=hardwareInfo_CPUpkg;
    allValue[5].state=hardwareInfo_CPUclk;
    allValue[6].state=hardwareInfo_GPUuti;
    allValue[7].state=hardwareInfo_GPUMCuti;
    allValue[8].state=hardwareInfo_GPUtmp;
    allValue[9].state=hardwareInfo_MENuti;

}
