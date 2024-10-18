#ifndef TELEMEDICINEVIEW_H
#define TELEMEDICINEVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class TelemedicineView : public QWidget {
    Q_OBJECT

public:
    explicit TelemedicineView(QWidget *parent = nullptr);

    void setQueuePositionLabel(const QString& text);
    void setWaitTimeLabel(const QString& text);
    void setDoctorNameLabel(const QString& text);
    void setDoctorSpecialtyLabel(const QString& text);
    void setPreparationLabel(const QString& text);

signals:
    void contactSupportClicked();
    void backToDashboard();

private:
    QLabel *titleLabel;
    QLabel *queuePositionLabel;
    QLabel *waitTimeLabel;
    QLabel *doctorNameLabel;
    QLabel *doctorSpecialtyLabel;
    QLabel *preparationLabel;
    QPushButton *contactSupportButton;
    QPushButton *settingsButton;

    void createLayout();
    QFrame* createEstimatedWaitTimeFrame();
    QFrame* createYourDoctorFrame();
    QFrame* createPrepareConsultationFrame();
    QFrame* createNeedAssistanceFrame();
};

#endif // TELEMEDICINEVIEW_H