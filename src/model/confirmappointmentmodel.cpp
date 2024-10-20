
#include "confirmappointmentmodel.h"

ConfirmAppointmentModel::ConfirmAppointmentModel()
    : m_doctor(""), m_date(QDate()), m_time(QTime()), m_patientName(""), m_reason("")
{
}

ConfirmAppointmentModel::ConfirmAppointmentModel(const QString &doctor, const QDate &date, const QTime &time, const QString &patientName, const QString &reason)
    : m_doctor(doctor), m_date(date), m_time(time), m_patientName(patientName), m_reason(reason)
{
}

QString ConfirmAppointmentModel::getDoctor() const { return m_doctor; }
QDate ConfirmAppointmentModel::getDate() const { return m_date; }
QTime ConfirmAppointmentModel::getTime() const { return m_time; }
QString ConfirmAppointmentModel::getPatientName() const { return m_patientName; }
QString ConfirmAppointmentModel::getReason() const { return m_reason; }

void ConfirmAppointmentModel::setDoctor(const QString &doctor) { m_doctor = doctor; }
void ConfirmAppointmentModel::setDate(const QDate &date) { m_date = date; }
void ConfirmAppointmentModel::setTime(const QTime &time) { m_time = time; }
void ConfirmAppointmentModel::setPatientName(const QString &patientName) { m_patientName = patientName; }
void ConfirmAppointmentModel::setReason(const QString &reason) { m_reason = reason; }