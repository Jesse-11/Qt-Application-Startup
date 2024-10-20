#pragma once

#include <QObject>
#include "../model/appointmentmodel.h"
#include "../view/appointmentview.h"
#include <QList>

class AppointmentController : public QObject {
    Q_OBJECT

public:
    explicit AppointmentController(AppointmentView *view, QObject *parent = nullptr);

public slots:
    void loadAppointments();
    void handleRescheduleRequest(const QString &appointmentId);
    void handleCancelRequest(const QString &appointmentId);
    void handleMakeNewAppointment();

signals:
    void backToDashboardRequested();
    void doctorSearchRequested();
private:
    AppointmentView *view;
    QList<AppointmentModel> appointments;

    void loadMockAppointments(); // For demo purposes
};