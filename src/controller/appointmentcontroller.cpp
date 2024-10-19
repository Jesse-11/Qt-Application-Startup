#include "appointmentcontroller.h"
#include <QDate>
#include <QTime>
#include <QDebug>


AppointmentController::AppointmentController(AppointmentView *view, QObject *parent)
    : QObject(parent), view(view) {
    connect(view, &AppointmentView::rescheduleRequested, this, &AppointmentController::handleRescheduleRequest);
    connect(view, &AppointmentView::cancelRequested, this, &AppointmentController::handleCancelRequest);
    connect(view, &AppointmentView::makeNewAppointment, this, &AppointmentController::handleMakeNewAppointment);
    connect(view, &AppointmentView::backToDashboard, this, &AppointmentController::backToDashboardRequested);
    loadAppointments();
}

void AppointmentController::loadAppointments() {
    // In a real application, this would fetch appointments from a database or API
    loadMockAppointments();
    view->updateAppointmentList(appointments);
}

void AppointmentController::handleRescheduleRequest(const QString &appointmentId) {
    // In a real application, this would open a dialog or navigate to a rescheduling page
    qDebug() << "Reschedule requested for appointment:" << appointmentId;
}

void AppointmentController::handleCancelRequest(const QString &appointmentId) {
    // In a real application, this would show a confirmation dialog and then cancel the appointment
    qDebug() << "Cancel requested for appointment:" << appointmentId;
    
    // For demo purposes, let's remove the appointment from the list
    for (int i = 0; i < appointments.size(); ++i) {
        if (appointments[i].getId() == appointmentId) {
            appointments.removeAt(i);
            break;  // Exit the loop once we've found and removed the appointment
        }
    }
    
    view->updateAppointmentList(appointments);
}

void AppointmentController::handleMakeNewAppointment() {
    // In a real application, this would open a dialog or navigate to a new appointment page
    qDebug() << "Make new appointment requested";
}

void AppointmentController::loadMockAppointments() {
    appointments.clear();
    appointments.append(AppointmentModel("1", "Dr. Smith", QDate(2024, 10, 15), QTime(10, 0), "General Checkup"));
    appointments.append(AppointmentModel("2", "Dr. Johnson", QDate(2024, 10, 20), QTime(14, 30), "Cardiology Consult"));
    appointments.append(AppointmentModel("3", "Dr. Williams", QDate(2024, 10, 25), QTime(11, 15), "Pediatric Checkup"));
}