
#include "doctorsearchcontroller.h"

DoctorSearchController::DoctorSearchController(DoctorSearchView *view, QObject *parent)
    : QObject(parent), view(view)
{
    connect(view, &DoctorSearchView::backToDashboard, this, &DoctorSearchController::backToDashboardRequested);
    connect(view, &DoctorSearchView::appointmentConfirmed, this, &DoctorSearchController::onAppointmentConfirmed);

    loadDoctors();
}

void DoctorSearchController::loadDoctors()
{
    // In a real application, this would fetch doctors from a database or API
    QStringList doctors = {"Dr. Smith", "Dr. Johnson", "Dr. Williams", "Dr. Brown", "Dr. Jones"};
    view->updateDoctorList(doctors);
}

void DoctorSearchController::onAppointmentConfirmed(const QString &doctor, const QDate &date, const QString &time)
{
    emit appointmentConfirmationRequested(doctor, date, time);
}