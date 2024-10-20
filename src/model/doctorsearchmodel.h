#pragma once

#include <QString>
#include <QDate>
#include <QTime>

class DoctorSearchModel {
public:
    DoctorSearchModel(const QString &id, const QString &doctor, const QDate &date, const QTime &time, const QString &description);

    QString getId() const;
    QString getDoctor() const;
    QDate getDate() const;
    QTime getTime() const;
    QString getDescription() const;

private:
    QString id;
    QString doctor;
    QDate date;
    QTime time;
    QString description;
};