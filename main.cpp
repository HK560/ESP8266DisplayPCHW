#include "mainwindow.h"
#include "aida64readerforesp8266.h"
#include <QApplication>
//#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(config::setupMinimize==false)
       w.show();
    return a.exec();
}
