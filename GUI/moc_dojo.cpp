/****************************************************************************
** Meta object code from reading C++ file 'dojo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dojo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dojo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dojo_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dojo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dojo_t qt_meta_stringdata_dojo = {
    {
QT_MOC_LITERAL(0, 0, 4), // "dojo"
QT_MOC_LITERAL(1, 5, 10), // "netBuilder"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "netTrainer"
QT_MOC_LITERAL(4, 28, 9), // "netRunner"
QT_MOC_LITERAL(5, 38, 5), // "title"
QT_MOC_LITERAL(6, 44, 6) // "addNet"

    },
    "dojo\0netBuilder\0\0netTrainer\0netRunner\0"
    "title\0addNet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dojo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    1,   41,    2, 0x09 /* Protected */,
       4,    0,   44,    2, 0x29 /* Protected | MethodCloned */,
       6,    0,   45,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dojo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dojo *_t = static_cast<dojo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->netBuilder(); break;
        case 1: _t->netTrainer(); break;
        case 2: _t->netRunner((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->netRunner(); break;
        case 4: _t->addNet(); break;
        default: ;
        }
    }
}

const QMetaObject dojo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_dojo.data,
      qt_meta_data_dojo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dojo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dojo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dojo.stringdata0))
        return static_cast<void*>(const_cast< dojo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int dojo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
