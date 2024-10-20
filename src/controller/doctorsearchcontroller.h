#pragma once

#include <QObject>
#include "../model/doctorsearchmodel.h"
#include "../view/doctorsearchview.h"
#include <QList>
#include "../view/confirmappointmentview.h"

class DoctorSearchController : public QObject
{
    Q_OBJECT

public:
    explicit DoctorSearchController(DoctorSearchView *view, QObject *parent = nullptr);

signals:
    void backToDashboardRequested();
    void appointmentConfirmationRequested(const QString &doctor, const QDate &date, const QString &time);

private slots:
    void onAppointmentConfirmed(const QString &doctor, const QDate &date, const QString &time);

private:
    DoctorSearchView *view;
    void loadDoctors();
};