#pragma once
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "../model/appointmentmodel.h"

class AppointmentView : public QWidget {
    Q_OBJECT

public:
    explicit AppointmentView(QWidget *parent = nullptr);
    void updateAppointmentList(const QList<AppointmentModel>& appointments);

signals:
    void rescheduleRequested(const QString &appointmentId);
    void cancelRequested(const QString &appointmentId);
    void backToDashboard();
    void makeNewAppointment();

private:
    QListWidget *appointmentList;
    QPushButton *backButton;
    QPushButton *makeNewButton;
    QStackedWidget *stackedWidget;

    void createLayout();
    void createAppointmentWidget(const AppointmentModel &appointment);
};