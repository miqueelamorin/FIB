/****************************************************************************
** Meta object code from reading C++ file 'MyQLCDNumber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "MyQLCDNumber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQLCDNumber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyQLCDNumber_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQLCDNumber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQLCDNumber_t qt_meta_stringdata_MyQLCDNumber = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyQLCDNumber"
QT_MOC_LITERAL(1, 13, 18), // "actualitzar_record"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "record"
QT_MOC_LITERAL(4, 40, 11), // "color_temps"
QT_MOC_LITERAL(5, 52, 5), // "color"
QT_MOC_LITERAL(6, 58, 15), // "iniciar_i_parar"
QT_MOC_LITERAL(7, 74, 9), // "restaurar"
QT_MOC_LITERAL(8, 84, 13) // "mostrar_temps"

    },
    "MyQLCDNumber\0actualitzar_record\0\0"
    "record\0color_temps\0color\0iniciar_i_parar\0"
    "restaurar\0mostrar_temps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQLCDNumber[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyQLCDNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyQLCDNumber *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->actualitzar_record((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->color_temps((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->iniciar_i_parar(); break;
        case 3: _t->restaurar(); break;
        case 4: _t->mostrar_temps(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyQLCDNumber::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyQLCDNumber::actualitzar_record)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyQLCDNumber::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyQLCDNumber::color_temps)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyQLCDNumber::staticMetaObject = { {
    QMetaObject::SuperData::link<QLCDNumber::staticMetaObject>(),
    qt_meta_stringdata_MyQLCDNumber.data,
    qt_meta_data_MyQLCDNumber,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyQLCDNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQLCDNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyQLCDNumber.stringdata0))
        return static_cast<void*>(this);
    return QLCDNumber::qt_metacast(_clname);
}

int MyQLCDNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCDNumber::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyQLCDNumber::actualitzar_record(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyQLCDNumber::color_temps(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
