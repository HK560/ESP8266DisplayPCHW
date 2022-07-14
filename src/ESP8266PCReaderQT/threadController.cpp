#include "threadController.h"
#include <QThread>
#include <QDebug>

ThreadController::ThreadController(QObject *parent):QObject(parent)
{
    m_worker=new dataOutputThread();
    m_worker->moveToThread(&m_dataQThread);

    connect(this,&ThreadController::singal_startOutputData,m_worker,& dataOutputThread::outputData);
    connect(this,&ThreadController::singal_startOpenCom,m_worker,& dataOutputThread::openCom);
    connect(this,&ThreadController::singal_startCloseCom,m_worker,& dataOutputThread::closeCom);
    connect(&m_dataQThread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_worker, &dataOutputThread::resultReady, this, &ThreadController::on_revResult);
    connect(m_worker, &dataOutputThread::showMessage, this, &ThreadController::on_msgShow);
    connect(m_worker, &dataOutputThread::outputState, this, &ThreadController::on_outputState);
    connect(m_worker, &dataOutputThread::execResult, this, &ThreadController::on_execResult);
    
    //connect(this,&ThreadController::singal_closeThread,this);
    m_dataQThread.start();
}

ThreadController::~ThreadController()
{
  m_dataQThread.quit();
  m_dataQThread.terminate();
  m_dataQThread.wait();
}

void ThreadController::startOutput()
{
    qDebug()<<"emit singal_startOutputData()";
    emit singal_startOutputData();
}

void ThreadController::startOpenCom()
{
    qDebug()<<"emit singal_startOpenCom()";
    emit singal_startOpenCom();
}

void ThreadController::startCloseCom()
{
    qDebug()<<"singal_startCloseCom()";
    emit singal_startCloseCom();
}

void ThreadController::on_revResult(const QString &str)
{
    qDebug() << str;
}

void ThreadController::on_msgShow(const QString &str)
{
    emit singal_showMeg(str);
}

void ThreadController::on_outputState(bool run)
{
    emit singal_outputState(run);
}

void ThreadController::on_execResult(const bool state){
    qDebug()<<"emit singal_execResult";
    emit singal_execResult(state);
}