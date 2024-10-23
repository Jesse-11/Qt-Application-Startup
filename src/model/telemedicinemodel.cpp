#include "telemedicinemodel.h"
#include <algorithm>

TelemedicineModel::TelemedicineModel(QObject *parent)
    : QObject(parent)
{
    setupTimers();
}

TelemedicineModel::TelemedicineModel(int initialQueuePosition, int initialWaitTime,
                                   const QString &doctor, const QString &specialty,
                                   QObject *parent)
    : QObject(parent),
      queuePosition(std::max(0, initialQueuePosition)),
      estimatedWaitTime(initialWaitTime),
      doctorName(doctor),
      doctorSpecialty(specialty),
      preparationSteps({
          "Ensure your device is charged and connected to stable internet",
          "Find a quiet, well-lit space for your consultation",
          "Have your medical history and current medications list ready",
          "Prepare any questions you want to ask your doctor"
      })
{
    setupTimers();
    calculateEstimatedWaitTime();
}

void TelemedicineModel::setupTimers() {
    queueTimer = new QTimer(this);
    consultationTimer = new QTimer(this);
    
    queueTimer->setInterval(30000);  // 30 seconds
    consultationTimer->setInterval(5000);  // 5 seconds
    
    connect(queueTimer, &QTimer::timeout, this, &TelemedicineModel::onQueueTimerTimeout);
    connect(consultationTimer, &QTimer::timeout, this, &TelemedicineModel::onConsultationTimerTimeout);
    
    // Make consultation timer single-shot
    consultationTimer->setSingleShot(true);
}

void TelemedicineModel::onQueueTimerTimeout() {
    if (queuePosition > 0) {
        moveUpInQueue();
        emit queuePositionChanged(queuePosition);
        emit estimatedWaitTimeChanged(estimatedWaitTime);
        
        if (queuePosition == 0) {
            queueTimer->stop();
            consultationTimer->start();
        }
    }
}

void TelemedicineModel::onConsultationTimerTimeout() {
    emit consultationReady();
}

void TelemedicineModel::startQueueTimer() {
    queueTimer->start();
}

void TelemedicineModel::stopQueueTimer() {
    queueTimer->stop();
    consultationTimer->stop();
}
int TelemedicineModel::getQueuePosition() const { return queuePosition; }
int TelemedicineModel::getEstimatedWaitTime() const { return estimatedWaitTime; }
QString TelemedicineModel::getDoctorName() const { return doctorName; }
QString TelemedicineModel::getDoctorSpecialty() const { return doctorSpecialty; }
QVector<QString> TelemedicineModel::getPreparationSteps() const { return preparationSteps; }

void TelemedicineModel::setQueuePosition(int position) {
    queuePosition = std::max(0, position);
    calculateEstimatedWaitTime();
}

void TelemedicineModel::moveUpInQueue() {
    if (queuePosition > 0) {
        queuePosition--;
        calculateEstimatedWaitTime();
    }
}

bool TelemedicineModel::isReadyForConsultation() const {
    return queuePosition == 0;
}

void TelemedicineModel::calculateEstimatedWaitTime() {
    estimatedWaitTime = queuePosition * 4;
}

