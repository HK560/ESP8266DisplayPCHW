#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);


String dataName="";
String dataValue="";
String type="";
byte revByte;
char ouputName[15],ouputData[15];
int couttime=0;

void refresh(){//显示函数
    //u8g2.clear(); 
    Serial.println("display");
    u8g2.clearBuffer();                         // 清空显存
    //u8g2.setFont(u8g2_font_unifont_t_chinese2);
    u8g2.setFont(u8g2_font_freedoomr10_mu);
    u8g2.drawStr((128-(u8g2.getUTF8Width("HK560's PC")))/2, 0, "HK560's PC");
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputName)))/2, 12, ouputName);
    u8g2.setFont(u8g2_font_freedoomr25_tn);
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputData)))/2, 24, ouputData);
    u8g2.sendBuffer();
}

void setup() {
  // put your setup code here, to run once:
    u8g2.begin();
    u8g2.enableUTF8Print();
    Serial.begin(115200);
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
            dataName.toCharArray(ouputName,15);//数据名字传到outputname
            dataValue.toCharArray(ouputData,15);//数据值传到outputdata

            dataName="";//清除
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


void boot(){
  String title="AMD YES!";//限制长度为15
  String subtitle="waiting for data";//限制长度为15
  char titleChar[15],subtitleChar[15];
  title.toCharArray(titleChar,15);
  subtitle.toCharArray(subtitleChar,15);
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_freedoomr10_mu);
  //u8g2.setCursor(20, 20);
  u8g2.drawStr((128-(u8g2.getUTF8Width(titleChar)))/2, 20, titleChar);
  //u8g2.print("Ryzen");
  //u8g2.setCursor(0, 35);
  //u8g2.print("connecting PC...");
  u8g2.drawStr((128-(u8g2.getUTF8Width(subtitleChar)))/2, 35, subtitleChar);
  u8g2.sendBuffer();
  //delay(1500); 
  //u8g2.clear(); 
}
