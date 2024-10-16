#include "../include/mainwindow.h"
#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("E-Health Portal");
    
    dashboardModel = new DashboardModel();
    dashboardView = new DashboardView(this);
    dashboardController = new DashboardController(dashboardModel, dashboardView, this);
    
    setCentralWidget(dashboardView);

    showMaximized(); // sets width and height of window

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

MainWindow::~MainWindow() {
    delete dashboardModel;
}