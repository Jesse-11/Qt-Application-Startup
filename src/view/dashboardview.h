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
    void languageSelectionClicked();
    void languageButtonClicked();

private:
    QLabel *welcomeLabel;
    QPushButton *startConsultationButton;
    QPushButton *accessProfileButton;
    QPushButton *bookAppointmentButton;
    QPushButton *viewRecordsButton;
    QPushButton *refillPrescriptionButton;
    QPushButton *languageButton;


    void createLayout();
    void styleWidgets();
    QGroupBox* createStyledGroupBox(const QString &title, const QString &description, QPushButton *button);
};

#endif // DASHBOARDVIEW_H