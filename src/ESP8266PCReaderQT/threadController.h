#ifndef THREADCONTROLLER_H
#define THREADCONTROLLER_H
#include <QObject>
#include <QThread>
#include "dataoutputthread.h"

class ThreadController : public QObject
{
    Q_OBJECT
public:
    explicit ThreadController(QObject *parent=nullptr);
    ~ThreadController();

    void startOutput();
    void startOpenCom();
    void startCloseCom();
signals:
    void singal_startOutputData();
    void singal_startOpenCom();
    void singal_startCloseCom();
    void singal_showMeg(const QString &str);
    void singal_outputState(const bool run);
    //void singal_closeThread();


public  slots:
    void on_revResult(const QString &str);
    void on_msgShow(const QString &str);
    void on_outputState(const bool run);
private:
    QThread m_dataQThread;
    dataOutputThread *m_worker;
};

#endif // THREADCONTROLLER_H
