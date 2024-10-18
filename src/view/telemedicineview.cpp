#include "telemedicineview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QListWidget>

TelemedicineView::TelemedicineView(QWidget *parent) : QWidget(parent) {
    createLayout();
}

void TelemedicineView::createLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    titleLabel = new QLabel("Telemedicine Consultation Queue", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    settingsButton = new QPushButton(this);
    settingsButton->setIcon(QIcon(":resources/images/settings.png"));
    settingsButton->setFixedSize(32, 32);
    settingsButton->setStyleSheet("border: none; background: transparent;");

    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(settingsButton);

    mainLayout->addLayout(headerLayout);

    // Content area
    QHBoxLayout *contentLayout = new QHBoxLayout();

    // Left column
    QVBoxLayout *leftColumnLayout = new QVBoxLayout();
    leftColumnLayout->addWidget(createEstimatedWaitTimeFrame());
    leftColumnLayout->addWidget(createPrepareConsultationFrame());
    contentLayout->addLayout(leftColumnLayout);

    // Right column
    QVBoxLayout *rightColumnLayout = new QVBoxLayout();
    rightColumnLayout->addWidget(createYourDoctorFrame());
    rightColumnLayout->addWidget(createNeedAssistanceFrame());
    contentLayout->addLayout(rightColumnLayout);

    mainLayout->addLayout(contentLayout);

    // Footer
    QLabel *footerLabel = new QLabel("Stay on this page. You will be automatically connected when the doctor is ready.", this);
    footerLabel->setAlignment(Qt::AlignCenter);
    footerLabel->setStyleSheet("color: gray;");
    mainLayout->addWidget(footerLabel);

    setLayout(mainLayout);
}

QFrame* TelemedicineView::createEstimatedWaitTimeFrame() {
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setStyleSheet("QFrame { background-color: white; border-radius: 8px; }");

    QVBoxLayout *layout = new QVBoxLayout(frame);

    QHBoxLayout *iconAndTitleLayout = new QHBoxLayout();
    QLabel *clockIcon = new QLabel("🕒", this);
    clockIcon->setStyleSheet("font-size: 18px;");
    QLabel *title = new QLabel("Estimated Wait Time", this);
    title->setStyleSheet("font-weight: bold;");
    iconAndTitleLayout->addWidget(clockIcon);
    iconAndTitleLayout->addWidget(title);
    iconAndTitleLayout->addStretch();

    waitTimeLabel = new QLabel("12 minutes", this);
    waitTimeLabel->setStyleSheet("font-size: 36px; color: #4a90e2; font-weight: bold;");
    waitTimeLabel->setAlignment(Qt::AlignCenter);

    queuePositionLabel = new QLabel("Your position in queue: 3", this);
    queuePositionLabel->setStyleSheet("color: gray;");
    queuePositionLabel->setAlignment(Qt::AlignCenter);

    layout->addLayout(iconAndTitleLayout);
    layout->addWidget(waitTimeLabel);
    layout->addWidget(queuePositionLabel);

    return frame;
}

QFrame* TelemedicineView::createYourDoctorFrame() {
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setStyleSheet("QFrame { background-color: white; border-radius: 8px; }");

    QVBoxLayout *layout = new QVBoxLayout(frame);

    QHBoxLayout *iconAndTitleLayout = new QHBoxLayout();
    QLabel *doctorIcon = new QLabel("👤", this);
    doctorIcon->setStyleSheet("font-size: 18px;");
    QLabel *title = new QLabel("Your Doctor", this);
    title->setStyleSheet("font-weight: bold;");
    iconAndTitleLayout->addWidget(doctorIcon);
    iconAndTitleLayout->addWidget(title);
    iconAndTitleLayout->addStretch();

    QHBoxLayout *doctorInfoLayout = new QHBoxLayout();
    QLabel *avatarLabel = new QLabel(this);
    avatarLabel->setFixedSize(64, 64);
    avatarLabel->setStyleSheet("background-color: lightgray; border-radius: 32px;");
    QVBoxLayout *doctorDetailsLayout = new QVBoxLayout();
    doctorNameLabel = new QLabel("Dr. Jane Smith", this);
    doctorSpecialtyLabel = new QLabel("General Practitioner", this);
    doctorSpecialtyLabel->setStyleSheet("color: gray;");
    doctorDetailsLayout->addWidget(doctorNameLabel);
    doctorDetailsLayout->addWidget(doctorSpecialtyLabel);
    doctorInfoLayout->addWidget(avatarLabel);
    doctorInfoLayout->addLayout(doctorDetailsLayout);

    layout->addLayout(iconAndTitleLayout);
    layout->addLayout(doctorInfoLayout);

    return frame;
}

QFrame* TelemedicineView::createPrepareConsultationFrame() {
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setStyleSheet("QFrame { background-color: white; border-radius: 8px; }");

    QVBoxLayout *layout = new QVBoxLayout(frame);

    QHBoxLayout *iconAndTitleLayout = new QHBoxLayout();
    QLabel *prepareIcon = new QLabel("📋", this);
    prepareIcon->setStyleSheet("font-size: 18px;");
    preparationLabel = new QLabel("Prepare for Your Consultation", this);
    preparationLabel->setStyleSheet("font-weight: bold;");
    iconAndTitleLayout->addWidget(prepareIcon);
    iconAndTitleLayout->addWidget(preparationLabel);
    iconAndTitleLayout->addStretch();

    QListWidget *prepStepsList = new QListWidget(this);
    prepStepsList->addItem("Ensure your device is charged and connected to stable internet");
    prepStepsList->addItem("Find a quiet, well-lit space for your consultation");
    prepStepsList->addItem("Have your medical history and current medications list ready");
    prepStepsList->addItem("Prepare any questions you want to ask your doctor");
    prepStepsList->setStyleSheet("QListWidget { border: none; }");

    layout->addLayout(iconAndTitleLayout);
    layout->addWidget(prepStepsList);

    return frame;
}

QFrame* TelemedicineView::createNeedAssistanceFrame() {
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setStyleSheet("QFrame { background-color: white; border-radius: 8px; }");

    QVBoxLayout *layout = new QVBoxLayout(frame);

    QLabel *title = new QLabel("Need Assistance?", this);
    title->setStyleSheet("font-weight: bold;");

    QLabel *assistanceText = new QLabel("If you're experiencing technical difficulties or need to reschedule:", this);
    assistanceText->setWordWrap(true);

    contactSupportButton = new QPushButton("Contact Support", this);
    contactSupportButton->setStyleSheet("background-color: #333; color: white; padding: 10px;");

    layout->addWidget(title);
    layout->addWidget(assistanceText);
    layout->addWidget(contactSupportButton);

    return frame;
}

void TelemedicineView::setQueuePositionLabel(const QString& text) {
    if (queuePositionLabel) {
        queuePositionLabel->setText(text);
    }
}

void TelemedicineView::setWaitTimeLabel(const QString& text) {
    if (waitTimeLabel) {
        waitTimeLabel->setText(text);
    }
}

void TelemedicineView::setDoctorNameLabel(const QString& text) {
    if (doctorNameLabel) {
        doctorNameLabel->setText(text);
    }
}

void TelemedicineView::setDoctorSpecialtyLabel(const QString& text) {
    if (doctorSpecialtyLabel) {
        doctorSpecialtyLabel->setText(text);
    }
}

void TelemedicineView::setPreparationLabel(const QString& text) {
    if (preparationLabel) {
        preparationLabel->setText(text);
    }
}