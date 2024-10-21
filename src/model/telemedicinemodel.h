

#ifndef TELEMEDICINEMODEL_H
#define TELEMEDICINEMODEL_H

#include <QString>
#include <QVector>

class TelemedicineModel {
public:
    TelemedicineModel()=default;
    TelemedicineModel(int initialQueuePosition, int initialWaitTime,
                      const QString &doctor, const QString &specialty);

    
    
    int getQueuePosition() const;
    int getEstimatedWaitTime() const;
    QString getDoctorName() const;
    QString getDoctorSpecialty() const;
    QVector<QString> getPreparationSteps() const;

   
    void setQueuePosition(int position);
    void updateEstimatedWaitTime();

    
    void moveUpInQueue();
    bool isReadyForConsultation() const;

private:
    int queuePosition;
    int estimatedWaitTime; 
    QString doctorName;
    QString doctorSpecialty;
    QVector<QString> preparationSteps;


    void calculateEstimatedWaitTime();
};

#endif