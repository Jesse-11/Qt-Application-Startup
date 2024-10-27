#ifndef HEALTHDATAMODEL_H
#define HEALTHDATAMODEL_H

#include <QObject>
#include <QVector>
#include <QDate>
#include <QString>

class HealthMetric {
    Q_GADGET
public:
    QDate date;
    double heartRate;
    int steps;
    double weight;
    double sleepHours;
};

class ConnectedDevice {
    Q_GADGET
public:
    QString type;
    QString name;
    QString lastSync;
    QString dataTypes;
};

class HealthDataModel : public QObject {
    Q_OBJECT
public:
    explicit HealthDataModel(QObject *parent = nullptr);
    QVector<HealthMetric> getWeeklyData() const;
    HealthMetric getLatestMetrics() const;
    QVector<ConnectedDevice> getConnectedDevices() const;
    void addMetric(const HealthMetric& metric);
    void addDevice(const ConnectedDevice& device);
    void removeDevice(const QString& deviceName);
    void syncDevice(const QString& deviceName);

private:
    QVector<HealthMetric> m_weeklyData;
    QVector<ConnectedDevice> m_connectedDevices;
    void initializeSampleData();
    void initializeSampleDevices();
};

#endif // HEALTHDATAMODEL_H