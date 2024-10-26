#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include "../src/controller/dashboardcontroller.h"
#include "../src/controller/prescriptioncontroller.h"
#include "../src/controller/telemedicinecontroller.h"
#include "../src/controller/appointmentcontroller.h"
#include "../src/controller/doctorsearchcontroller.h"
#include "../src/controller/confirmappointmentcontroller.h"
#include "../src/controller/languageselectioncontroller.h"
#include "../src/controller/healthdatacontroller.h"
#include "../src/view/healthdataview.h" 
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
    void showConsultation();
    void showProfile();
    void handleAppointmentConfirmed();
    void handleAppointmentCancelled();
    void handleConsultationEnded();
    void showLanguageSelection();
    void onLanguageChanged(const QString& languageCode);

private:
    QStackedWidget *stackedWidget;
    DashboardController *dashboardController;
    PrescriptionController *prescriptionController;
    TelemedicineController *telemedicineController;
    AppointmentController *appointmentController;
    DoctorSearchController *doctorsearchController;
    ConfirmAppointmentController *confirmappointmentController;
    ConfirmAppointmentView *confirmappointmentView; 
    LanguageSelectionController* languageselectionController;
    LanguageSelectionModel *languageselectionModel;
    LanguageSelectionView *languageselectionView;
    HealthDataController *healthdataController;
};