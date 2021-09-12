/****************************************************************************
** Meta object code from reading C++ file 'threadController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ESP8266PCReaderQTSourceCode/threadController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadController_t {
    QByteArrayData data[12];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadController_t qt_meta_stringdata_ThreadController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ThreadController"
QT_MOC_LITERAL(1, 17, 22), // "singal_startOutputData"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "singal_startOpenCom"
QT_MOC_LITERAL(4, 61, 20), // "singal_startCloseCom"
QT_MOC_LITERAL(5, 82, 14), // "singal_showMeg"
QT_MOC_LITERAL(6, 97, 3), // "str"
QT_MOC_LITERAL(7, 101, 18), // "singal_outputState"
QT_MOC_LITERAL(8, 120, 3), // "run"
QT_MOC_LITERAL(9, 124, 12), // "on_revResult"
QT_MOC_LITERAL(10, 137, 10), // "on_msgShow"
QT_MOC_LITERAL(11, 148, 14) // "on_outputState"

    },
    "ThreadController\0singal_startOutputData\0"
    "\0singal_startOpenCom\0singal_startCloseCom\0"
    "singal_showMeg\0str\0singal_outputState\0"
    "run\0on_revResult\0on_msgShow\0on_outputState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   63,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void ThreadController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadController *_t = static_cast<ThreadController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->singal_startOutputData(); break;
        case 1: _t->singal_startOpenCom(); break;
        case 2: _t->singal_startCloseCom(); break;
        case 3: _t->singal_showMeg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->singal_outputState((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->on_revResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_msgShow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_outputState((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ThreadController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadController::singal_startOutputData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadController::singal_startOpenCom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ThreadController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadController::singal_startCloseCom)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ThreadController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadController::singal_showMeg)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ThreadController::*_t)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadController::singal_outputState)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ThreadController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadController.data,
      qt_meta_data_ThreadController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThreadController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ThreadController::singal_startOutputData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadController::singal_startOpenCom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ThreadController::singal_startCloseCom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ThreadController::singal_showMeg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadController::singal_outputState(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
