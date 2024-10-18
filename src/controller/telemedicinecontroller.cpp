#include "telemedicinecontroller.h"
#include "../model/telemedicinemodel.h"
#include <iostream>
#include <QString>
#include <QVector>

TelemedicineController::TelemedicineController(TelemedicineView* view, QObject* parent)
    : QObject(parent), view(view) {
    model= new TelemedicineModel();
    connect(view, &TelemedicineView::contactSupportClicked, this, &TelemedicineController::contactSupport);
    connect(view, &TelemedicineView::backToDashboard, this, &TelemedicineController::backToDashboardRequested);
    loadTelemedicineData();
}

void TelemedicineController::loadTelemedicineData() {
    view->setQueuePositionLabel(QString::number(model->getQueuePosition()));
    view->setWaitTimeLabel(QString::number(model->getEstimatedWaitTime()) + " minutes");
    view->setDoctorNameLabel(model->getDoctorName());
    view->setDoctorSpecialtyLabel(model->getDoctorSpecialty());

    QVector<QString> steps = model->getPreparationSteps();
    // ... rest of the function ...
}