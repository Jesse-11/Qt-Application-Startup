/****************************************************************************
** Meta object code from reading C++ file 'confirmappointmentcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/confirmappointmentcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confirmappointmentcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfirmAppointmentController_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfirmAppointmentController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfirmAppointmentController_t qt_meta_stringdata_ConfirmAppointmentController = {
    {
QT_MOC_LITERAL(0, 0, 28), // "ConfirmAppointmentController"
QT_MOC_LITERAL(1, 29, 20), // "appointmentConfirmed"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 20), // "appointmentCancelled"
QT_MOC_LITERAL(4, 72, 21), // "setAppointmentDetails"
QT_MOC_LITERAL(5, 94, 6), // "doctor"
QT_MOC_LITERAL(6, 101, 4), // "date"
QT_MOC_LITERAL(7, 106, 4), // "time"
QT_MOC_LITERAL(8, 111, 16), // "onConfirmClicked"
QT_MOC_LITERAL(9, 128, 15) // "onCancelClicked"

    },
    "ConfirmAppointmentController\0"
    "appointmentConfirmed\0\0appointmentCancelled\0"
    "setAppointmentDetails\0doctor\0date\0"
    "time\0onConfirmClicked\0onCancelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfirmAppointmentController[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   41,    2, 0x0a /* Public */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate, QMetaType::QString,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfirmAppointmentController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfirmAppointmentController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appointmentConfirmed(); break;
        case 1: _t->appointmentCancelled(); break;
        case 2: _t->setAppointmentDetails((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->onConfirmClicked(); break;
        case 4: _t->onCancelClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConfirmAppointmentController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfirmAppointmentController::appointmentConfirmed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConfirmAppointmentController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfirmAppointmentController::appointmentCancelled)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfirmAppointmentController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ConfirmAppointmentController.data,
    qt_meta_data_ConfirmAppointmentController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConfirmAppointmentController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfirmAppointmentController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmAppointmentController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConfirmAppointmentController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ConfirmAppointmentController::appointmentConfirmed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConfirmAppointmentController::appointmentCancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
