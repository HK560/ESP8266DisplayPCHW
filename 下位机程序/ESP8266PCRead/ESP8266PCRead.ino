#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);


String dataName="";
String dataValue="";
String type="";
byte revByte;
char ouputName[15],ouputData[15];
int couttime=0;

void refresh(){
    //u8g2.clear(); 
    Serial.println("display");
    u8g2.clearBuffer();                         // 清空显存
    u8g2.setFont(u8g2_font_unifont_t_chinese2);
    u8g2.drawStr((128-(u8g2.getUTF8Width("HK560's PC")))/2, 15, "HK560's PC");
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputName)))/2, 30, ouputName);
    u8g2.drawStr((128-(u8g2.getUTF8Width(ouputData)))/2, 45, ouputData);
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
            dataName.toCharArray(ouputName,15);
            dataValue.toCharArray(ouputData,15);

            dataName="";
            dataValue="";
            type="";
            refresh();
        }
        
        while(Serial.read()>=0){}

    }else{ 
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
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_unifont_t_chinese2);
  u8g2.setCursor(20, 20);
  u8g2.print("Booting...");
  u8g2.setCursor(0, 35);
  u8g2.print("connecting PC...");
  u8g2.sendBuffer();
  //delay(1500); 
  //u8g2.clear(); 
}
