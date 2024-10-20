
#include "confirmappointmentcontroller.h"
#include <QDebug>

ConfirmAppointmentController::ConfirmAppointmentController(ConfirmAppointmentView *view, QObject *parent)
    : QObject(parent), view(view)
{
    connect(view, &ConfirmAppointmentView::confirmClicked, this, &ConfirmAppointmentController::onConfirmClicked);
    connect(view, &ConfirmAppointmentView::cancelClicked, this, &ConfirmAppointmentController::onCancelClicked);
}

void ConfirmAppointmentController::setAppointmentDetails(const QString &doctor, const QDate &date, const QString &time)
{
    this->doctor = doctor;
    this->date = date;
    this->time = time;
    view->setAppointmentDetails(doctor, date, time);
}

void ConfirmAppointmentController::onConfirmClicked()
{
    qDebug() << "Appointment confirmed with" << doctor
             << "on" << date.toString()
             << "at" << time;
    emit appointmentConfirmed();
}

void ConfirmAppointmentController::onCancelClicked()
{
    emit appointmentCancelled();
}