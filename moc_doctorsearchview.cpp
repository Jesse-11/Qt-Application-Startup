/****************************************************************************
** Meta object code from reading C++ file 'doctorsearchview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/view/doctorsearchview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctorsearchview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorSearchView_t {
    QByteArrayData data[12];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoctorSearchView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoctorSearchView_t qt_meta_stringdata_DoctorSearchView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DoctorSearchView"
QT_MOC_LITERAL(1, 17, 15), // "backToDashboard"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "appointmentConfirmed"
QT_MOC_LITERAL(4, 55, 6), // "doctor"
QT_MOC_LITERAL(5, 62, 4), // "date"
QT_MOC_LITERAL(6, 67, 4), // "time"
QT_MOC_LITERAL(7, 72, 24), // "onDoctorSelectionChanged"
QT_MOC_LITERAL(8, 97, 5), // "index"
QT_MOC_LITERAL(9, 103, 13), // "onDateChanged"
QT_MOC_LITERAL(10, 117, 17), // "onTimeSlotClicked"
QT_MOC_LITERAL(11, 135, 16) // "onConfirmClicked"

    },
    "DoctorSearchView\0backToDashboard\0\0"
    "appointmentConfirmed\0doctor\0date\0time\0"
    "onDoctorSelectionChanged\0index\0"
    "onDateChanged\0onTimeSlotClicked\0"
    "onConfirmClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorSearchView[] = {

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
       3,    3,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   52,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,
      10,    0,   56,    2, 0x08 /* Private */,
      11,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QDate, QMetaType::QString,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DoctorSearchView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoctorSearchView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToDashboard(); break;
        case 1: _t->appointmentConfirmed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->onDoctorSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onDateChanged(); break;
        case 4: _t->onTimeSlotClicked(); break;
        case 5: _t->onConfirmClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoctorSearchView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorSearchView::backToDashboard)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DoctorSearchView::*)(const QString & , const QDate & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorSearchView::appointmentConfirmed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DoctorSearchView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DoctorSearchView.data,
    qt_meta_data_DoctorSearchView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DoctorSearchView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorSearchView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorSearchView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DoctorSearchView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void DoctorSearchView::backToDashboard()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DoctorSearchView::appointmentConfirmed(const QString & _t1, const QDate & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
