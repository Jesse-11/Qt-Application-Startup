#ifndef PRESCRIPTIONMODEL_H
#define PRESCRIPTIONMODEL_H

#include <QString>
#include <QDate>

class PrescriptionModel {
public:
    PrescriptionModel(const QString &name, const QString &dosage, const QString &frequency, const QDate &lastRefill, int refillsRemaining);

    QString getName() const;
    QString getDosage() const;
    QString getFrequency() const;
    QDate getLastRefill() const;
    int getRefillsRemaining() const;
    void decrementRefills();

private:
    QString name;
    QString dosage;
    QString frequency;
    QDate lastRefill;
    int refillsRemaining;
};

#endif // PRESCRIPTIONMODEL_H