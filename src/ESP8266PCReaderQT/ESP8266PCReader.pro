QT       += core gui
QT       += serialport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_FILE = res/res.rc

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/aida64readerforesp8266.cpp \
    src/binarization.cpp \
    src/config.cpp \
    src/dataoutputthread.cpp \
    src/imageinfo.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/threadController.cpp


HEADERS += \
    include/aida64readerforesp8266.h \
    include/binarization.h \
    include/config.h \
    include/dataoutputthread.h \
    include/imageinfo.h \
    include/mainwindow.h \
    include/threadController.h


FORMS += \
    form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/src.qrc

DISTFILES += \
    res/style.qss

