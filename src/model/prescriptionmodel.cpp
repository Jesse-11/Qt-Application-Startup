#include "prescriptionmodel.h"

PrescriptionModel::PrescriptionModel(const QString &name, const QString &dosage, const QString &frequency, const QDate &lastRefill, int refillsRemaining)
    : name(name), dosage(dosage), frequency(frequency), lastRefill(lastRefill), refillsRemaining(refillsRemaining) {}

QString PrescriptionModel::getName() const { return name; }
QString PrescriptionModel::getDosage() const { return dosage; }
QString PrescriptionModel::getFrequency() const { return frequency; }
QDate PrescriptionModel::getLastRefill() const { return lastRefill; }
int PrescriptionModel::getRefillsRemaining() const { return refillsRemaining; }

void PrescriptionModel::decrementRefills() {
    if (refillsRemaining > 0) refillsRemaining--;
}