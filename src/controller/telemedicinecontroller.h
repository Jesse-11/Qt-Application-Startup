#ifndef TELEMEDICINECONTROLLER_H
#define TELEMEDICINECONTROLLER_H

#include "../model/telemedicinemodel.h"
#include "../view/telemedicineview.h"
#include <QString>
#include <QVector>
#include <functional>
#include <QObject>

class TelemedicineView;  // Forward declaration

class TelemedicineController : public QObject {
    Q_OBJECT

public:
    TelemedicineController(TelemedicineView* view, QObject* parent = nullptr);
public slots:
    void loadTelemedicineData();

signals:
    void contactSupport();
    void backToDashboardRequested();

private:
    TelemedicineView* view;
    TelemedicineModel* model;  

    void setView(TelemedicineView* view);
    void notifyQueueUpdate();
    void checkAndNotifyConsultationReady();
};

#endif // TELEMEDICINECONTROLLER_H