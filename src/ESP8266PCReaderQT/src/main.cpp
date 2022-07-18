#include "include/mainwindow.h"
#include "include/aida64readerforesp8266.h"
#include <QApplication>
//#include "config.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QFont f("微软雅黑",9);
    QFile qss("../res/style.qss");
    if(!qss.open(QFile::ReadOnly)){
        qDebug()<<"open qss file failed";
    }
    a.setStyleSheet(qss.readAll());
    qss.close();
    // a.setFont(f);
    MainWindow w;
    if(config::setupMinimize==false)
       w.show();
    return a.exec();
}
