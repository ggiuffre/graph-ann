/****************************************************************************
** Meta object code from reading C++ file 'palestra.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "palestra.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'palestra.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_palestra_t {
    QByteArrayData data[10];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_palestra_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_palestra_t qt_meta_stringdata_palestra = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 10),
QT_MOC_LITERAL(4, 32, 9),
QT_MOC_LITERAL(5, 42, 1),
QT_MOC_LITERAL(6, 44, 11),
QT_MOC_LITERAL(7, 56, 6),
QT_MOC_LITERAL(8, 63, 17),
QT_MOC_LITERAL(9, 81, 7)
    },
    "palestra\0netBuilder\0\0netTrainer\0"
    "netRunner\0t\0dataBuilder\0addNet\0"
    "layeredBiasedNet*\0new_net"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_palestra[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void palestra::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        palestra *_t = static_cast<palestra *>(_o);
        switch (_id) {
        case 0: _t->netBuilder(); break;
        case 1: _t->netTrainer(); break;
        case 2: _t->netRunner((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dataBuilder(); break;
        case 4: _t->addNet((*reinterpret_cast< layeredBiasedNet*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject palestra::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_palestra.data,
      qt_meta_data_palestra,  qt_static_metacall, 0, 0}
};


const QMetaObject *palestra::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *palestra::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_palestra.stringdata))
        return static_cast<void*>(const_cast< palestra*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int palestra::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
