#include "../include/mainwindow.h"
#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("E-Health Portal");
    
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);


    // Create Views
    DashboardView *dashboardView = new DashboardView(this);
    PrescriptionView *prescriptionView = new PrescriptionView(this);

    // Create Controllers
    dashboardController = new DashboardController(new DashboardModel(), dashboardView, this);
    prescriptionController = new PrescriptionController(prescriptionView, this);

    // Add views to stacked weight
    stackedWidget->addWidget(dashboardView);
    stackedWidget->addWidget(prescriptionView);

    // Connect signals
    connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);
    connect(prescriptionController, &PrescriptionController::backToDashboardRequested, this, &MainWindow::showDashboard);

    showDashboard();

    showMaximized(); // sets width and height of window

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

MainWindow::~MainWindow() {}

void MainWindow::showDashboard() {
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::showPrescriptions() {
    stackedWidget->setCurrentIndex(1);
}
