#pragma once
#include <QString>
#include <QDate>
#include <QTime>

class ConfirmAppointmentModel
{
public:
    ConfirmAppointmentModel();
    ConfirmAppointmentModel(const QString &doctor, const QDate &date, const QTime &time, const QString &patientName, const QString &reason);

    QString getDoctor() const;
    QDate getDate() const;
    QTime getTime() const;
    QString getPatientName() const;
    QString getReason() const;

    void setDoctor(const QString &doctor);
    void setDate(const QDate &date);
    void setTime(const QTime &time);
    void setPatientName(const QString &patientName);
    void setReason(const QString &reason);

private:
    QString m_doctor;
    QDate m_date;
    QTime m_time;
    QString m_patientName;
    QString m_reason;
};