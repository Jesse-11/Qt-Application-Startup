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
    TelemedicineView *telemedicineView = new TelemedicineView(this);
    AppointmentView *appointmentView = new AppointmentView(this);

    // Create Controllers
    dashboardController = new DashboardController(new DashboardModel(), dashboardView, this);
    prescriptionController = new PrescriptionController(prescriptionView, this);
    telemedicineController = new TelemedicineController(telemedicineView, this);
    appointmentController = new AppointmentController(appointmentView, this);

    // Add views to stacked weight
    stackedWidget->addWidget(dashboardView);
    stackedWidget->addWidget(prescriptionView);
    stackedWidget->addWidget(telemedicineView);
    stackedWidget->addWidget(appointmentView);


    // Connect signals
    connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);
    connect(dashboardController, &DashboardController::telemedicineRequested, this, &MainWindow::showTelemedicine);
    connect(dashboardController, &DashboardController::appointmentRequested, this, &MainWindow::showAppointment);
    connect(prescriptionController, &PrescriptionController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(telemedicineController, &TelemedicineController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(appointmentController, &AppointmentController::backToDashboardRequested, this, &MainWindow::showDashboard);

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

void MainWindow::showTelemedicine() {
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::showAppointment() {
    stackedWidget->setCurrentIndex(3);
}