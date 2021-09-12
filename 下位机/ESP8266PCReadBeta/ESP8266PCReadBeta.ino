//兼容上位机版本ver0.1
//下位机程序版本ver0.3
//版本说明：可以显示单位了，更换了字体好看点
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);


String dataName="";
String trueName="";
String dataValue="";
String unit;
String type="";
byte revByte;
char ouputName[15],ouputData[15],ouputUnit[4];
int couttime=0;

struct dataList{
  String dataName;
  String trueName;
  String unit;
};

dataList hwList[10]={
  {"CPU_Volt","CPU Voltage","V"},
  {"GPU_Volt","GPU Voltage","V"},
  {"CPU_UTI","CPU Usage","%"},
  {"CPU_TMP","CPU Temp","C"},
  {"CPU_PKG","CPU Package","W"},
  {"CPU_CLK","CPU Clock","MHz"},
  {"GPU_UTI","GPU Usage","%"},
  {"GPUMC_UTI","GPU Mem Usage","%"},
  {"GPU_TMP","GPU Temp","C"},
  {"MEM_UTI","Memory Usage","%"},
};

void refresh(){//显示函数
    //u8g2.clear(); 
    Serial.println("display");
    u8g2.clearBuffer();                         // 清空显存
    //u8g2.setFont(u8g2_font_unifont_t_chinese2);
    u8g2.setFont(u8g2_font_missingplanet_tr);
    u8g2.drawStr((128-(u8g2.getUTF8Width("My PC Info")))/2, 10, "My PC Info");
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputName)))/2, 25, ouputName);
    
    u8g2.setFont(u8g2_font_freedoomr25_tn);
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputData)))/2, 60, ouputData);
    int length=((128-(u8g2.getUTF8Width(ouputData)))/2)+u8g2.getUTF8Width(ouputData);
    u8g2.setFont(u8g2_font_missingplanet_tf);
    if(strcmp(ouputUnit,"C")==0){//解决显示不了温度单位
      u8g2.setCursor(length+6, 60);
      char c=(char)176;//修改字体需要参考字符文档
      u8g2.print(c);
      u8g2.print(ouputUnit);
    }else{
    u8g2.drawStr(length+6, 60, ouputUnit);
    }
    u8g2.sendBuffer();

}

void boot(){//没有收到数据时候执行的函数
  String title="AMD YES!";//可自定义，限制长度为15
  String subtitle="Connecting...";//可自定义，限制长度为15
  char titleChar[15],subtitleChar[15];
  title.toCharArray(titleChar,15);
  subtitle.toCharArray(subtitleChar,15);
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_missingplanet_tr);
  //设置字体库可以查询u8g2库wiki：https://github.com/olikraus/u8g2/wiki/fntlistall
  //u8g2.setCursor(20, 20);
  u8g2.drawStr((128-(u8g2.getUTF8Width(titleChar)))/2, 20, titleChar);
  //u8g2.print("Ryzen");
  //u8g2.setCursor(0, 35);
  //u8g2.print("connecting PC...");
  u8g2.drawStr((128-(u8g2.getUTF8Width(subtitleChar)))/2, 40, subtitleChar);
  u8g2.sendBuffer();
  //delay(1500); 
  //u8g2.clear(); 
}

void setTrueName(String dataName, String& trueName,String& unit){
  for(int i=0;i<10;i++){
    if(dataName==hwList[i].dataName){
      trueName=hwList[i].trueName;
      unit=hwList[i].unit;
      return;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
    u8g2.begin();
    u8g2.enableUTF8Print();
    Serial.begin(1500000);
    Serial.println("Ready");

}
//!DA#CPU=5?
void loop() {
  // put your main code here, to run repeatedly:
    
    if(Serial.available()>0){
        couttime=0;
        //Serial.println("revmsg");
        revByte=Serial.read(); //读！
        //Serial.print("FRead，should be ！ ");
        //Serial.println((char)revByte);
        if (revByte=='!'){
            //Serial.println("read");
            while(revByte!='#'){
                while (Serial.available() == 0)
                    ;
                revByte=Serial.read();
                if(revByte!='#'){
                    type+=(char)revByte;
                }
            }
            //Serial.println("readName");
            while(revByte!='='){
                while (Serial.available() == 0)
                    ;
                revByte=Serial.read();
                if(revByte!='='){
                    dataName+=(char)revByte;
                }
            }
            //Serial.println("readvalue");
            while(revByte!='?'){
                while (Serial.available() == 0)
                    ;
                revByte=Serial.read();
                if(revByte!='?'){
                    dataValue+=(char)revByte;
                }
            }
            
            Serial.println(type); //如果需要显示其他的信息，去上位机输出里查名称
            Serial.println(dataName);
            Serial.println(dataValue);
            //strcpy(ouputName,dataName);
            //strcpy(ouputData,dataValue);
            //ouputName=const_cast<char*>(dataName.c_str());
            //ouputData=const_cast<char*>(dataValue.c_str());

            setTrueName(dataName,trueName,unit);
            trueName.toCharArray(ouputName,15);//数据名字传到outputname
            dataValue.toCharArray(ouputData,15);//数据值传到outputdata
            unit.toCharArray(ouputUnit,4);
            
            dataName="";//清除
            trueName="";
            dataValue="";
            type="";
            
            refresh();//执行刷新显示函数
        }
        
        while(Serial.read()>=0){}

    }else{ 

      //如果5s内没有收到数据则执行boot()函数
        if(couttime!=5){
            couttime+=1;
            delay(1000);
        }else{
            boot();
            couttime=0;
        }
    }
    
}
