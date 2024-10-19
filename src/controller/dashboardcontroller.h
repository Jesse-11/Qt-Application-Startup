#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include <QObject>
#include "../model/dashboardmodel.h"
#include "../view/dashboardview.h"

class DashboardController : public QObject {
    Q_OBJECT

public:
    explicit DashboardController(DashboardModel *model, DashboardView *view, QObject *parent = nullptr);

signals:

    void prescriptionsRequested();
    void telemedicineRequested();  
    void appointmentRequested();

private slots:
    void onStartConsultationClicked();
    void onAccessProfileClicked();
    void onBookAppointmentClicked();
    void onViewRecordsClicked();
    void onRefillPrescriptionClicked();
    void onLanguageButtonClicked();

private:
    DashboardModel *model;
    DashboardView *view;

    void updateView();
};

#endif // DASHBOARDCONTROLLER_H