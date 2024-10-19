#include "appointmentview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>

AppointmentView::AppointmentView(QWidget *parent) : QWidget(parent) {
    createLayout();
}

void AppointmentView::createLayout() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    backButton = new QPushButton("← Back", this);
    backButton->setStyleSheet("background-color: transparent; border: none; font-weight: bold;");
    headerLayout->addWidget(backButton, 0, Qt::AlignLeft);

    QLabel *titleLabel = new QLabel("Manage Your Appointments", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    headerLayout->addWidget(titleLabel, 1, Qt::AlignCenter);

    makeNewButton = new QPushButton("+ Make New", this);
    makeNewButton->setStyleSheet("background-color: #007bff; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    headerLayout->addWidget(makeNewButton, 0, Qt::AlignRight);

    mainLayout->addLayout(headerLayout);

    // Appointment List
    appointmentList = new QListWidget(this);
    appointmentList->setStyleSheet("QListWidget { border: none; } QListWidget::item { padding: 10px; }");
    mainLayout->addWidget(appointmentList);

    // Stacked widget (keeping it for potential future use)
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(appointmentList);
    mainLayout->addWidget(stackedWidget);

    connect(backButton, &QPushButton::clicked, this, &AppointmentView::backToDashboard);
    connect(makeNewButton, &QPushButton::clicked, this, &AppointmentView::makeNewAppointment);
}

void AppointmentView::updateAppointmentList(const QList<AppointmentModel>& appointments) {
    appointmentList->clear();
    for (const auto &appointment : appointments) {
        createAppointmentWidget(appointment);
    }
}

void AppointmentView::createAppointmentWidget(const AppointmentModel &appointment) {
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QHBoxLayout *infoLayout = new QHBoxLayout();
    
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(new QLabel(appointment.getDoctor(), widget));
    leftLayout->addWidget(new QLabel(appointment.getDate().toString("yyyy-MM-dd"), widget));
    leftLayout->addWidget(new QLabel(appointment.getTime().toString("hh:mm AP"), widget));
    leftLayout->addWidget(new QLabel(appointment.getDescription(), widget));
    infoLayout->addLayout(leftLayout);

    QVBoxLayout *buttonLayout = new QVBoxLayout();
    QPushButton *rescheduleButton = new QPushButton("Reschedule", widget);
    rescheduleButton->setStyleSheet("background-color: #007bff; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    QPushButton *cancelButton = new QPushButton("✕", widget);
    cancelButton->setStyleSheet("background-color: #dc3545; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    buttonLayout->addWidget(rescheduleButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addStretch();
    infoLayout->addLayout(buttonLayout);

    layout->addLayout(infoLayout);

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    QListWidgetItem *item = new QListWidgetItem(appointmentList);
    item->setSizeHint(widget->sizeHint());
    appointmentList->addItem(item);
    appointmentList->setItemWidget(item, widget);

    connect(rescheduleButton, &QPushButton::clicked, this, [this, id = appointment.getId()]() {
        emit rescheduleRequested(id);
    });
    connect(cancelButton, &QPushButton::clicked, this, [this, id = appointment.getId()]() {
        emit cancelRequested(id);
    });
}