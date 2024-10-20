#include "doctorsearchmodel.h"

DoctorSearchModel::DoctorSearchModel(const QString &id, const QString &doctor, const QDate &date, const QTime &time, const QString &description)
    : id(id), doctor(doctor), date(date), time(time), description(description) {}

QString DoctorSearchModel::getId() const { return id; }
QString DoctorSearchModel::getDoctor() const { return doctor; }
QDate DoctorSearchModel::getDate() const { return date; }
QTime DoctorSearchModel::getTime() const { return time; }
QString DoctorSearchModel::getDescription() const { return description; }