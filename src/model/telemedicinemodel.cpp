#include "telemedicinemodel.h"
#include <algorithm> // for std::max

TelemedicineModel::TelemedicineModel(int initialQueuePosition, int initialWaitTime,
                                     const QString &doctor, const QString &specialty)
    : queuePosition(std::max(0, initialQueuePosition)),
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
    calculateEstimatedWaitTime();
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