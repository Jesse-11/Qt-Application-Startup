#ifndef TELEMEDICINEMODEL_H
#define TELEMEDICINEMODEL_H

#include <QString>
#include <QVector>
#include <QObject>
#include <QTimer>

class TelemedicineModel : public QObject {
    Q_OBJECT  // Required for signals and slots

public:
    TelemedicineModel(QObject *parent = nullptr);
    TelemedicineModel(int initialQueuePosition, int initialWaitTime,
                    const QString &doctor, const QString &specialty,
                    QObject *parent = nullptr);

    int getQueuePosition() const;
    int getEstimatedWaitTime() const;
    QString getDoctorName() const;
    QString getDoctorSpecialty() const;
    QVector<QString> getPreparationSteps() const;

    void setQueuePosition(int position);
    void updateEstimatedWaitTime();
    void moveUpInQueue();
    bool isReadyForConsultation() const;

    void startQueueTimer();
    void stopQueueTimer();

signals:
    void queuePositionChanged(int newPosition);
    void consultationReady();
    void estimatedWaitTimeChanged(int newTime);

private slots:
    void onQueueTimerTimeout();
    void onConsultationTimerTimeout();

private:
    int queuePosition;
    int estimatedWaitTime;
    QString doctorName;
    QString doctorSpecialty;
    QVector<QString> preparationSteps;

    QTimer *queueTimer;
    QTimer *consultationTimer;
    void calculateEstimatedWaitTime();
    void setupTimers();
};

#endif