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

// Constructor
DashboardView::DashboardView(QWidget *parent) : QWidget(parent) {
    createLayout(); // Sets up layout
    styleWidgets(); // Apply styling to widgets
}


// Sets welcome Message
void DashboardView::setWelcomeMessage(const QString &message) {
    welcomeLabel->setText(message); 
}



void DashboardView::createLayout() {

    // Main layout with alignment and margins
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);





    // ---------------------------------------------------------

    // Header section
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("E-Health Portal", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333;");
    headerLayout->addWidget(titleLabel); // Add title to header layout

    
    // Language Button, aligned right in header
    languageButton = new QPushButton("Language", this);
    languageButton->setFixedSize(120, 40);
    headerLayout->addWidget(languageButton, 0, Qt::AlignRight | Qt::AlignVCenter); // Add language to header layout

    // Welcome message - below header
    welcomeLabel = new QLabel("Welcome to your personal health management system", this);
    welcomeLabel->setStyleSheet("font-size: 16px; color: #666;");

    //Combine header and welcome message vertically
    QVBoxLayout *headerVLayout = new QVBoxLayout(); //Create a vertical box layout
    headerVLayout->addLayout(headerLayout); // Add header
    headerVLayout->addWidget(welcomeLabel); // Add welcome

    // Wrap the header section in a stylised widget
    QWidget *headerWidget = new QWidget(this);
    headerWidget->setLayout(headerVLayout);
    headerWidget->setStyleSheet("background-color: white; border-radius: 10px; padding: 15px;");

    mainLayout->addWidget(headerWidget); // Add new header to main layout






    // ---------------------------------------------------------

    // Main content
    QHBoxLayout *contentLayout = new QHBoxLayout(); // Create a new content Layour
    contentLayout->setSpacing(20);

    // Left column
    QVBoxLayout *leftColumn = new QVBoxLayout(); // Create left layout
    leftColumn->addWidget(createStyledGroupBox("Telemedicine Consultation", 
        "Connect with healthcare providers remotely for consultations and follow-ups.", 
        startConsultationButton = new QPushButton("Start Consultation"))); // Create a widget which has text and a button

    // Right column
    QVBoxLayout *rightColumn = new QVBoxLayout(); // Create right layout
    rightColumn->setSpacing(20);
    rightColumn->addWidget(createStyledGroupBox("My Profile", 
        "View and update your personal health information", 
        accessProfileButton = new QPushButton("Access Profile"))); // Create widget with text and button
    rightColumn->addWidget(createStyledGroupBox("Appointments", 
        "Schedule and manage your medical appointments", 
        bookAppointmentButton = new QPushButton("Book Appointment"))); // Create Widget with text and button

    contentLayout->addLayout(leftColumn, 2); // Add leftcolumn to contect layout (2, means take more space)
    contentLayout->addLayout(rightColumn, 1); // Add right column to content layout 

    mainLayout->addLayout(contentLayout); // Add the contentLayout into the larger Main Layout







    // ---------------------------------------------------------

    // Bottom row
    QHBoxLayout *bottomLayout = new QHBoxLayout(); // Create a new bottom Layout
    bottomLayout->setSpacing(20);
    bottomLayout->addWidget(createStyledGroupBox("Medical Records", 
        "Access your medical history and test results", 
        viewRecordsButton = new QPushButton("View Records"))); // Create a widget with text and a button
    bottomLayout->addWidget(createStyledGroupBox("Prescriptions", 
        "Manage and request prescription refills", 
        refillPrescriptionButton = new QPushButton("View Prescriptions"))); // Create a widget with text and a button

    mainLayout->addLayout(bottomLayout); // Add bottom layout to alrger main Layout








    // ---------------------------------------------------------

    // Footer
    QLabel *footerLabel = new QLabel("© 2024 E-Health Portal. All rights reserved.", this); // Create a new footer label
    footerLabel->setAlignment(Qt::AlignCenter); // Allign footer
    footerLabel->setStyleSheet("color: #666; margin-top: 20px;");
    mainLayout->addWidget(footerLabel); // Add footer to larger main Layout






    // ---------------------------------------------------------

    // Connect buttons to corresponding signals
    connect(startConsultationButton, &QPushButton::clicked, this, &DashboardView::startConsultationClicked);
    connect(accessProfileButton, &QPushButton::clicked, this, &DashboardView::accessProfileClicked);
    connect(bookAppointmentButton, &QPushButton::clicked, this, &DashboardView::bookAppointmentClicked);
    connect(viewRecordsButton, &QPushButton::clicked, this, &DashboardView::viewRecordsClicked);
    connect(refillPrescriptionButton, &QPushButton::clicked, this, &DashboardView::refillPrescriptionClicked);
    connect(accessProfileButton, &QPushButton::clicked, this, &DashboardView::profileClicked);
    
    connect(languageButton, &QPushButton::clicked, this, &DashboardView::languageButtonClicked);

}




// Apply styles to dashbaord widgets
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


    // Apply the button style to various buttons
    startConsultationButton->setStyleSheet(buttonStyle);
    accessProfileButton->setStyleSheet(buttonStyle);
    bookAppointmentButton->setStyleSheet(buttonStyle);
    viewRecordsButton->setStyleSheet(buttonStyle);
    refillPrescriptionButton->setStyleSheet(buttonStyle);
    languageButton->setStyleSheet(languageButtonStyle);

}







// Helper function to create a styled group boxex ( text and button in one layout)
QGroupBox* DashboardView::createStyledGroupBox(const QString &title, const QString &description, QPushButton *button) {
    
    QGroupBox *groupBox = new QGroupBox(this); // Create groupBox
    QVBoxLayout *layout = new QVBoxLayout(groupBox); // Make groupbox a layout

    //Add titles label for groupBox
    QLabel *titleLabel = new QLabel(title, groupBox);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");
    
    // Add a description label for groupBox with dynamic wrap
    QLabel *descLabel = new QLabel(description, groupBox);
    descLabel->setWordWrap(true);
    descLabel->setStyleSheet("color: #666; margin-bottom: 15px;");

    //Add Titles, desc and button to the layout
    layout->addWidget(titleLabel);
    layout->addWidget(descLabel);
    layout->addWidget(button);
    layout->addStretch();

    // Style the groupbox
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