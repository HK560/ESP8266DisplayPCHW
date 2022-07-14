#ifndef DATAOUTPUTTHREAD_H
#define DATAOUTPUTTHREAD_H
#include<QThread>
#include<QDebug>
#include <QtSerialPort/QtSerialPort>
#include <QObject>
#include "aida64readerforesp8266.h"
#include <QMessageBox>
#include "config.h"
#include "imageinfo.h"
#include <QTimer>

class dataOutputThread:public   QObject{
    Q_OBJECT
public:
    explicit dataOutputThread(QObject *parent=nullptr);
signals:
    void resultReady(const QString &str);
    void showMessage(const QString &str);
    void outputState(const bool run);
    void execResult(const bool state);
public slots:
    void openCom();
    void outputData();
    void closeCom();
    //void closeThread();
private:
    QSerialPort *serial = nullptr;

};

#endif // DATAOUTPUTTHREAD_H
