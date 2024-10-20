#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDate>
#include "../model/confirmappointmentmodel.h"

class ConfirmAppointmentView : public QWidget
{
    Q_OBJECT

public:
    explicit ConfirmAppointmentView(QWidget *parent = nullptr);
    void setAppointmentDetails(const QString &doctor, const QDate &date, const QString &time);

signals:
    void confirmClicked();
    void cancelClicked();

private:
    QLabel *detailsLabel;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void createLayout();
};