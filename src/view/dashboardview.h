#ifndef DASHBOARDVIEW_H
#define DASHBOARDVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

class DashboardView : public QWidget {
    Q_OBJECT

public:
    explicit DashboardView(QWidget *parent = nullptr);
    void setWelcomeMessage(const QString &message);

signals:
    void startConsultationClicked();
    void accessProfileClicked();
    void bookAppointmentClicked();
    void viewRecordsClicked();
    void refillPrescriptionClicked();

private:
    QLabel *welcomeLabel;
    QLabel *logoLabel;
    QPushButton *startConsultationButton;
    QPushButton *accessProfileButton;
    QPushButton *bookAppointmentButton;
    QPushButton *viewRecordsButton;
    QPushButton *refillPrescriptionButton;


    void createLayout();
    void styleWidgets();
    QGroupBox* createStyledGroupBox(const QString &title, const QString &description, QPushButton *button);
};

#endif // DASHBOARDVIEW_H