#include "doctorsearchview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDate>
#include <QMessageBox>
#include <QRandomGenerator>

DoctorSearchView::DoctorSearchView(QWidget *parent) : QWidget(parent)
{
    createLayout();
    setupTimeSlots();
}

void DoctorSearchView::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    backButton = new QPushButton("← Back", this);
    mainLayout->addWidget(backButton);

    QLabel *titleLabel = new QLabel("Doctor Availability Schedule", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    mainLayout->addWidget(titleLabel);

    doctorComboBox = new QComboBox(this);
    doctorComboBox->addItem("Choose a doctor");
    mainLayout->addWidget(doctorComboBox);

    calendarWidget = new QCalendarWidget(this);
    mainLayout->addWidget(calendarWidget);

    dateLabel = new QLabel(this);
    mainLayout->addWidget(dateLabel);

    timeSlotsLayout = new QGridLayout();
    mainLayout->addLayout(timeSlotsLayout);

    confirmButton = new QPushButton("Confirm Selection", this);
    confirmButton->setEnabled(false);
    mainLayout->addWidget(confirmButton);

    connect(backButton, &QPushButton::clicked, this, &DoctorSearchView::backToDashboard);
    connect(doctorComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &DoctorSearchView::onDoctorSelectionChanged);
    connect(calendarWidget, &QCalendarWidget::selectionChanged, this, &DoctorSearchView::onDateChanged);
    connect(confirmButton, &QPushButton::clicked, this, &DoctorSearchView::onConfirmClicked);
}


void DoctorSearchView::setupTimeSlots()
{
    QStringList timeSlots = {"09:00 AM", "09:30 AM", "10:00 AM", "10:30 AM", "11:00 AM", "11:30 AM",
                             "02:00 PM", "02:30 PM", "03:00 PM", "03:30 PM", "04:00 PM", "04:30 PM"};

    int row = 0, col = 0;
    for (const QString &time : timeSlots) {
        QPushButton *slot = new QPushButton(time, this);
        slot->setCheckable(true);
        connect(slot, &QPushButton::clicked, this, &DoctorSearchView::onTimeSlotClicked);
        timeSlotsLayout->addWidget(slot, row, col);
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }
}

void DoctorSearchView::updateDoctorList(const QStringList &doctors)
{
    doctorComboBox->clear();
    doctorComboBox->addItem("Choose a doctor");
    doctorComboBox->addItems(doctors);
}

void DoctorSearchView::onDoctorSelectionChanged(int index)
{
    if (index > 0) {
        selectedDoctor = doctorComboBox->currentText();
        updateAvailableTimeSlots();
    } else {
        selectedDoctor.clear();
    }
}

void DoctorSearchView::onDateChanged()
{
    selectedDate = calendarWidget->selectedDate();
    dateLabel->setText(selectedDate.toString("dddd, MMMM d, yyyy"));
    updateAvailableTimeSlots();
}

void DoctorSearchView::onTimeSlotClicked()
{
    QPushButton *clickedSlot = qobject_cast<QPushButton*>(sender());
    if (clickedSlot) {
        for (int i = 0; i < timeSlotsLayout->count(); ++i) {
            QPushButton *slot = qobject_cast<QPushButton*>(timeSlotsLayout->itemAt(i)->widget());
            if (slot && slot != clickedSlot) {
                slot->setChecked(false);
            }
        }
        selectedTime = clickedSlot->text();
        confirmButton->setEnabled(true);
    }
}

void DoctorSearchView::onConfirmClicked()
{
    if (selectedDoctor.isEmpty() || !selectedDate.isValid() || selectedTime.isEmpty()) {
        QMessageBox::warning(this, "Incomplete Selection", "Please select a doctor, date, and time slot.");
        return;
    }

    emit appointmentConfirmed(selectedDoctor, selectedDate, selectedTime);
}

void DoctorSearchView::updateAvailableTimeSlots()
{
    // In a real application, this would fetch availability data from a model or API
    // For now, we'll just randomly set some slots as unavailable
    for (int i = 0; i < timeSlotsLayout->count(); ++i) {
        QPushButton *slot = qobject_cast<QPushButton*>(timeSlotsLayout->itemAt(i)->widget());
        if (slot) {
            bool available = (QRandomGenerator::global()->generate() % 2 == 0);
            slot->setEnabled(available);
            slot->setStyleSheet(available ? "background-color: #d1fae5;" : "background-color: #fee2e2;");
        }
    }
}