#include "telemedicinecontroller.h"
#include <QDebug>

TelemedicineController::TelemedicineController(TelemedicineView* view,
                                             ConsultationView* consultView,
                                             QObject* parent)
    : QObject(parent)
    , view(view) 
{
    model = new TelemedicineModel(3, 12, "Dr. Jane Smith", "General Practitioner", this);
    consultationController = new ConsultationController(consultView, this);
    
    // Connect consultation end signal
    connect(consultationController, &ConsultationController::consultationEnded,
            this, &TelemedicineController::backToDashboardRequested);
    connect(view, &TelemedicineView::backToDashboard, 
            this, &TelemedicineController::backToDashboardRequested);
    connect(view, &TelemedicineView::contactSupportClicked, 
            this, &TelemedicineController::onContactSupportClicked);

    setupModelConnections();
    loadTelemedicineData();
    model->startQueueTimer();
}

void TelemedicineController::setupModelConnections() {
    connect(model, &TelemedicineModel::queuePositionChanged,
            this, &TelemedicineController::handleQueuePositionChanged);
    connect(model, &TelemedicineModel::estimatedWaitTimeChanged,
            this, &TelemedicineController::handleEstimatedWaitTimeChanged);
    connect(model, &TelemedicineModel::consultationReady,
            this, &TelemedicineController::handleConsultationReady);
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

// Add these new implementations
void TelemedicineController::handleQueuePositionChanged(int newPosition) {
    qDebug() << "Queue position updated to:" << newPosition;
    view->setQueuePositionLabel(QString::number(newPosition));
}

void TelemedicineController::handleEstimatedWaitTimeChanged(int newTime) {
    qDebug() << "Estimated wait time updated to:" << newTime;
    view->setWaitTimeLabel(QString::number(newTime) + " minutes");
}

void TelemedicineController::handleConsultationReady() {
    qDebug() << "Consultation is ready!";
    view->hide();
    emit consultationReady();
    consultationController->initializeConsultation(model->getDoctorName());
}

void TelemedicineController::backToDashboardRequested() {
    model->stopQueueTimer();
    // Make sure to clean up both views
    view->hide();
    emit consultationEnded();
}

void TelemedicineController::onContactSupportClicked() {
    qDebug() << "Contact support clicked";
    // Implement support functionality
}

