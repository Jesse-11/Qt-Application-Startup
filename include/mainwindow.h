#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include "../src/controller/dashboardcontroller.h"
#include "../src/controller/prescriptioncontroller.h"
#include "../src/controller/telemedicinecontroller.h"
#include "../src/controller/appointmentcontroller.h"
#include "../src/controller/doctorsearchcontroller.h"
#include "../src/controller/confirmappointmentcontroller.h"
#include <QDebug>


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDashboard();
    void showPrescriptions();
    void showTelemedicine();
    void showAppointment();
    void showDoctorSearch();
    void showConfirmAppointment(const QString &doctor, const QDate &date, const QString &time);
    void handleAppointmentConfirmed();
    void handleAppointmentCancelled();

private:
    QStackedWidget *stackedWidget;
    DashboardController *dashboardController;
    PrescriptionController *prescriptionController;
    TelemedicineController *telemedicineController;
    AppointmentController *appointmentController;
    DoctorSearchController *doctorsearchController;
    ConfirmAppointmentController *confirmappointmentController;
    ConfirmAppointmentView *confirmappointmentView; 
    
};