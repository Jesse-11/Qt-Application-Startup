#ifndef TELEMEDICINECONTROLLER_H
#define TELEMEDICINECONTROLLER_H

#include "../model/telemedicinemodel.h"
#include "../view/telemedicineview.h"
#include "../controller/consultationcontroller.h"
#include "../view/consultationview.h"
#include "../controller/dashboardcontroller.h"
#include <QString>
#include <QVector>
#include <functional>
#include <QObject>


class TelemedicineController : public QObject {
    Q_OBJECT

public:
    TelemedicineController(TelemedicineView* view, 
                          ConsultationView* consultView,
                          QObject* parent = nullptr);
    void startTimer();

signals:
    void consultationEnded();
    void consultationReady();
public slots:
    void backToDashboardRequested();

private slots:
    void handleQueuePositionChanged(int newPosition);
    void handleEstimatedWaitTimeChanged(int newTime);
    void handleConsultationReady();
    void onContactSupportClicked();

private:
    TelemedicineModel* model;
    TelemedicineView* view;
    ConsultationController* consultationController;
    void loadTelemedicineData();
    void setupModelConnections();
};

#endif