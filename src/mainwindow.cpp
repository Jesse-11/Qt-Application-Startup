#include "../include/mainwindow.h"

#include <QScreen>
#include <QGuiApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("E-Health Portal");
    
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Create Views
    DashboardView *dashboardView = new DashboardView(this);
    PrescriptionView *prescriptionView = new PrescriptionView(this);
    TelemedicineView *telemedicineView = new TelemedicineView(this);
    ConsultationView *consultationView = new ConsultationView(this);
    AppointmentView *appointmentView = new AppointmentView(this);
    DoctorSearchView *doctorsearchView = new DoctorSearchView(this);
    confirmappointmentView = new ConfirmAppointmentView(this);
    LanguageSelectionView *languageselectionView = new LanguageSelectionView(this);
    HealthDataView *healthdataview = new HealthDataView(this);


    // Create Controllers
    dashboardController = new DashboardController(new DashboardModel(), dashboardView, this);
    prescriptionController = new PrescriptionController(prescriptionView, this);
    telemedicineController = new TelemedicineController(telemedicineView,consultationView, this);
    appointmentController = new AppointmentController(appointmentView, this);
    doctorsearchController = new DoctorSearchController(doctorsearchView, this);
    confirmappointmentController = new ConfirmAppointmentController(confirmappointmentView, this);
    languageselectionController = new LanguageSelectionController(languageselectionModel, languageselectionView, this);
    healthdataController = new HealthDataController(healthdataview, this);


    // Add views to stacked widget
    stackedWidget->addWidget(dashboardView);
    stackedWidget->addWidget(prescriptionView);
    stackedWidget->addWidget(telemedicineView);
    stackedWidget->addWidget(appointmentView);
    stackedWidget->addWidget(doctorsearchView);
    stackedWidget->addWidget(confirmappointmentView);
    stackedWidget->addWidget(languageselectionView);
    stackedWidget->addWidget(consultationView);
    stackedWidget->addWidget(healthdataview);


    // Connect signals
    connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);
    connect(dashboardController, &DashboardController::telemedicineRequested, this, &MainWindow::showTelemedicine);
    connect(dashboardController, &DashboardController::appointmentRequested, this, &MainWindow::showAppointment);
    connect(dashboardController, &DashboardController::languageSelectionRequested, this, &MainWindow::showLanguageSelection);
    connect(dashboardController, &DashboardController::profileRequested, this, &MainWindow::showProfile);

    connect(prescriptionController, &PrescriptionController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(telemedicineController, &TelemedicineController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(telemedicineController, &TelemedicineController::consultationReady, this, &MainWindow::showConsultation);
    connect(telemedicineController, &TelemedicineController::consultationEnded,this, &MainWindow::handleConsultationEnded);
    connect(healthdataController, &HealthDataController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(appointmentController, &AppointmentController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(appointmentController, &AppointmentController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(appointmentController, &AppointmentController::doctorSearchRequested, this, &MainWindow::showDoctorSearch);
    connect(doctorsearchController, &DoctorSearchController::backToDashboardRequested, this, &MainWindow::showDashboard);
    connect(doctorsearchController, &DoctorSearchController::appointmentConfirmationRequested, this, &MainWindow::showConfirmAppointment);
    connect(confirmappointmentController, &ConfirmAppointmentController::appointmentConfirmed, this, &MainWindow::handleAppointmentConfirmed);
    connect(confirmappointmentController, &ConfirmAppointmentController::appointmentCancelled, this, &MainWindow::handleAppointmentCancelled);
    connect(languageselectionController, &LanguageSelectionController::languageChanged, this, &MainWindow::onLanguageChanged);
    connect(languageselectionController, &LanguageSelectionController::cancelRequested, this, &MainWindow::showDashboard);

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
    telemedicineController->startTimer();
}

void MainWindow::showAppointment() {
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::showDoctorSearch() {
    stackedWidget->setCurrentIndex(4);
}

void MainWindow::showLanguageSelection() {
    stackedWidget->setCurrentIndex(6);  
}
void MainWindow::showConsultation() {
    if(stackedWidget->currentIndex() == 2)
    {
        stackedWidget->setCurrentIndex(7);
    }
    
}
void MainWindow::showProfile(){
    stackedWidget->setCurrentIndex(8);
}

void MainWindow::showConfirmAppointment(const QString &doctor, const QDate &date, const QString &time) {
    qDebug() << "showConfirmAppointment called";
    if (!stackedWidget) {
        qDebug() << "stackedWidget is null!";
        return;
    }
    if (!confirmappointmentView) {
        qDebug() << "confirmappointmentView is null!";
        return;
    }
    confirmappointmentController->setAppointmentDetails(doctor, date, time);
    stackedWidget->setCurrentWidget(confirmappointmentView);
}

void MainWindow::handleAppointmentConfirmed()
{
    QMessageBox::information(this, "Appointment Confirmed", "Your appointment has been confirmed.");
    showDashboard();
}

void MainWindow::handleAppointmentCancelled()
{
    showDashboard();
}

void MainWindow::onLanguageChanged(const QString& languageCode) {
    qDebug() << "Language changed to:" << languageCode;
    showDashboard();
}
void MainWindow::handleConsultationEnded() {
    showDashboard();
}

