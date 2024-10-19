#include "appointmentmodel.h"

AppointmentModel::AppointmentModel(const QString &id, const QString &doctor, const QDate &date, const QTime &time, const QString &description)
    : id(id), doctor(doctor), date(date), time(time), description(description) {}

QString AppointmentModel::getId() const { return id; }
QString AppointmentModel::getDoctor() const { return doctor; }
QDate AppointmentModel::getDate() const { return date; }
QTime AppointmentModel::getTime() const { return time; }
QString AppointmentModel::getDescription() const { return description; }