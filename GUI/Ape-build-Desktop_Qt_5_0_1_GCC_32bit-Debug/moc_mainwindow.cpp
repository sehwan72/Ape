/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ape/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 22),
QT_MOC_LITERAL(4, 44, 9),
QT_MOC_LITERAL(5, 54, 13),
QT_MOC_LITERAL(6, 68, 17),
QT_MOC_LITERAL(7, 86, 9),
QT_MOC_LITERAL(8, 96, 13),
QT_MOC_LITERAL(9, 110, 8),
QT_MOC_LITERAL(10, 119, 24),
QT_MOC_LITERAL(11, 144, 23),
QT_MOC_LITERAL(12, 168, 23),
QT_MOC_LITERAL(13, 192, 24),
QT_MOC_LITERAL(14, 217, 24),
QT_MOC_LITERAL(15, 242, 24),
QT_MOC_LITERAL(16, 267, 25)
    },
    "MainWindow\0updateUI\0\0showProcessContextMenu\0"
    "sortTable\0doubleClicked\0QTableWidgetItem*\0"
    "toggleCmd\0handleMenuBar\0QAction*\0"
    "on_sigkillButton_clicked\0"
    "on_memmapButton_clicked\0on_sigintButton_clicked\0"
    "on_sigtermButton_clicked\0"
    "on_sigstopButton_clicked\0"
    "on_sendsigButton_clicked\0"
    "on_coredumpButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08,
       3,    1,   80,    2, 0x08,
       4,    1,   83,    2, 0x08,
       5,    1,   86,    2, 0x08,
       7,    0,   89,    2, 0x08,
       8,    1,   90,    2, 0x08,
      10,    0,   93,    2, 0x08,
      11,    0,   94,    2, 0x08,
      12,    0,   95,    2, 0x08,
      13,    0,   96,    2, 0x08,
      14,    0,   97,    2, 0x08,
      15,    0,   98,    2, 0x08,
      16,    0,   99,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateUI(); break;
        case 1: _t->showProcessContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->sortTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->doubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->toggleCmd(); break;
        case 5: _t->handleMenuBar((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->on_sigkillButton_clicked(); break;
        case 7: _t->on_memmapButton_clicked(); break;
        case 8: _t->on_sigintButton_clicked(); break;
        case 9: _t->on_sigtermButton_clicked(); break;
        case 10: _t->on_sigstopButton_clicked(); break;
        case 11: _t->on_sendsigButton_clicked(); break;
        case 12: _t->on_coredumpButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
