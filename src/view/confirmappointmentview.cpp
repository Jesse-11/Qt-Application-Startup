
#include "confirmappointmentview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

ConfirmAppointmentView::ConfirmAppointmentView(QWidget *parent) : QWidget(parent)
{
    createLayout();
}

void ConfirmAppointmentView::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Confirm Your Appointment", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    mainLayout->addWidget(titleLabel);

    detailsLabel = new QLabel(this);
    detailsLabel->setStyleSheet("font-size: 18px; margin: 20px 0;");
    mainLayout->addWidget(detailsLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    confirmButton = new QPushButton("Confirm", this);
    cancelButton = new QPushButton("Cancel", this);

    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    connect(confirmButton, &QPushButton::clicked, this, &ConfirmAppointmentView::confirmClicked);
    connect(cancelButton, &QPushButton::clicked, this, &ConfirmAppointmentView::cancelClicked);
}

void ConfirmAppointmentView::setAppointmentDetails(const QString &doctor, const QDate &date, const QString &time)
{
    QString details = QString("Doctor: %1\nDate: %2\nTime: %3")
                          .arg(doctor)
                          .arg(date.toString("MMMM d, yyyy"))
                          .arg(time);
    detailsLabel->setText(details);
}