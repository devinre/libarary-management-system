/****************************************************************************
** Meta object code from reading C++ file 'reader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/reader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reader_t {
    QByteArrayData data[13];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_reader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_reader_t qt_meta_stringdata_reader = {
    {
QT_MOC_LITERAL(0, 0, 6), // "reader"
QT_MOC_LITERAL(1, 7, 14), // "on_rpc_clicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "on_rexit_clicked"
QT_MOC_LITERAL(4, 40, 20), // "on_lastpage1_clicked"
QT_MOC_LITERAL(5, 61, 20), // "on_nextpage1_clicked"
QT_MOC_LITERAL(6, 82, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 104, 15), // "on_seek_clicked"
QT_MOC_LITERAL(8, 120, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 144, 18), // "on_reinput_clicked"
QT_MOC_LITERAL(10, 163, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(11, 187, 11), // "timerUpDate"
QT_MOC_LITERAL(12, 199, 10) // "timerStart"

    },
    "reader\0on_rpc_clicked\0\0on_rexit_clicked\0"
    "on_lastpage1_clicked\0on_nextpage1_clicked\0"
    "on_pushButton_clicked\0on_seek_clicked\0"
    "on_pushButton_2_clicked\0on_reinput_clicked\0"
    "on_pushButton_4_clicked\0timerUpDate\0"
    "timerStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void reader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        reader *_t = static_cast<reader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_rpc_clicked(); break;
        case 1: _t->on_rexit_clicked(); break;
        case 2: _t->on_lastpage1_clicked(); break;
        case 3: _t->on_nextpage1_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_seek_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_reinput_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        case 9: _t->timerUpDate(); break;
        case 10: _t->timerStart(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject reader::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_reader.data,
      qt_meta_data_reader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *reader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_reader.stringdata0))
        return static_cast<void*>(const_cast< reader*>(this));
    return QDialog::qt_metacast(_clname);
}

int reader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
