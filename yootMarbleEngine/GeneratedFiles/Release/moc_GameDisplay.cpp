/****************************************************************************
** Meta object code from reading C++ file 'GameDisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameDisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameDisplay_t {
    QByteArrayData data[24];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameDisplay_t qt_meta_stringdata_GameDisplay = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GameDisplay"
QT_MOC_LITERAL(1, 12, 13), // "selectAndMove"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "updateGame"
QT_MOC_LITERAL(4, 38, 7), // "newGame"
QT_MOC_LITERAL(5, 46, 11), // "unitePieces"
QT_MOC_LITERAL(6, 58, 10), // "movePieces"
QT_MOC_LITERAL(7, 69, 11), // "resetPieces"
QT_MOC_LITERAL(8, 81, 8), // "isCaught"
QT_MOC_LITERAL(9, 90, 7), // "stealHP"
QT_MOC_LITERAL(10, 98, 6), // "damage"
QT_MOC_LITERAL(11, 105, 12), // "explainSpace"
QT_MOC_LITERAL(12, 118, 8), // "position"
QT_MOC_LITERAL(13, 127, 11), // "Piece1_num1"
QT_MOC_LITERAL(14, 139, 11), // "Piece1_num2"
QT_MOC_LITERAL(15, 151, 11), // "Piece1_num3"
QT_MOC_LITERAL(16, 163, 11), // "Piece2_num1"
QT_MOC_LITERAL(17, 175, 11), // "Piece2_num2"
QT_MOC_LITERAL(18, 187, 11), // "Piece2_num3"
QT_MOC_LITERAL(19, 199, 9), // "StartGame"
QT_MOC_LITERAL(20, 209, 11), // "ExplainGame"
QT_MOC_LITERAL(21, 221, 8), // "ExitGame"
QT_MOC_LITERAL(22, 230, 7), // "showPre"
QT_MOC_LITERAL(23, 238, 8) // "showNext"

    },
    "GameDisplay\0selectAndMove\0\0updateGame\0"
    "newGame\0unitePieces\0movePieces\0"
    "resetPieces\0isCaught\0stealHP\0damage\0"
    "explainSpace\0position\0Piece1_num1\0"
    "Piece1_num2\0Piece1_num3\0Piece2_num1\0"
    "Piece2_num2\0Piece2_num3\0StartGame\0"
    "ExplainGame\0ExitGame\0showPre\0showNext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    1,  114,    2, 0x08 /* Private */,
       9,    1,  117,    2, 0x08 /* Private */,
      11,    1,  120,    2, 0x08 /* Private */,
      13,    0,  123,    2, 0x08 /* Private */,
      14,    0,  124,    2, 0x08 /* Private */,
      15,    0,  125,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    0,  129,    2, 0x08 /* Private */,
      20,    0,  130,    2, 0x08 /* Private */,
      21,    0,  131,    2, 0x08 /* Private */,
      22,    0,  132,    2, 0x08 /* Private */,
      23,    0,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameDisplay *_t = static_cast<GameDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectAndMove(); break;
        case 1: _t->updateGame(); break;
        case 2: _t->newGame(); break;
        case 3: _t->unitePieces(); break;
        case 4: _t->movePieces(); break;
        case 5: _t->resetPieces((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->stealHP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->explainSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->Piece1_num1(); break;
        case 9: _t->Piece1_num2(); break;
        case 10: _t->Piece1_num3(); break;
        case 11: _t->Piece2_num1(); break;
        case 12: _t->Piece2_num2(); break;
        case 13: _t->Piece2_num3(); break;
        case 14: _t->StartGame(); break;
        case 15: _t->ExplainGame(); break;
        case 16: _t->ExitGame(); break;
        case 17: _t->showPre(); break;
        case 18: _t->showNext(); break;
        default: ;
        }
    }
}

const QMetaObject GameDisplay::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GameDisplay.data,
      qt_meta_data_GameDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameDisplay.stringdata0))
        return static_cast<void*>(const_cast< GameDisplay*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GameDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
