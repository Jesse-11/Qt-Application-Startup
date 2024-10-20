/****************************************************************************
** Meta object code from reading C++ file 'doctorsearchcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/doctorsearchcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctorsearchcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorSearchController_t {
    QByteArrayData data[8];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoctorSearchController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoctorSearchController_t qt_meta_stringdata_DoctorSearchController = {
    {
QT_MOC_LITERAL(0, 0, 22), // "DoctorSearchController"
QT_MOC_LITERAL(1, 23, 24), // "backToDashboardRequested"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 32), // "appointmentConfirmationRequested"
QT_MOC_LITERAL(4, 82, 6), // "doctor"
QT_MOC_LITERAL(5, 89, 4), // "date"
QT_MOC_LITERAL(6, 94, 4), // "time"
QT_MOC_LITERAL(7, 99, 22) // "onAppointmentConfirmed"

    },
    "DoctorSearchController\0backToDashboardRequested\0"
    "\0appointmentConfirmationRequested\0"
    "doctor\0date\0time\0onAppointmentConfirmed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorSearchController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    3,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QDate, QMetaType::QString,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate, QMetaType::QString,    4,    5,    6,

       0        // eod
};

void DoctorSearchController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoctorSearchController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToDashboardRequested(); break;
        case 1: _t->appointmentConfirmationRequested((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->onAppointmentConfirmed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoctorSearchController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorSearchController::backToDashboardRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DoctorSearchController::*)(const QString & , const QDate & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorSearchController::appointmentConfirmationRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DoctorSearchController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DoctorSearchController.data,
    qt_meta_data_DoctorSearchController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DoctorSearchController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorSearchController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorSearchController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DoctorSearchController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void DoctorSearchController::backToDashboardRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DoctorSearchController::appointmentConfirmationRequested(const QString & _t1, const QDate & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
