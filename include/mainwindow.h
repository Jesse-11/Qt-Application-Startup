#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "../src/controller/dashboardcontroller.h"
#include "../src/controller/prescriptioncontroller.h"
#include "../src/controller/telemedicinecontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDashboard();
    void showPrescriptions();
    void showTelemedicine();

private:
    QStackedWidget *stackedWidget;
    DashboardController *dashboardController;
    PrescriptionController *prescriptionController;
    TelemedicineController *telemedicineController;
};

#endif // MAINWINDOW_H