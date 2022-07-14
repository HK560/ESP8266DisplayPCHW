#ifndef CONFIG_H
#define CONFIG_H

#include <QSettings>
#include<QFileInfo>
#include"aida64readerforesp8266.h"

class config
{
public:
    config();
    static bool startpush;
    static bool setupPush;//是否启动推送
    static bool setupMinimize;

    static bool hardwareInfo;//是否推送硬件信息
    static int hardwareInfoDPtime;//推送硬件信息循环次数
    static unsigned int hardwareInfoDPlastTime; //每一项持续时间ms
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

    static bool imageReady;//图片是否已经加载
    static bool imageInfo;//是否显示图片
    static int imageInfoLoopTime;//图片循环时间
    static double imageFps;
   

    static void hardwareInfoReload();
    static void imageInfoReload();

    void setupconfig();
    void readconfig(QSettings config);
    void writeconfig(QSettings config);
    QSettings *configFile;
#endif // CONFIG_H

};


