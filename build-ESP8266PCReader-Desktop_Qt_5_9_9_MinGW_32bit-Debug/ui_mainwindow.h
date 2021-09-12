/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comChoBox;
    QPushButton *openComBtn;
    QGridLayout *gridLayout_2;
    QPushButton *serComBtn;
    QPushButton *closeBtn;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QPushButton *saveBtn;
    QPushButton *aboutBtn;
    QLabel *label;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *hwChkBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpinBox *hwCycleTime;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CPUvoltChk;
    QCheckBox *MENutiChk;
    QCheckBox *CPUutiChk;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *CPUpkgChk;
    QCheckBox *CPUclkChk;
    QCheckBox *CPUtmpChk;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *GPUutiChk;
    QCheckBox *GPUvoltChk;
    QCheckBox *GPUtmpChk;
    QCheckBox *GPUMCutiChk;
    QGroupBox *groupBox_4;
    QToolButton *picNameBtn;
    QLabel *imgNum;
    QWidget *widget;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *imgShowChk;
    QLabel *imageShow;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *imgLoop;
    QSpinBox *imgLoopTime;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *outputStateLB;
    QCheckBox *autoBox;
    QPushButton *autoSetMsgBtn;
    QLabel *label_4;
    QPushButton *stopBtn;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *minniChk;
    QPushButton *hideBtn;
    QLabel *version;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(394, 627);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(390, 512));
        MainWindow->setMaximumSize(QSize(394, 900));
        MainWindow->setFocusPolicy(Qt::TabFocus);
        MainWindow->setWindowTitle(QStringLiteral("ESP8266_PCReader"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/avatar_hk560.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, -1, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comChoBox = new QComboBox(groupBox_3);
        comChoBox->setObjectName(QStringLiteral("comChoBox"));

        horizontalLayout_3->addWidget(comChoBox);

        openComBtn = new QPushButton(groupBox_3);
        openComBtn->setObjectName(QStringLiteral("openComBtn"));

        horizontalLayout_3->addWidget(openComBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        serComBtn = new QPushButton(groupBox_3);
        serComBtn->setObjectName(QStringLiteral("serComBtn"));

        gridLayout_2->addWidget(serComBtn, 0, 0, 1, 1);

        closeBtn = new QPushButton(groupBox_3);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        gridLayout_2->addWidget(closeBtn, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        saveBtn = new QPushButton(groupBox_3);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));

        verticalLayout_6->addWidget(saveBtn);

        aboutBtn = new QPushButton(groupBox_3);
        aboutBtn->setObjectName(QStringLiteral("aboutBtn"));
        aboutBtn->setMaximumSize(QSize(50, 16777215));
        aboutBtn->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_6->addWidget(aboutBtn);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(3, 0));
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        hwChkBox = new QCheckBox(groupBox);
        hwChkBox->setObjectName(QStringLiteral("hwChkBox"));

        horizontalLayout_7->addWidget(hwChkBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_2);

        hwCycleTime = new QSpinBox(groupBox);
        hwCycleTime->setObjectName(QStringLiteral("hwCycleTime"));
        hwCycleTime->setMinimum(1);
        hwCycleTime->setMaximum(20);

        horizontalLayout_7->addWidget(hwCycleTime);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CPUvoltChk = new QCheckBox(groupBox);
        CPUvoltChk->setObjectName(QStringLiteral("CPUvoltChk"));
        CPUvoltChk->setChecked(false);

        horizontalLayout->addWidget(CPUvoltChk);

        MENutiChk = new QCheckBox(groupBox);
        MENutiChk->setObjectName(QStringLiteral("MENutiChk"));
        MENutiChk->setChecked(false);

        horizontalLayout->addWidget(MENutiChk);

        CPUutiChk = new QCheckBox(groupBox);
        CPUutiChk->setObjectName(QStringLiteral("CPUutiChk"));
        CPUutiChk->setChecked(false);

        horizontalLayout->addWidget(CPUutiChk);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CPUpkgChk = new QCheckBox(groupBox);
        CPUpkgChk->setObjectName(QStringLiteral("CPUpkgChk"));
        CPUpkgChk->setChecked(false);

        horizontalLayout_4->addWidget(CPUpkgChk);

        CPUclkChk = new QCheckBox(groupBox);
        CPUclkChk->setObjectName(QStringLiteral("CPUclkChk"));
        CPUclkChk->setChecked(false);

        horizontalLayout_4->addWidget(CPUclkChk);

        CPUtmpChk = new QCheckBox(groupBox);
        CPUtmpChk->setObjectName(QStringLiteral("CPUtmpChk"));
        CPUtmpChk->setChecked(false);

        horizontalLayout_4->addWidget(CPUtmpChk);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        GPUutiChk = new QCheckBox(groupBox);
        GPUutiChk->setObjectName(QStringLiteral("GPUutiChk"));
        GPUutiChk->setChecked(false);

        horizontalLayout_6->addWidget(GPUutiChk);

        GPUvoltChk = new QCheckBox(groupBox);
        GPUvoltChk->setObjectName(QStringLiteral("GPUvoltChk"));
        GPUvoltChk->setChecked(false);

        horizontalLayout_6->addWidget(GPUvoltChk);

        GPUtmpChk = new QCheckBox(groupBox);
        GPUtmpChk->setObjectName(QStringLiteral("GPUtmpChk"));
        GPUtmpChk->setChecked(false);

        horizontalLayout_6->addWidget(GPUtmpChk);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout);

        GPUMCutiChk = new QCheckBox(groupBox);
        GPUMCutiChk->setObjectName(QStringLiteral("GPUMCutiChk"));
        GPUMCutiChk->setChecked(false);

        verticalLayout_3->addWidget(GPUMCutiChk);


        verticalLayout_8->addWidget(groupBox);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setMinimumSize(QSize(0, 71));
        picNameBtn = new QToolButton(groupBox_4);
        picNameBtn->setObjectName(QStringLiteral("picNameBtn"));
        picNameBtn->setGeometry(QRect(220, 40, 71, 20));
        imgNum = new QLabel(groupBox_4);
        imgNum->setObjectName(QStringLiteral("imgNum"));
        imgNum->setGeometry(QRect(230, 70, 54, 12));
        widget = new QWidget(groupBox_4);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 130, 90));
        verticalLayout_9 = new QVBoxLayout(widget);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        imgShowChk = new QCheckBox(widget);
        imgShowChk->setObjectName(QStringLiteral("imgShowChk"));

        verticalLayout_9->addWidget(imgShowChk);

        imageShow = new QLabel(widget);
        imageShow->setObjectName(QStringLiteral("imageShow"));
        imageShow->setMinimumSize(QSize(128, 64));
        imageShow->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(imageShow);

        widget1 = new QWidget(groupBox_4);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(200, 100, 96, 25));
        horizontalLayout_8 = new QHBoxLayout(widget1);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        imgLoop = new QLabel(widget1);
        imgLoop->setObjectName(QStringLiteral("imgLoop"));

        horizontalLayout_8->addWidget(imgLoop);

        imgLoopTime = new QSpinBox(widget1);
        imgLoopTime->setObjectName(QStringLiteral("imgLoopTime"));
        imgLoopTime->setMinimum(1);
        imgLoopTime->setMaximum(20);

        horizontalLayout_8->addWidget(imgLoopTime);


        verticalLayout_8->addWidget(groupBox_4);


        verticalLayout_4->addWidget(groupBox_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        outputStateLB = new QLabel(centralwidget);
        outputStateLB->setObjectName(QStringLiteral("outputStateLB"));
        outputStateLB->setMinimumSize(QSize(60, 32));
        outputStateLB->setLayoutDirection(Qt::LeftToRight);
        outputStateLB->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(outputStateLB, 0, 2, 1, 1);

        autoBox = new QCheckBox(centralwidget);
        autoBox->setObjectName(QStringLiteral("autoBox"));

        gridLayout->addWidget(autoBox, 0, 3, 1, 1);

        autoSetMsgBtn = new QPushButton(centralwidget);
        autoSetMsgBtn->setObjectName(QStringLiteral("autoSetMsgBtn"));
        autoSetMsgBtn->setMinimumSize(QSize(40, 40));
        autoSetMsgBtn->setMaximumSize(QSize(50, 16777215));
        autoSetMsgBtn->setAutoRepeatDelay(300);

        gridLayout->addWidget(autoSetMsgBtn, 0, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setMinimumSize(QSize(40, 40));

        gridLayout->addWidget(stopBtn, 0, 5, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        minniChk = new QCheckBox(centralwidget);
        minniChk->setObjectName(QStringLiteral("minniChk"));

        horizontalLayout_5->addWidget(minniChk);

        hideBtn = new QPushButton(centralwidget);
        hideBtn->setObjectName(QStringLiteral("hideBtn"));
        hideBtn->setMinimumSize(QSize(0, 22));

        horizontalLayout_5->addWidget(hideBtn);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_5);

        version = new QLabel(centralwidget);
        version->setObjectName(QStringLiteral("version"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(version->sizePolicy().hasHeightForWidth());
        version->setSizePolicy(sizePolicy3);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(7);
        version->setFont(font);
        version->setTextFormat(Qt::AutoText);
        version->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(version);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 394, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        openComBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        serComBtn->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        saveBtn->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", Q_NULLPTR));
        aboutBtn->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205:HK560", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\256\276\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\241\254\344\273\266\344\277\241\346\201\257", Q_NULLPTR));
        hwChkBox->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\241\254\344\273\266\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\254\241\346\225\260", Q_NULLPTR));
        CPUvoltChk->setText(QApplication::translate("MainWindow", "CPU\347\224\265\345\216\213", Q_NULLPTR));
        MENutiChk->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\344\275\277\347\224\250\347\216\207", Q_NULLPTR));
        CPUutiChk->setText(QApplication::translate("MainWindow", "CPU\344\275\277\347\224\250\347\216\207", Q_NULLPTR));
        CPUpkgChk->setText(QApplication::translate("MainWindow", "CPU\345\212\237\350\200\227", Q_NULLPTR));
        CPUclkChk->setText(QApplication::translate("MainWindow", "CPU\351\242\221\347\216\207", Q_NULLPTR));
        CPUtmpChk->setText(QApplication::translate("MainWindow", "CPU\346\270\251\345\272\246", Q_NULLPTR));
        GPUutiChk->setText(QApplication::translate("MainWindow", "GPU\344\275\277\347\224\250\347\216\207", Q_NULLPTR));
        GPUvoltChk->setText(QApplication::translate("MainWindow", "GPU\347\224\265\345\216\213", Q_NULLPTR));
        GPUtmpChk->setText(QApplication::translate("MainWindow", "GPU\346\270\251\345\272\246", Q_NULLPTR));
        GPUMCutiChk->setText(QApplication::translate("MainWindow", "GPU\346\230\276\345\255\230\344\275\277\347\224\250\347\216\207", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\345\212\250\347\224\273/\345\233\276\347\211\207", Q_NULLPTR));
        picNameBtn->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", Q_NULLPTR));
        imgNum->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\225\260:", Q_NULLPTR));
        imgShowChk->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\212\250\347\224\273/\345\233\276\347\211\207", Q_NULLPTR));
        imageShow->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\351\242\204\350\247\210", Q_NULLPTR));
        imgLoop->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\254\241\346\225\260", Q_NULLPTR));
        outputStateLB->setText(QApplication::translate("MainWindow", "(\302\264\357\275\260\342\210\200\357\275\260`)", Q_NULLPTR));
        autoBox->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\350\277\220\350\241\214\345\220\216\350\207\252\345\212\250\345\220\257\345\212\250", Q_NULLPTR));
        autoSetMsgBtn->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201:", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        minniChk->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\351\273\230\350\256\244\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        hideBtn->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        version->setText(QApplication::translate("MainWindow", "ESP8266_PCReader 0.1(2104151241)", Q_NULLPTR));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
