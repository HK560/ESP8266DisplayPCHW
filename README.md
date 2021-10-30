# 关于本项目
*使用esp8266与oled屏幕输出监控电脑硬件和显示其他信息,实现类似于高端主板上面的小屏幕功能*

受b站up主 会飞的阿卡林 视频启发
不同点在于上位机获取硬件信息方式不同

通过上位机+下位机模式实现,均已开源

上位机从aida64读取出硬件信息并通过串口传输到下位机ESP8266显示到OLED屏幕上

PC需要安装运行AIDA64和本项目的上位机程序,ESP8266需要烧录本项目的下位机程序

## 使用方法简述
- 1.clone本项目,获取上位机程序和下位机程序源码.ino文件
- 2.使用arduino ide将下位机源码烧录进esp8266(软件配置和烧录方法不再描述,可自行搜索教程)
- 3.将连接好oled屏幕的esp8266连接电脑
- 4.启动aida64并在设置里勾选 “允许将检测数据写入注册表”,将列表中所有的硬件信息选项打勾, 保存。
- 5.打开上位机程序设置esp8266所连接的串口号,根据自己需求设置勾选要显示的项目,启动运行,正常运行的话oled屏幕会开始显示信息。

## 上位机程序ESP8266 Pc Reader
#### 特点:
- 通过读取aida64写入到注册表的信息获取数据,而非aida64共享内存
- 可自定义串口
- 可自定义要显示的硬件信息类型
- 可自动最小化到托盘(用于开机启动)
- 可保存读取设置
- 播放动画/图片功能

![](https://cdn.jsdelivr.net/gh/HK560/MyPicHub@master/res/pic/20210922171958.png)

## 下位机程序
- 已开源,可以自行修改显示的字体、样式、文字, 具体参考u8g2库的官方文档

[视频演示](https://www.bilibili.com/video/BV1sM4y137Ay/ "视频演示")

<img src="https://cdn.jsdelivr.net/gh/HK560/MyPicHub@master/res/pic/esp8266show2.jpg" alt="示例1" width="300" >

![示例1](https://cdn.jsdelivr.net/gh/HK560/MyPicHub@master/res/pic/esp8266Show1.jpg)

---------------
其他说明请点击：
[Read more](https://blog.hk560.top/Aida64ForEsp8266/ "Read more")

------------

