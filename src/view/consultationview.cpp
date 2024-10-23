#include "consultationview.h"
#include <QFrame>
#include <QGroupBox>

ConsultationView::ConsultationView(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void ConsultationView::setupUI() {
    // Create main horizontal layout
    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    
    // Create left and right sections
    leftSection = new QWidget(this);
    rightSection = new QWidget(this);
    leftLayout = new QVBoxLayout(leftSection);
    rightLayout = new QVBoxLayout(rightSection);
    
    // Set up individual areas
    setupVideoArea();
    setupControlsArea();
    setupChatArea();
    setupNotesArea();
    
    // Add sections to main layout
    mainLayout->addWidget(leftSection, 7);  // Video takes more space
    mainLayout->addWidget(rightSection, 3);  // Chat/Notes take less space
    
    setLayout(mainLayout);
}

void ConsultationView::setupVideoArea() {
    // Doctor name label
    m_doctorNameLabel = new QLabel(this);
    m_doctorNameLabel->setAlignment(Qt::AlignCenter);
    m_doctorNameLabel->setStyleSheet(
        "QLabel { font-size: 18px; font-weight: bold; color: #2c3e50; padding: 10px; }"
    );
    leftLayout->addWidget(m_doctorNameLabel);
    
    // Video area
    m_videoArea = new QLabel(this);
    m_videoArea->setMinimumSize(800, 450);
    m_videoArea->setStyleSheet(
        "QLabel { background-color: #2c3e50; color: white; border-radius: 8px; }"
    );
    m_videoArea->setAlignment(Qt::AlignCenter);
    m_videoArea->setText("Video Feed");
    leftLayout->addWidget(m_videoArea, 1);
}

void ConsultationView::setupControlsArea() {
    auto controlsLayout = new QHBoxLayout();
    controlsLayout->setSpacing(10);
    controlsLayout->setAlignment(Qt::AlignCenter);
    
    // Create buttons with icons
    m_muteButton = new QPushButton("Mute", this);
    m_stopVideoButton = new QPushButton("Stop Video", this);
    m_endCallButton = new QPushButton("End Call", this);
    
    // Style buttons
    QString normalButtonStyle = 
        "QPushButton { padding: 8px 16px; border-radius: 4px; "
        "background-color: #f8f9fa; border: 1px solid #dee2e6; }";
    QString endCallButtonStyle = 
        "QPushButton { padding: 8px 16px; border-radius: 4px; "
        "background-color: #dc3545; color: white; border: none; }";
    
    m_muteButton->setStyleSheet(normalButtonStyle);
    m_stopVideoButton->setStyleSheet(normalButtonStyle);
    m_endCallButton->setStyleSheet(endCallButtonStyle);
    
    controlsLayout->addWidget(m_muteButton);
    controlsLayout->addWidget(m_stopVideoButton);
    controlsLayout->addWidget(m_endCallButton);
    
    leftLayout->addLayout(controlsLayout);
}

void ConsultationView::setupChatArea() {
    // Chat group box
    m_chatBox = new QGroupBox("Chat", this);
    m_chatBox->setStyleSheet(
        "QGroupBox { font-weight: bold; border: 1px solid #dee2e6; border-radius: 4px; margin-top: 1ex; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 5px; }"
    );
    
    auto chatLayout = new QVBoxLayout(m_chatBox);
    
    m_chatArea = new QTextEdit(this);
    m_chatArea->setReadOnly(true);
    m_chatArea->setStyleSheet(
        "QTextEdit { border: none; background-color: white; }"
    );
    m_chatArea->setText("Dr. Smith: Hello! How are you feeling today?\n\nYou: I've been having some headaches lately.");
    
    chatLayout->addWidget(m_chatArea);
    rightLayout->addWidget(m_chatBox, 2);  // Chat takes more space in right section
}

void ConsultationView::setupNotesArea() {
    // Notes group box
    m_notesBox = new QGroupBox("Consultation Notes", this);
    m_notesBox->setStyleSheet(
        "QGroupBox { font-weight: bold; border: 1px solid #dee2e6; border-radius: 4px; margin-top: 1ex; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top left; padding: 0 5px; }"
    );
    
    auto notesLayout = new QVBoxLayout(m_notesBox);
    
    m_notesArea = new QTextEdit(this);
    m_notesArea->setReadOnly(true);
    m_notesArea->setStyleSheet(
        "QTextEdit { border: none; background-color: white; }"
    );
    m_notesArea->setPlaceholderText("The doctor is taking notes. You'll be able to view these after the consultation.");
    
    notesLayout->addWidget(m_notesArea);
    rightLayout->addWidget(m_notesBox, 1);  // Notes takes less space in right section
    
    // Connect signals
    connect(m_muteButton, &QPushButton::clicked, this, &ConsultationView::muteClicked);
    connect(m_stopVideoButton, &QPushButton::clicked, this, &ConsultationView::stopVideoClicked);
    connect(m_endCallButton, &QPushButton::clicked, this, &ConsultationView::endCallClicked);
}

void ConsultationView::setDoctorName(const QString& name) {
    m_doctorNameLabel->setText("Consultation with " + name);
}