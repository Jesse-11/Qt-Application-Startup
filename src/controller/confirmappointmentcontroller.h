#pragma once

#include <QObject>
#include "../model/confirmappointmentmodel.h"
#include "../view/confirmappointmentview.h"
#include <QDate>
#include <QString>


class ConfirmAppointmentController : public QObject
{
    Q_OBJECT

public:
    explicit ConfirmAppointmentController(ConfirmAppointmentView *view, QObject *parent = nullptr);

public slots:
    void setAppointmentDetails(const QString &doctor, const QDate &date, const QString &time);

signals:
    void appointmentConfirmed();
    void appointmentCancelled();

private slots:
    void onConfirmClicked();
    void onCancelClicked();

private:
    ConfirmAppointmentView *view;
    QString doctor;
    QDate date;
    QString time;
};