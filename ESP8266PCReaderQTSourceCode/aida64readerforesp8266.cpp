#include "aida64readerforesp8266.h"
//#include <atlstr.h>

using namespace std;


int aida64ReaderForESP8266::cycletime=3;
bool aida64ReaderForESP8266::ifStopSignal=true;
QString aida64ReaderForESP8266::portName="null";


aida64ValueList allValue[10] ={
        {(_T("Value.VCPU")),"CPU_Volt",false},
        {(_T("Value.VGPU1")),"GPU_Volt",true},
        {(_T("Value.SCPUUTI")),"CPU_UTI",true},
        {(_T("Value.TCPU")),"CPU_TMP",true},
        {(_T("Value.PCPUPKG")),"CPU_PKG",true},
        {(_T("Value.SCPUCLK")),"CPU_CLK",true},
        {(_T("Value.SGPU1UTI")),"GPU_UTI",true},
        {(_T("Value.SGPU1MCUTI")),"GPUMC_UTI",true},
        {(_T("Value.TGPU1DIO")),"GPU_TMP",true},
        {(_T("Value.SMEMUTI")),"MEM_UTI",true},

    };

void aida64ReaderForESP8266::wcharTochar(const wchar_t* wchar, char* chr, int length)
{
    WideCharToMultiByte(CP_ACP, 0, wchar, -1,
        chr, length, NULL, NULL);
}

bool aida64ReaderForESP8266::OpenRegKey(HKEY& hRetKey, LPCWSTR sw)
{
    //LPCWSTR sw = _T("SOFTWARE\\FinalWire\\AIDA64\\SensorValues");//_T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Bandizip.exe");
    //wprintf(L"SW is %s\n", sw);
    if (ERROR_SUCCESS == RegOpenKey(HKEY_CURRENT_USER, sw, &hRetKey)) //注意是HKEY_CURRENT_USER
    {
        return true;
    }
    printf("OpenRegKey return is false!\n");
    return false;
}

bool aida64ReaderForESP8266::QueryRegKey(LPCWSTR strSubKey, LPCWSTR strValueName, char* strValue, int length)//这里是传3个参数
{
    DWORD dwType = REG_SZ;//定义数据类型
    DWORD dwLen = MAX_PATH;
    wchar_t data[MAX_PATH];
    HKEY hKey;
    HKEY hSubKey;
    if (OpenRegKey(hKey, strSubKey))
    {
        if (ERROR_SUCCESS == RegOpenKey(HKEY_CURRENT_USER, strSubKey, &hSubKey))
        {
            TCHAR buf[256] = { 0 };
            if (ERROR_SUCCESS == RegQueryValueEx(hSubKey, strValueName, 0, &dwType, (LPBYTE)data, &dwLen))
            {
                wcharTochar(data, strValue, length);
                //wprintf(L"data = %s,len= %d\n", data, strlen((const char*)data));
                RegCloseKey(hKey); //关闭注册表
                return true;
            }
        }
        RegCloseKey(hKey); //关闭注册表
    }
    return false;
}



//想要检测什么项目就在下面的数组按照格式插入，strValueName请去查表

//void formatList() {
    //int i = 0;
   // for (; allValue[i].end == false; i++);
    //allValue[i] = { (_T("")),"",false,true };
//}
void aida64ReaderForESP8266::test1()
{
    qDebug()<<"run";

    //cout << "aida64REGLocation：" << REG_LOCATION<<endl;

    HKEY  hKey = NULL;
    string result;
    LPCWSTR strSubKey = _T(REG_LOCATION);
    //LPCWSTR strValueName = _T("Value.VCPU");
    char strValue[256];
    int length = 256;
    for (int i=0;i<10 ;i++ ) {
        qDebug()<< i << " times"<<endl;
        for (int k = 0; allValue[k].end == false; k++) {
            if (allValue[k].state == true) {
                QueryRegKey((LPCWSTR)strSubKey, allValue[k].strValueName, strValue, length);
                //QString qStr=allValue[k].name;
                qDebug()<<allValue[k].name;
                //cout << allValue[k].name;
                // printf("status is %d\n", status);
                qDebug()<<strValue;
                //printf(": %s\n", strValue);
            }
        }
        cout << endl;
        Sleep(1000);
    }
    //delete []allValue;
    //bool status = QueryRegKey(strSubKey, strValueName, strValue, length);
    //printf("status is %d\n", status);
    //printf("result is %s\n", strValue);
    //return 0;
}


bool Pushdata(LPCWSTR strValueName,QByteArray &value ){

    LPCWSTR strSubKey = _T(REG_LOCATION);

    char strValue[256];
    int length = 256;

    aida64ReaderForESP8266::QueryRegKey((LPCWSTR)strSubKey, strValueName, strValue, length);
    value=strValue;

    return true;



}
