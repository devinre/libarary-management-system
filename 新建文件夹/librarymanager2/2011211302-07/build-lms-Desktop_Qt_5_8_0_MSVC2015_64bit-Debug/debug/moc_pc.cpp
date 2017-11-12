/****************************************************************************
** Meta object code from reading C++ file 'pc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/pc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pc_t {
    QByteArrayData data[6];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pc_t qt_meta_stringdata_pc = {
    {
QT_MOC_LITERAL(0, 0, 2), // "pc"
QT_MOC_LITERAL(1, 3, 19), // "on_pc_exitb_clicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 20), // "on_pc_clearb_clicked"
QT_MOC_LITERAL(4, 45, 18), // "on_pc_regb_clicked"
QT_MOC_LITERAL(5, 64, 11) // "timerUpDate"

    },
    "pc\0on_pc_exitb_clicked\0\0on_pc_clearb_clicked\0"
    "on_pc_regb_clicked\0timerUpDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pc *_t = static_cast<pc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pc_exitb_clicked(); break;
        case 1: _t->on_pc_clearb_clicked(); break;
        case 2: _t->on_pc_regb_clicked(); break;
        case 3: _t->timerUpDate(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject pc::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pc.data,
      qt_meta_data_pc,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pc::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pc.stringdata0))
        return static_cast<void*>(const_cast< pc*>(this));
    return QDialog::qt_metacast(_clname);
}

int pc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
