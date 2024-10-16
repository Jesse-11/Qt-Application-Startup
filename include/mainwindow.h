#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../src/controller/dashboardcontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    DashboardModel *dashboardModel;
    DashboardView *dashboardView;
    DashboardController *dashboardController;
};

#endif // MAINWINDOW_H