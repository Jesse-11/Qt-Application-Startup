#include "dashboardview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPixmap>
#include <QFont>
#include <QPalette>
#include <QDebug>
#include <QLabel>
#include <QApplication>
#include <QScreen>

DashboardView::DashboardView(QWidget *parent) : QWidget(parent) {
    createLayout();
    styleWidgets();
}

void DashboardView::setWelcomeMessage(const QString &message) {
    welcomeLabel->setText(message);
}

void DashboardView::createLayout() {


    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("E-Health Portal", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333;");
    headerLayout->addWidget(titleLabel);

    
    // Language Button
    languageButton = new QPushButton("Language", this);
    languageButton->setFixedSize(120, 40);
    headerLayout->addWidget(languageButton, 0, Qt::AlignRight | Qt::AlignVCenter);


    // Welcome message
    welcomeLabel = new QLabel("Welcome to your personal health management system", this);
    welcomeLabel->setStyleSheet("font-size: 16px; color: #666;");

    QVBoxLayout *headerVLayout = new QVBoxLayout();
    headerVLayout->addLayout(headerLayout);
    headerVLayout->addWidget(welcomeLabel);

    QWidget *headerWidget = new QWidget(this);
    headerWidget->setLayout(headerVLayout);
    headerWidget->setStyleSheet("background-color: white; border-radius: 10px; padding: 15px;");

    mainLayout->addWidget(headerWidget);

    // Main content
    QHBoxLayout *contentLayout = new QHBoxLayout();
    contentLayout->setSpacing(20);

    // Left column
    QVBoxLayout *leftColumn = new QVBoxLayout();
    leftColumn->addWidget(createStyledGroupBox("Telemedicine Consultation", 
        "Connect with healthcare providers remotely for consultations and follow-ups.", 
        startConsultationButton = new QPushButton("Start Consultation")));

    // Right column
    QVBoxLayout *rightColumn = new QVBoxLayout();
    rightColumn->setSpacing(20);
    rightColumn->addWidget(createStyledGroupBox("My Profile", 
        "View and update your personal health information", 
        accessProfileButton = new QPushButton("Access Profile")));
    rightColumn->addWidget(createStyledGroupBox("Appointments", 
        "Schedule and manage your medical appointments", 
        bookAppointmentButton = new QPushButton("Book Appointment")));

    contentLayout->addLayout(leftColumn, 2);
    contentLayout->addLayout(rightColumn, 1);

    mainLayout->addLayout(contentLayout);

    // Bottom row
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->setSpacing(20);
    bottomLayout->addWidget(createStyledGroupBox("Medical Records", 
        "Access your medical history and test results", 
        viewRecordsButton = new QPushButton("View Records")));
    bottomLayout->addWidget(createStyledGroupBox("Prescriptions", 
        "Manage and request prescription refills", 
        refillPrescriptionButton = new QPushButton("Refill Prescription")));

    mainLayout->addLayout(bottomLayout);

    // Footer
    QLabel *footerLabel = new QLabel("© 2024 E-Health Portal. All rights reserved.", this);
    footerLabel->setAlignment(Qt::AlignCenter);
    footerLabel->setStyleSheet("color: #666; margin-top: 20px;");
    mainLayout->addWidget(footerLabel);

    // Connect signals
    connect(startConsultationButton, &QPushButton::clicked, this, &DashboardView::startConsultationClicked);
    connect(accessProfileButton, &QPushButton::clicked, this, &DashboardView::accessProfileClicked);
    connect(bookAppointmentButton, &QPushButton::clicked, this, &DashboardView::bookAppointmentClicked);
    connect(viewRecordsButton, &QPushButton::clicked, this, &DashboardView::viewRecordsClicked);
    connect(refillPrescriptionButton, &QPushButton::clicked, this, &DashboardView::refillPrescriptionClicked);
    connect(languageButton, &QPushButton::clicked, this, &DashboardView::languageSelectionClicked);
    connect(languageButton, &QPushButton::clicked, this, &DashboardView::languageButtonClicked);
}

void DashboardView::styleWidgets() {

    // Set the background color of the main widget
    setStyleSheet("background-color: #f0f0f0;");

    // Style the buttons
    QString buttonStyle = 
        "QPushButton {"
        "   background-color: #1a1a2e;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   border-radius: 5px;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   min-width: 150px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #16213e;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #0f3460;"
        "}";


    // Style language button
    QString languageButtonStyle = 
        "QPushButton {"
        "   background-color: #1a1a2e;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 5px;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   text-align: center;"
        "   padding: 0px;" 
        "}"
        "QPushButton:hover {"
        "   background-color: #16213e;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #0f3460;"
        "}";

    startConsultationButton->setStyleSheet(buttonStyle);
    accessProfileButton->setStyleSheet(buttonStyle);
    bookAppointmentButton->setStyleSheet(buttonStyle);
    viewRecordsButton->setStyleSheet(buttonStyle);
    refillPrescriptionButton->setStyleSheet(buttonStyle);
    languageButton->setStyleSheet(languageButtonStyle);

}

QGroupBox* DashboardView::createStyledGroupBox(const QString &title, const QString &description, QPushButton *button) {
    QGroupBox *groupBox = new QGroupBox(this);
    QVBoxLayout *layout = new QVBoxLayout(groupBox);

    QLabel *titleLabel = new QLabel(title, groupBox);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");
    
    QLabel *descLabel = new QLabel(description, groupBox);
    descLabel->setWordWrap(true);
    descLabel->setStyleSheet("color: #666; margin-bottom: 15px;");

    layout->addWidget(titleLabel);
    layout->addWidget(descLabel);
    layout->addWidget(button);
    layout->addStretch();

    groupBox->setStyleSheet(
        "QGroupBox {"
        "   background-color: white;"
        "   border: none;"
        "   border-radius: 10px;"
        "   padding: 20px;"
        "}"
    );

    return groupBox;
}