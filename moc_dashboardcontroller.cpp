/****************************************************************************
** Meta object code from reading C++ file 'dashboardcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/controller/dashboardcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboardcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DashboardController_t {
    QByteArrayData data[12];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DashboardController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DashboardController_t qt_meta_stringdata_DashboardController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DashboardController"
QT_MOC_LITERAL(1, 20, 22), // "prescriptionsRequested"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 21), // "telemedicineRequested"
QT_MOC_LITERAL(4, 66, 20), // "appointmentRequested"
QT_MOC_LITERAL(5, 87, 26), // "languageSelectionRequested"
QT_MOC_LITERAL(6, 114, 26), // "onStartConsultationClicked"
QT_MOC_LITERAL(7, 141, 22), // "onAccessProfileClicked"
QT_MOC_LITERAL(8, 164, 24), // "onBookAppointmentClicked"
QT_MOC_LITERAL(9, 189, 20), // "onViewRecordsClicked"
QT_MOC_LITERAL(10, 210, 27), // "onRefillPrescriptionClicked"
QT_MOC_LITERAL(11, 238, 23) // "onLanguageButtonClicked"

    },
    "DashboardController\0prescriptionsRequested\0"
    "\0telemedicineRequested\0appointmentRequested\0"
    "languageSelectionRequested\0"
    "onStartConsultationClicked\0"
    "onAccessProfileClicked\0onBookAppointmentClicked\0"
    "onViewRecordsClicked\0onRefillPrescriptionClicked\0"
    "onLanguageButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DashboardController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DashboardController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DashboardController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->prescriptionsRequested(); break;
        case 1: _t->telemedicineRequested(); break;
        case 2: _t->appointmentRequested(); break;
        case 3: _t->languageSelectionRequested(); break;
        case 4: _t->onStartConsultationClicked(); break;
        case 5: _t->onAccessProfileClicked(); break;
        case 6: _t->onBookAppointmentClicked(); break;
        case 7: _t->onViewRecordsClicked(); break;
        case 8: _t->onRefillPrescriptionClicked(); break;
        case 9: _t->onLanguageButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DashboardController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardController::prescriptionsRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DashboardController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardController::telemedicineRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DashboardController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardController::appointmentRequested)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DashboardController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardController::languageSelectionRequested)) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DashboardController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DashboardController.data,
    qt_meta_data_DashboardController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DashboardController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashboardController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DashboardController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DashboardController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DashboardController::prescriptionsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DashboardController::telemedicineRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DashboardController::appointmentRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DashboardController::languageSelectionRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
