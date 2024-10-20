/****************************************************************************
** Meta object code from reading C++ file 'dashboardview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/view/dashboardview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboardview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DashboardView_t {
    QByteArrayData data[9];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DashboardView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DashboardView_t qt_meta_stringdata_DashboardView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DashboardView"
QT_MOC_LITERAL(1, 14, 24), // "startConsultationClicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "accessProfileClicked"
QT_MOC_LITERAL(4, 61, 22), // "bookAppointmentClicked"
QT_MOC_LITERAL(5, 84, 18), // "viewRecordsClicked"
QT_MOC_LITERAL(6, 103, 25), // "refillPrescriptionClicked"
QT_MOC_LITERAL(7, 129, 24), // "languageSelectionClicked"
QT_MOC_LITERAL(8, 154, 21) // "languageButtonClicked"

    },
    "DashboardView\0startConsultationClicked\0"
    "\0accessProfileClicked\0bookAppointmentClicked\0"
    "viewRecordsClicked\0refillPrescriptionClicked\0"
    "languageSelectionClicked\0languageButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DashboardView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DashboardView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DashboardView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startConsultationClicked(); break;
        case 1: _t->accessProfileClicked(); break;
        case 2: _t->bookAppointmentClicked(); break;
        case 3: _t->viewRecordsClicked(); break;
        case 4: _t->refillPrescriptionClicked(); break;
        case 5: _t->languageSelectionClicked(); break;
        case 6: _t->languageButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::startConsultationClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::accessProfileClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::bookAppointmentClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::viewRecordsClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::refillPrescriptionClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::languageSelectionClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DashboardView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DashboardView::languageButtonClicked)) {
                *result = 6;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DashboardView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DashboardView.data,
    qt_meta_data_DashboardView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DashboardView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashboardView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DashboardView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DashboardView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DashboardView::startConsultationClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DashboardView::accessProfileClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DashboardView::bookAppointmentClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DashboardView::viewRecordsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DashboardView::refillPrescriptionClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DashboardView::languageSelectionClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DashboardView::languageButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
