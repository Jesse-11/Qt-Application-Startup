#include "prescriptionview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

PrescriptionView::PrescriptionView(QWidget *parent) : QWidget(parent) {
    createLayout();
}

void PrescriptionView::createLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("Prescription Refill Requests", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    headerLayout->addWidget(titleLabel);
    backButton = new QPushButton("Back to Dashboard", this);
    headerLayout->addWidget(backButton);
    mainLayout->addLayout(headerLayout);

    // Tab buttons
    QHBoxLayout *tabLayout = new QHBoxLayout();
    activeButton = new QPushButton("Active", this);
    pendingButton = new QPushButton("Pending", this);
    historyButton = new QPushButton("History", this);
    tabLayout->addWidget(activeButton);
    tabLayout->addWidget(pendingButton);
    tabLayout->addWidget(historyButton);
    mainLayout->addLayout(tabLayout);

    // Stacked widget for different views
    stackedWidget = new QStackedWidget(this);
    prescriptionList = new QListWidget(this);
    stackedWidget->addWidget(prescriptionList);
    mainLayout->addWidget(stackedWidget);

    connect(backButton, &QPushButton::clicked, this, &PrescriptionView::backToDashboard);
}

void PrescriptionView::updatePrescriptionList(const QList<PrescriptionModel>& prescriptions) {
    prescriptionList->clear();
    for (const auto &prescription : prescriptions) {
        createPrescriptionWidget(prescription);
    }
}

void PrescriptionView::createPrescriptionWidget(const PrescriptionModel &prescription) {
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *nameLabel = new QLabel(prescription.getName(), widget);
    nameLabel->setStyleSheet("font-weight: bold;");
    layout->addWidget(nameLabel);

    layout->addWidget(new QLabel(QString("Dosage: %1").arg(prescription.getDosage()), widget));
    layout->addWidget(new QLabel(QString("Frequency: %1").arg(prescription.getFrequency()), widget));
    layout->addWidget(new QLabel(QString("Last Refill: %1").arg(prescription.getLastRefill().toString("yyyy-MM-dd")), widget));
    layout->addWidget(new QLabel(QString("Refills Remaining: %1").arg(prescription.getRefillsRemaining()), widget));

    QPushButton *refillButton = new QPushButton("Request Refill", widget);
    connect(refillButton, &QPushButton::clicked, this, [this, name = prescription.getName()]() {
        emit refillRequested(name);
    });
    layout->addWidget(refillButton);

    QListWidgetItem *item = new QListWidgetItem(prescriptionList);
    item->setSizeHint(widget->sizeHint());
    prescriptionList->addItem(item);
    prescriptionList->setItemWidget(item, widget);
}