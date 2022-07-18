//兼容上位机版本0.3
//下位机程序版本ver3.0
//版本说明：支持udp通信
#include <ESP8266WiFi.h>  //ESP8266基本网络功能
#include <U8g2lib.h>
#include <WiFiUdp.h>  //提供UDP相关功能
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

String dataName = "";
String trueName = "";
String dataValue = "";
String unit;
String type = "";
byte revByte;
char ouputName[15], ouputData[15], ouputUnit[4];
int couttime = 0;
uint8_t frame[1024] = {};

const char* ssid = "XXXXXX";  //网络名称 修改为你的wifi名字
const char* password = "XXXXX";    //网络密码 修改为你的wifi密码

WiFiUDP Udp;
unsigned int localUdpPort = 56000;  // 本地端口号
char incomingPacket[10000];         // 接收缓冲区

struct dataList {
    String dataName;
    String trueName;
    String unit;
};

dataList hwList[10] = {
    {"CPU_Volt", "CPU Voltage", "V"}, {"GPU_Volt", "GPU Voltage", "V"},
    {"CPU_UTI", "CPU Usage", "%"},    {"CPU_TMP", "CPU Temp", "C"},
    {"CPU_PKG", "CPU Package", "W"},  {"CPU_CLK", "CPU Clock", "MHz"},
    {"GPU_UTI", "GPU Usage", "%"},    {"GPUMC_UTI", "GPU Mem Usage", "%"},
    {"GPU_TMP", "GPU Temp", "C"},     {"MEM_UTI", "Memory Usage", "%"},
};

void refresh() {  //显示函数
    // u8g2.clear();
    Serial.println("display");
    u8g2.clearBuffer();  // 清空显存
    // u8g2.setFont(u8g2_font_unifont_t_chinese2);
    u8g2.setFont(u8g2_font_missingplanet_tr);
    u8g2.drawStr((128 - (u8g2.getUTF8Width("My PC Info"))) / 2, 10,
                 "My PC Info");
    u8g2.drawStr((128 - (u8g2.getUTF8Width(ouputName))) / 2, 25, ouputName);

    u8g2.setFont(u8g2_font_freedoomr25_tn);
    u8g2.drawStr((128 - (u8g2.getUTF8Width(ouputData))) / 2, 60, ouputData);
    int length = ((128 - (u8g2.getUTF8Width(ouputData))) / 2) +
                 u8g2.getUTF8Width(ouputData);
    u8g2.setFont(u8g2_font_missingplanet_tf);
    if (strcmp(ouputUnit, "C") == 0) {  //解决显示不了温度单位
        u8g2.setCursor(length + 6, 60);
        char c = (char)176;  //修改字体需要参考字符文档
        u8g2.print(c);
        u8g2.print(ouputUnit);
    } else {
        u8g2.drawStr(length + 6, 60, ouputUnit);
    }
    u8g2.sendBuffer();
}

void boot() {                     //没有收到数据时候执行的函数
    String title = "elbadaernU";  //可自定义，限制长度为15
    String subtitle = "Waiting for signal";  //可自定义，限制长度为15
    char titleChar[15], subtitleChar[30];
    title.toCharArray(titleChar, 15);
    subtitle.toCharArray(subtitleChar, 30);

    char nowip[20];
    String ipStr = WiFi.localIP().toString();
    ipStr.toCharArray(nowip, 20);
    Serial.println(ipStr);

    // u8g2.drawStr(1, 10, "1232133");
    // u8g2.sendBuffer();
    // delay(5000);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_missingplanet_tr);

    //设置字体库可以查询u8g2库wiki：https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr((128 - (u8g2.getUTF8Width(titleChar))) / 2, 20, titleChar);
    u8g2.drawStr((128 - (u8g2.getUTF8Width(subtitleChar))) / 2, 40,
                 subtitleChar);
    u8g2.drawStr((128 - (u8g2.getUTF8Width(nowip))) / 2, 55, nowip);

    u8g2.sendBuffer();

    Udp.begin(localUdpPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n",
                  WiFi.localIP().toString().c_str(), localUdpPort);
}

void setTrueName(String dataName, String& trueName, String& unit) {
    for (int i = 0; i < 10; i++) {
        if (dataName == hwList[i].dataName) {
            trueName = hwList[i].trueName;
            unit = hwList[i].unit;
            return;
        }
    }
    //not found
    trueName = dataName;
    unit = "";
    return;

}

void setup() {
    // put your setup code here, to run once:
    u8g2.begin();
    u8g2.enableUTF8Print();
    u8g2.clearBuffer();
    Serial.begin(1500000);
    Serial.println("Ready");
    // wifi connect
    WiFi.begin(ssid, password);      // 启动网络连接
    Serial.print("Connecting to ");  // 串口监视器输出网络连接信息
    Serial.print(ssid);
    Serial.println(" ...");  // 告知用户NodeMCU正在尝试WiFi连接

    int i = 0;  // 这一段程序语句用于检查WiFi是否连接成功
    while (
        WiFi.status() !=
        WL_CONNECTED) {  // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。
        delay(1000);     // 如果WiFi连接成功则返回值为WL_CONNECTED
        Serial.print(i++);
        Serial.print(
            ' ');  // 此处通过While循环让NodeMCU每隔一秒钟检查一次WiFi.status()函数返回值
    }  // 同时NodeMCU将通过串口监视器输出连接时长读秒。
       // 这个读秒是通过变量i每隔一秒自加1来实现的。

    Serial.println("");  // WiFi连接成功后
    Serial.println(
        "Connection established!");  // NodeMCU将通过串口监视器输出"连接成功"信息。
    Serial.print(
        "IP address:    ");  // 同时还将输出NodeMCU的IP地址。这一功能是通过调用
    Serial.println(
        WiFi.localIP());  // WiFi.localIP()函数来实现的。该函数的返回值即NodeMCU的IP地址。
    // u8g2.clearBuffer();
    // char ip[56];
    // String  ipStr = WiFi.localIP().toString();
    // ipStr.toCharArray(ip,56);
    // Serial.print("drawStr:    ");             //
    // 同时还将输出NodeMCU的IP地址。这一功能是通过调用 清空显存
    // u8g2.drawStr(1, 10, "1232133");
    // u8g2.sendBuffer();

    boot();
}
//! DA#CPU=5?
void loop() {
    // put your main code here, to run repeatedly:

    int packetSize = Udp.parsePacket();  //获取当前队首数据包长度
    char firstChar[2];
    firstChar[1] = 0;
    if (packetSize)  // 有数据可用
    {
        Serial.printf("Received %d bytes from %s, port %d\n", packetSize,
                      Udp.remoteIP().toString().c_str(), Udp.remotePort());
        revByte = Udp.read();  // 读取数据到incomingPacket
        packetSize--;
        firstChar[0] = revByte;
        // if (lenf > 0)                             // 如果正确读取
        
            Serial.printf("UDP header contents: %s\n", firstChar);

            if (revByte == '!') {
                Serial.printf("is!");
                while (revByte != '#'&& packetSize>0) {
                    revByte = Udp.read();
                    packetSize--;

                    if (revByte != '#') {
                        type += (char)revByte;
                    }
                }
                while (revByte != '=' && packetSize>0) {
                    revByte = Udp.read();
                    packetSize--;
                    if (revByte != '=') {
                        dataName += (char)revByte;
                    }
                }
                while (revByte != '?' && packetSize>0) {
                    revByte = Udp.read();
                    packetSize--;

                    if (revByte != '?') {
                        dataValue += (char)revByte;
                    }
                }
                Serial.println(
                    type);  //如果需要显示其他的信息，去上位机输出里查名称
                Serial.println(dataName);
                Serial.println(dataValue);

                setTrueName(dataName, trueName, unit);
                trueName.toCharArray(ouputName, 15);  //数据名字传到outputname
                dataValue.toCharArray(ouputData, 15);  //数据值传到outputdata
                unit.toCharArray(ouputUnit, 4);

                dataName = "";  //清除
                trueName = "";
                dataValue = "";
                type = "";

                refresh();  //执行刷新显示函数
            }

            else if (revByte == '@') {
              // if (Serial.available() > 0) {
                Serial.println("readimage");
                revByte = Udp.read();
                if (revByte == '$') {
                    // int countnum = 0;
                    // for (int i = 0; i < 1024; i++) {
                    //     frame[i] = Udp.read();
                    //     // countnum++;
                    // }
                    Udp.read(frame,1024);
                    u8g2.firstPage();
                    do {
                        u8g2.drawXBM(0, 0, 128, 64, frame);
                    } while (u8g2.nextPage());
                } else if (revByte == '&')
                    return;
            // }
            }
    }

    if (Serial.available() > 0) {
        u8g2.clearBuffer();
        revByte = Serial.read();
        if (revByte == '@') {
            if (Serial.available() > 0) {
                revByte = Serial.read();
                if (revByte == '$') {
                    // int countnum = 0;
                    for (int i = 0; i < 1024; i++) {
                        while (Serial.available() == 0)
                            ;
                        frame[i] = Serial.read();
                        // countnum++;
                    }
                    u8g2.firstPage();
                    do {
                        u8g2.drawXBM(0, 0, 128, 64, frame);
                    } while (u8g2.nextPage());
                } else if (revByte == '&')
                    return;
            }
        } else {
            if (revByte == '!') {
                // Serial.println("read");
                while (revByte != '#') {
                    while (Serial.available() == 0)
                        ;
                    revByte = Serial.read();
                    if (revByte != '#') {
                        type += (char)revByte;
                    }
                }
                // Serial.println("readName");
                while (revByte != '=') {
                    while (Serial.available() == 0)
                        ;
                    revByte = Serial.read();
                    if (revByte != '=') {
                        dataName += (char)revByte;
                    }
                }
                // Serial.println("readvalue");
                while (revByte != '?') {
                    while (Serial.available() == 0)
                        ;
                    revByte = Serial.read();
                    if (revByte != '?') {
                        dataValue += (char)revByte;
                    }
                }

                Serial.println(
                    type);  //如果需要显示其他的信息，去上位机输出里查名称
                Serial.println(dataName);
                Serial.println(dataValue);

                setTrueName(dataName, trueName, unit);
                trueName.toCharArray(ouputName, 15);  //数据名字传到outputname
                dataValue.toCharArray(ouputData, 15);  //数据值传到outputdata
                unit.toCharArray(ouputUnit, 4);

                dataName = "";  //清除
                trueName = "";
                dataValue = "";
                type = "";

                refresh();  //执行刷新显示函数
            }
            couttime = 0;
            revByte = Serial.read();  //读！
            while (Serial.read() >= 0) {
            }
        }
    }
    // else{

    //   //如果5s内没有收到数据则执行boot()函数
    //     if(couttime!=500){
    //         couttime++;
    //         delay(10);
    //     }else{
    //         boot();
    //         couttime=0;
    //     }

    // }
}
