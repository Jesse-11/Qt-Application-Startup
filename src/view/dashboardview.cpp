#include "dashboardview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPixmap>
#include <QFont>
#include <QPalette>
#include <QDebug>

DashboardView::DashboardView(QWidget *parent) : QWidget(parent) {
    createLayout();
    styleWidgets();
}

void DashboardView::setWelcomeMessage(const QString &message) {
    welcomeLabel->setText(message);
}

void DashboardView::createLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Logo and Welcome message
    QHBoxLayout *topLayout = new QHBoxLayout();
    logoLabel = new QLabel(this);
    QPixmap logo(":resources/images/placeholder-logo-1.png");  // Make sure to add your logo to resources
    if (logo.isNull()) {
        qDebug() << "Failed to load logo image";
    } else {
        logoLabel->setPixmap(logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    topLayout->addWidget(logoLabel);

    welcomeLabel = new QLabel(this);
    topLayout->addWidget(welcomeLabel, 1);
    topLayout->addStretch();

    mainLayout->addLayout(topLayout);

    // Main content
    QHBoxLayout *contentLayout = new QHBoxLayout();

    // Left column
    QVBoxLayout *leftColumn = new QVBoxLayout();
    leftColumn->addWidget(createStyledGroupBox("Telemedicine Consultation", 
        "Connect with healthcare providers remotely for consultations and follow-ups.", 
        startConsultationButton = new QPushButton("Start Consultation")));
    leftColumn->addStretch();

    // Right column
    QVBoxLayout *rightColumn = new QVBoxLayout();
    rightColumn->addWidget(createStyledGroupBox("My Profile", 
        "View and update your personal health information", 
        accessProfileButton = new QPushButton("Access Profile")));
    rightColumn->addWidget(createStyledGroupBox("Appointments", 
        "Schedule and manage your medical appointments", 
        bookAppointmentButton = new QPushButton("Book Appointment")));
    rightColumn->addStretch();

    contentLayout->addLayout(leftColumn, 2);
    contentLayout->addLayout(rightColumn, 1);

    mainLayout->addLayout(contentLayout);

    // Bottom row
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(createStyledGroupBox("Medical Records", 
        "Access your medical history and test results", 
        viewRecordsButton = new QPushButton("View Records")));
    bottomLayout->addWidget(createStyledGroupBox("Prescriptions", 
        "Manage and request prescription refills", 
        refillPrescriptionButton = new QPushButton("Refill Prescription")));

    mainLayout->addLayout(bottomLayout);

    // Connect signals
    connect(startConsultationButton, &QPushButton::clicked, this, &DashboardView::startConsultationClicked);
    connect(accessProfileButton, &QPushButton::clicked, this, &DashboardView::accessProfileClicked);
    connect(bookAppointmentButton, &QPushButton::clicked, this, &DashboardView::bookAppointmentClicked);
    connect(viewRecordsButton, &QPushButton::clicked, this, &DashboardView::viewRecordsClicked);
    connect(refillPrescriptionButton, &QPushButton::clicked, this, &DashboardView::refillPrescriptionClicked);
}

void DashboardView::styleWidgets() {
    // Set the background color of the main widget
    setStyleSheet("background-color: #f0f0f0;");

    // Style the welcome label
    welcomeLabel->setStyleSheet(
        "font-size: 24px; font-weight: bold; color: #2c3e50;"
    );

    // Style the buttons
    QString buttonStyle = 
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px;"
        "   border-radius: 5px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #21618c;"
        "}";

    startConsultationButton->setStyleSheet(buttonStyle);
    accessProfileButton->setStyleSheet(buttonStyle);
    bookAppointmentButton->setStyleSheet(buttonStyle);
    viewRecordsButton->setStyleSheet(buttonStyle);
    refillPrescriptionButton->setStyleSheet(buttonStyle);
}

QGroupBox* DashboardView::createStyledGroupBox(const QString &title, const QString &description, QPushButton *button) {
    QGroupBox *groupBox = new QGroupBox(title);
    QVBoxLayout *layout = new QVBoxLayout(groupBox);

    QLabel *descLabel = new QLabel(description);
    descLabel->setWordWrap(true);

    layout->addWidget(descLabel);
    layout->addWidget(button);

    groupBox->setStyleSheet(
        "QGroupBox {"
        "   background-color: white;"
        "   border: 1px solid #bdc3c7;"
        "   border-radius: 5px;"
        "   margin-top: 10px;"
        "   font-weight: bold;"
        "}"
        "QGroupBox::title {"
        "   subcontrol-origin: margin;"
        "   left: 10px;"
        "   padding: 0 3px 0 3px;"
        "}"
    );

    return groupBox;
}