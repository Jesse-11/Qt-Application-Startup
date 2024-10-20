/****************************************************************************
** Meta object code from reading C++ file 'appointmentcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/appointmentcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appointmentcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppointmentController_t {
    QByteArrayData data[9];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppointmentController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppointmentController_t qt_meta_stringdata_AppointmentController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AppointmentController"
QT_MOC_LITERAL(1, 22, 24), // "backToDashboardRequested"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 21), // "doctorSearchRequested"
QT_MOC_LITERAL(4, 70, 16), // "loadAppointments"
QT_MOC_LITERAL(5, 87, 23), // "handleRescheduleRequest"
QT_MOC_LITERAL(6, 111, 13), // "appointmentId"
QT_MOC_LITERAL(7, 125, 19), // "handleCancelRequest"
QT_MOC_LITERAL(8, 145, 24) // "handleMakeNewAppointment"

    },
    "AppointmentController\0backToDashboardRequested\0"
    "\0doctorSearchRequested\0loadAppointments\0"
    "handleRescheduleRequest\0appointmentId\0"
    "handleCancelRequest\0handleMakeNewAppointment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppointmentController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void AppointmentController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppointmentController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToDashboardRequested(); break;
        case 1: _t->doctorSearchRequested(); break;
        case 2: _t->loadAppointments(); break;
        case 3: _t->handleRescheduleRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->handleCancelRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->handleMakeNewAppointment(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppointmentController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppointmentController::backToDashboardRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppointmentController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppointmentController::doctorSearchRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppointmentController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppointmentController.data,
    qt_meta_data_AppointmentController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppointmentController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppointmentController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppointmentController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppointmentController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AppointmentController::backToDashboardRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppointmentController::doctorSearchRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
