#include "healthdatamodel.h"
#include <QDebug>
#include <QDateTime>

HealthDataModel::HealthDataModel(QObject *parent) : QObject(parent) {
    // Initialize random seed
    qsrand(QDateTime::currentDateTime().toSecsSinceEpoch());
    qDebug() << "Initializing HealthDataModel...";
    initializeSampleData();
    initializeSampleDevices();
}

void HealthDataModel::initializeSampleData() {
    QDate currentDate = QDate::currentDate();
    qDebug() << "Creating sample data starting from:" << currentDate;
    
    m_weeklyData.clear(); // Clear any existing data
    
    for (int i = 6; i >= 0; --i) {
        HealthMetric metric;
        metric.date = currentDate.addDays(-i);
        metric.heartRate = 70 + qrand() % 5;
        metric.steps = 9000 + qrand() % 2000;
        metric.weight = 70 + (qrand() % 10) / 10.0;
        metric.sleepHours = 7.5 + (qrand() % 10) / 10.0;
        m_weeklyData.append(metric);
        
        qDebug() << "Added data point -" 
                 << "Date:" << metric.date.toString()
                 << "HR:" << metric.heartRate
                 << "Steps:" << metric.steps
                 << "Weight:" << metric.weight
                 << "Sleep:" << metric.sleepHours;
    }
    qDebug() << "Total data points created:" << m_weeklyData.size();
}

void HealthDataModel::initializeSampleDevices() {
    qDebug() << "Initializing sample devices...";
    m_connectedDevices.clear(); // Clear existing devices

    ConnectedDevice phone;
    phone.type = "Smartphone";
    phone.name = "iPhone 13";
    phone.lastSync = "10 minutes ago";
    phone.dataTypes = "Data: Steps, Active Minutes, Sleep";
    m_connectedDevices.append(phone);

    ConnectedDevice watch;
    watch.type = "Smartwatch";
    watch.name = "Fitbit Versa 3";
    watch.lastSync = "1 hour ago";
    watch.dataTypes = "Data: Heart Rate, Steps, Sleep, Active Minutes";
    m_connectedDevices.append(watch);

    ConnectedDevice scale;
    scale.type = "Smart Scale";
    scale.name = "Withings Body+";
    scale.lastSync = "2 days ago";
    scale.dataTypes = "Data: Weight, Body Fat %, BMI";
    m_connectedDevices.append(scale);

    ConnectedDevice thermometer;
    thermometer.type = "Smart Thermometer";
    thermometer.name = "Kinsa Smart Thermometer";
    thermometer.lastSync = "1 week ago";
    thermometer.dataTypes = "Data: Body Temperature";
    m_connectedDevices.append(thermometer);

    qDebug() << "Added" << m_connectedDevices.size() << "sample devices";
}

QVector<HealthMetric> HealthDataModel::getWeeklyData() const {
    qDebug() << "Returning" << m_weeklyData.size() << "weekly data points";
    return m_weeklyData;
}

HealthMetric HealthDataModel::getLatestMetrics() const {
    if (m_weeklyData.isEmpty()) {
        qDebug() << "Warning: No metrics available, returning empty metric";
        return HealthMetric();
    }
    qDebug() << "Returning latest metrics from:" << m_weeklyData.last().date.toString();
    return m_weeklyData.last();
}

QVector<ConnectedDevice> HealthDataModel::getConnectedDevices() const {
    qDebug() << "Returning" << m_connectedDevices.size() << "connected devices";
    return m_connectedDevices;
}

void HealthDataModel::addMetric(const HealthMetric& metric) {
    m_weeklyData.append(metric);
    if (m_weeklyData.size() > 7) {
        m_weeklyData.removeFirst();
    }
    qDebug() << "Added new metric, total count:" << m_weeklyData.size();
}

void HealthDataModel::addDevice(const ConnectedDevice& device) {
    m_connectedDevices.append(device);
    qDebug() << "Added new device:" << device.name;
}

void HealthDataModel::removeDevice(const QString& deviceName) {
    for (int i = 0; i < m_connectedDevices.size(); ++i) {
        if (m_connectedDevices[i].name == deviceName) {
            m_connectedDevices.removeAt(i);
            qDebug() << "Removed device:" << deviceName;
            break;
        }
    }
}

void HealthDataModel::syncDevice(const QString& deviceName) {
    for (auto& device : m_connectedDevices) {
        if (device.name == deviceName) {
            device.lastSync = "Just now";
            qDebug() << "Synced device:" << deviceName;
            break;
        }
    }
}