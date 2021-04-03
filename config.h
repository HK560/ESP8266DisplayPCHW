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
    static bool hardwareInfo;//是否推送硬件信息
    static int hardwareInfoDPtime;//推送硬件信息循环次数

    static int hardwareInfo_CPUuti;
    static int hardwareInfo_CPUvolt;
    static int hardwareInfo_GPUvolt;
    static int hardwareInfo_CPUclk;
    static int hardwareInfo_CPUpkg;
    static int hardwareInfo_CPUtmp;
    static int hardwareInfo_GPUMCuti;
    static int hardwareInfo_GPUtmp;
    static int hardwareInfo_GPUuti;
    static int hardwareInfo_MENuti;

    static void hardwareInfoReload();

    void setupconfig();
    void readconfig(QSettings config);
    void writeconfig(QSettings config);
    QSettings *configFile;
#endif // CONFIG_H

};


