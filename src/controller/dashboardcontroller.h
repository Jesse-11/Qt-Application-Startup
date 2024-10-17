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

private slots:
    void onStartConsultationClicked();
    void onAccessProfileClicked();
    void onBookAppointmentClicked();
    void onViewRecordsClicked();
    void onRefillPrescriptionClicked();

private:
    DashboardModel *model;
    DashboardView *view;

    void updateView();
};

#endif // DASHBOARDCONTROLLER_H