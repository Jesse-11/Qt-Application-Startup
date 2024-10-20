#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>

class DoctorSearchView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorSearchView(QWidget *parent = nullptr);
    void updateDoctorList(const QStringList &doctors);

signals:
    void backToDashboard();
    void appointmentConfirmed(const QString &doctor, const QDate &date, const QString &time);

private slots:
    void onDoctorSelectionChanged(int index);
    void onDateChanged();
    void onTimeSlotClicked();
    void onConfirmClicked();

private:
    QComboBox *doctorComboBox;
    QCalendarWidget *calendarWidget;
    QGridLayout *timeSlotsLayout;
    QPushButton *confirmButton;
    QPushButton *backButton;
    QLabel *dateLabel;

    QString selectedDoctor;
    QDate selectedDate;
    QString selectedTime;

    void createLayout();
    void setupTimeSlots();
    void updateAvailableTimeSlots();
};
