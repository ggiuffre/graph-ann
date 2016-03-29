/****************************************************************************
** Meta object code from reading C++ file 'nets_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nets_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nets_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nets_list_t {
    QByteArrayData data[7];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nets_list_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nets_list_t qt_meta_stringdata_nets_list = {
    {
QT_MOC_LITERAL(0, 0, 9), // "nets_list"
QT_MOC_LITERAL(1, 10, 11), // "NetSelected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "t"
QT_MOC_LITERAL(4, 25, 10), // "NetClicked"
QT_MOC_LITERAL(5, 36, 1), // "i"
QT_MOC_LITERAL(6, 38, 5) // "prova"

    },
    "nets_list\0NetSelected\0\0t\0NetClicked\0"
    "i\0prova"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nets_list[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void nets_list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nets_list *_t = static_cast<nets_list *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NetSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->NetClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->prova((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (nets_list::*_t)(QString ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nets_list::NetSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject nets_list::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_nets_list.data,
      qt_meta_data_nets_list,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nets_list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nets_list::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nets_list.stringdata0))
        return static_cast<void*>(const_cast< nets_list*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int nets_list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void nets_list::NetSelected(QString _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< nets_list *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
