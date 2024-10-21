

// telemedicinecontroller.cpp
#include "telemedicinecontroller.h"
#include <QDebug>

TelemedicineController::TelemedicineController(TelemedicineView* view, QObject* parent)
    : QObject(parent), view(view) {

     model = new TelemedicineModel(3, 12, "Dr. Jane Smith", "General Practitioner");
    
    connect(view, &TelemedicineView::backToDashboard, this, &TelemedicineController::backToDashboardRequested);
    connect(view, &TelemedicineView::contactSupportClicked, this, &TelemedicineController::onContactSupportClicked);
    
    loadTelemedicineData();
}

void TelemedicineController::loadTelemedicineData() {
    view->setQueuePositionLabel(QString::number(model->getQueuePosition()));
    view->setWaitTimeLabel(QString::number(model->getEstimatedWaitTime()) + " minutes");
    view->setDoctorNameLabel(model->getDoctorName());
    view->setDoctorSpecialtyLabel(model->getDoctorSpecialty());
    
    QString preparationSteps;
    for (const auto& step : model->getPreparationSteps()) {
        preparationSteps += "• " + step + "\n";
    }
    view->setPreparationLabel(preparationSteps);
}

void TelemedicineController::onContactSupportClicked() {
    qDebug() << "Contact support clicked";
    // Implement contact support functionality here
}