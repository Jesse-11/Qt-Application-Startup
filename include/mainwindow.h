#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "../src/controller/dashboardcontroller.h"
#include "../src/controller/prescriptioncontroller.h"

// mainwindow.h
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showDashboard();
    void showPrescriptions();

private:
    QStackedWidget *stackedWidget;
    DashboardController *dashboardController;
    PrescriptionController *prescriptionController;
};

#endif // MAINWINDOW_H