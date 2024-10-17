#include "prescriptioncontroller.h"
#include <QDate>
#include <QDebug>

PrescriptionController::PrescriptionController(PrescriptionView *view, QObject *parent)
    : QObject(parent), view(view) {
    connect(view, &PrescriptionView::refillRequested, this, &PrescriptionController::handleRefillRequest);
    connect(view, &PrescriptionView::backToDashboard, this, &PrescriptionController::backToDashboardRequested);
    loadPrescriptions();
}

void PrescriptionController::loadPrescriptions() {
    // In a real application, this data would come from a database or API
    prescriptions.clear();
    prescriptions.append(PrescriptionModel("Lisinopril", "10mg", "Once daily", QDate(2024, 9, 15), 2));
    prescriptions.append(PrescriptionModel("Metformin", "500mg", "Twice daily", QDate(2024, 9, 20), 3));
    view->updatePrescriptionList(prescriptions);
}

void PrescriptionController::handleRefillRequest(const QString &prescriptionName) {
    // In a real application, this would send a request to a backend service
    qDebug() << "Refill requested for:" << prescriptionName;
}