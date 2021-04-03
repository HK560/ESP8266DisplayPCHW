#ifndef AIDA64READERFORESP8266_H
#define AIDA64READERFORESP8266_H

#include <iostream>
#include <assert.h>
#include "windows.h"
#include "tchar.h"
#include "conio.h"
#include "stdio.h"
#include <QDebug>
#include <QtSerialPort/QtSerialPort>


#define REG_LOCATION "SOFTWARE\\FinalWire\\AIDA64\\SensorValues"   //aida64共享的数据的注册表路径



class aida64ReaderForESP8266
{
public:
    aida64ReaderForESP8266();
    static void wcharTochar(const wchar_t* wchar, char* chr, int length);
    static bool OpenRegKey(HKEY& hRetKey, LPCWSTR sw);
    static bool QueryRegKey(LPCWSTR strSubKey, LPCWSTR strValueName, char* strValue, int length);
    static void test1();
    static int cycletime;//显示几秒
    static bool ifStopSignal;
    static QString portName;
};

struct aida64ValueList {
    LPCWSTR strValueName;//检测的项目在注册表的名字
    QString name;//检查项目名字
    bool state;//是否读取该数据
    bool end=false;//结束标志
    aida64ValueList(LPCWSTR sVName,QString n,bool st){
        strValueName=sVName;
        name=n;
        state=st;
    };
};

static aida64ValueList  *allValue =new aida64ValueList[10] {
        {(_T("Value.VCPU")),"CPU_Volt",true},
        {(_T("Value.VGPU1")),"GPU_Volt",true},
        {(_T("Value.SCPUUTI")),"CPU_UTI",true},
        {(_T("Value.TCPU")),"CPU_TMP",true,},
        {(_T("Value.PCPUPKG")),"CPU_PKG",true,},
        {(_T("Value.SCPUCLK")),"CPU_CLK",true,},
        {(_T("Value.SGPU1UTI")),"GPU_UTI",true,},
        {(_T("Value.SGPU1MCUTI")),"GPUMC_UTI",true,},
        {(_T("Value.TGPU1DIO")),"GPU_TMP",true,},
        {(_T("Value.SMEMUTI")),"MEM_UTI",true,},
    };

bool Pushdata(LPCWSTR strValueName,QByteArray &value );



#endif // AIDA64READERFORESP8266_H
