#ifndef CONFIG_H
#define CONFIG_H

#include <QSettings>
#include<QFileInfo>
#include"aida64readerforesp8266.h"

class config
{
public:
    config();

    static bool setupPush;//是否启动推送
    static bool setupMinimize;

    static bool hardwareInfo;//是否推送硬件信息
    static int hardwareInfoDPtime;//推送硬件信息循环次数

    static bool hardwareInfo_CPUuti;
    static bool hardwareInfo_CPUvolt;
    static bool hardwareInfo_GPUvolt;
    static bool hardwareInfo_CPUclk;
    static bool hardwareInfo_CPUpkg;
    static bool hardwareInfo_CPUtmp;
    static bool hardwareInfo_GPUMCuti;
    static bool hardwareInfo_GPUtmp;
    static bool hardwareInfo_GPUuti;
    static bool hardwareInfo_MENuti;



    static void hardwareInfoReload();

    void setupconfig();
    void readconfig(QSettings config);
    void writeconfig(QSettings config);
    QSettings *configFile;
#endif // CONFIG_H

};


