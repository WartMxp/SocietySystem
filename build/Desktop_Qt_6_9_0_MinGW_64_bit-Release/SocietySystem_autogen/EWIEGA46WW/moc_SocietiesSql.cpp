/****************************************************************************
** Meta object code from reading C++ file 'SocietiesSql.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SocietiesSql.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocietiesSql.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12SocietiesSqlE_t {};
} // unnamed namespace

template <> constexpr inline auto SocietiesSql::qt_create_metaobjectdata<qt_meta_tag_ZN12SocietiesSqlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SocietiesSql",
        "studentAdded",
        "",
        "stuInfo",
        "student",
        "societyAdded",
        "socInfo",
        "society",
        "memberAdded",
        "socMemInfo",
        "member",
        "activityAdded",
        "actInfo",
        "activity",
        "participantsAdded",
        "actPtpInfo",
        "participant"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'studentAdded'
        QtMocHelpers::SignalData<void(const stuInfo &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'societyAdded'
        QtMocHelpers::SignalData<void(const socInfo &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'memberAdded'
        QtMocHelpers::SignalData<void(const socMemInfo &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'activityAdded'
        QtMocHelpers::SignalData<void(const actInfo &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Signal 'participantsAdded'
        QtMocHelpers::SignalData<void(const actPtpInfo &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SocietiesSql, qt_meta_tag_ZN12SocietiesSqlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SocietiesSql::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SocietiesSqlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SocietiesSqlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12SocietiesSqlE_t>.metaTypes,
    nullptr
} };

void SocietiesSql::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SocietiesSql *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->studentAdded((*reinterpret_cast< std::add_pointer_t<stuInfo>>(_a[1]))); break;
        case 1: _t->societyAdded((*reinterpret_cast< std::add_pointer_t<socInfo>>(_a[1]))); break;
        case 2: _t->memberAdded((*reinterpret_cast< std::add_pointer_t<socMemInfo>>(_a[1]))); break;
        case 3: _t->activityAdded((*reinterpret_cast< std::add_pointer_t<actInfo>>(_a[1]))); break;
        case 4: _t->participantsAdded((*reinterpret_cast< std::add_pointer_t<actPtpInfo>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SocietiesSql::*)(const stuInfo & )>(_a, &SocietiesSql::studentAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocietiesSql::*)(const socInfo & )>(_a, &SocietiesSql::societyAdded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocietiesSql::*)(const socMemInfo & )>(_a, &SocietiesSql::memberAdded, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocietiesSql::*)(const actInfo & )>(_a, &SocietiesSql::activityAdded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SocietiesSql::*)(const actPtpInfo & )>(_a, &SocietiesSql::participantsAdded, 4))
            return;
    }
}

const QMetaObject *SocietiesSql::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocietiesSql::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12SocietiesSqlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocietiesSql::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SocietiesSql::studentAdded(const stuInfo & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SocietiesSql::societyAdded(const socInfo & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SocietiesSql::memberAdded(const socMemInfo & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void SocietiesSql::activityAdded(const actInfo & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SocietiesSql::participantsAdded(const actPtpInfo & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
