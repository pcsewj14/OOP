/****************************************************************************
** Meta object code from reading C++ file 'User.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../User.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'User.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_User_t {
    QByteArrayData data[22];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_User_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_User_t qt_meta_stringdata_User = {
    {
QT_MOC_LITERAL(0, 0, 4), // "User"
QT_MOC_LITERAL(1, 5, 6), // "thrown"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 11), // "uniteSignal"
QT_MOC_LITERAL(4, 25, 11), // "caughtPiece"
QT_MOC_LITERAL(5, 37, 8), // "isCaught"
QT_MOC_LITERAL(6, 46, 6), // "lostHP"
QT_MOC_LITERAL(7, 53, 6), // "damage"
QT_MOC_LITERAL(8, 60, 3), // "die"
QT_MOC_LITERAL(9, 64, 13), // "updateDisplay"
QT_MOC_LITERAL(10, 78, 11), // "debugSignal"
QT_MOC_LITERAL(11, 90, 9), // "movePiece"
QT_MOC_LITERAL(12, 100, 1), // "i"
QT_MOC_LITERAL(13, 102, 8), // "buySpace"
QT_MOC_LITERAL(14, 111, 10), // "stealSpace"
QT_MOC_LITERAL(15, 122, 9), // "donothing"
QT_MOC_LITERAL(16, 132, 7), // "confirm"
QT_MOC_LITERAL(17, 140, 8), // "confirm1"
QT_MOC_LITERAL(18, 149, 10), // "dieconfirm"
QT_MOC_LITERAL(19, 160, 9), // "keyEffect"
QT_MOC_LITERAL(20, 170, 12), // "HackathonDie"
QT_MOC_LITERAL(21, 183, 14) // "PostechConfirm"

    },
    "User\0thrown\0\0uniteSignal\0caughtPiece\0"
    "isCaught\0lostHP\0damage\0die\0updateDisplay\0"
    "debugSignal\0movePiece\0i\0buySpace\0"
    "stealSpace\0donothing\0confirm\0confirm1\0"
    "dieconfirm\0keyEffect\0HackathonDie\0"
    "PostechConfirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    1,  101,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       8,    1,  107,    2, 0x06 /* Public */,
       9,    0,  110,    2, 0x06 /* Public */,
      10,    0,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  112,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
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

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        User *_t = static_cast<User *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thrown(); break;
        case 1: _t->uniteSignal(); break;
        case 2: _t->caughtPiece((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->lostHP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->die((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->updateDisplay(); break;
        case 6: _t->debugSignal(); break;
        case 7: _t->movePiece((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->buySpace(); break;
        case 9: _t->stealSpace(); break;
        case 10: _t->donothing(); break;
        case 11: _t->confirm(); break;
        case 12: _t->confirm1(); break;
        case 13: _t->dieconfirm(); break;
        case 14: _t->keyEffect(); break;
        case 15: _t->HackathonDie(); break;
        case 16: _t->PostechConfirm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::thrown)) {
                *result = 0;
            }
        }
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::uniteSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (User::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::caughtPiece)) {
                *result = 2;
            }
        }
        {
            typedef void (User::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::lostHP)) {
                *result = 3;
            }
        }
        {
            typedef void (User::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::die)) {
                *result = 4;
            }
        }
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::updateDisplay)) {
                *result = 5;
            }
        }
        {
            typedef void (User::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&User::debugSignal)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject User::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_User.data,
      qt_meta_data_User,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_User.stringdata0))
        return static_cast<void*>(const_cast< User*>(this));
    return QObject::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void User::thrown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void User::uniteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void User::caughtPiece(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void User::lostHP(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void User::die(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void User::updateDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void User::debugSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
