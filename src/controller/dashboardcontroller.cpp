#include "dashboardcontroller.h"
#include <QDebug>

DashboardController::DashboardController(DashboardModel *model, DashboardView *view, QObject *parent)
    : QObject(parent), model(model), view(view) {
    updateView();

    connect(view, &DashboardView::startConsultationClicked, this, &DashboardController::onStartConsultationClicked);
    connect(view, &DashboardView::accessProfileClicked, this, &DashboardController::onAccessProfileClicked);
    connect(view, &DashboardView::bookAppointmentClicked, this, &DashboardController::onBookAppointmentClicked);
    connect(view, &DashboardView::viewRecordsClicked, this, &DashboardController::onViewRecordsClicked);
    connect(view, &DashboardView::refillPrescriptionClicked, this, &DashboardController::onRefillPrescriptionClicked);
    connect(view, &DashboardView::languageButtonClicked, this, &DashboardController::onLanguageButtonClicked);
    connect(view, &DashboardView::profileClicked, this, &DashboardController::onProfileClicked);
}

void DashboardController::updateView() {
    view->setWelcomeMessage(model->getWelcomeMessage());
}

void DashboardController::onLanguageButtonClicked() {
    qDebug() << "Language button clicked";
    emit languageSelectionRequested();
}

void DashboardController::onStartConsultationClicked() {
    qDebug() << "Start Consultation clicked";
    emit telemedicineRequested();
}

void DashboardController::onAccessProfileClicked() {
    qDebug() << "Access Profile clicked";
    // Implement the action for accessing the profile
}

void DashboardController::onBookAppointmentClicked() {
    qDebug() << "Book Appointment clicked";
    emit appointmentRequested();
}

void DashboardController::onViewRecordsClicked() {
    qDebug() << "View Records clicked";
    // Implement the action for viewing medical records
}

void DashboardController::onRefillPrescriptionClicked() {
    qDebug() << "Refill Prescription clicked";
    emit prescriptionsRequested();
}

void DashboardController::onProfileClicked() {
    qDebug() << "Profile clicked";
    emit profileRequested();
}
