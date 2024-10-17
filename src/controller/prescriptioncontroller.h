#ifndef PRESCRIPTIONCONTROLLER_H
#define PRESCRIPTIONCONTROLLER_H

#include <QObject>
#include "../model/prescriptionmodel.h"
#include "../view/prescriptionview.h"
#include <QList>

class PrescriptionController : public QObject {
    Q_OBJECT

public:
    explicit PrescriptionController(PrescriptionView *view, QObject *parent = nullptr);

public slots:
    void loadPrescriptions();
    void handleRefillRequest(const QString &prescriptionName);

signals:
    void backToDashboardRequested();

private:
    PrescriptionView *view;
    QList<PrescriptionModel> prescriptions;
};

#endif // PRESCRIPTIONCONTROLLER_H