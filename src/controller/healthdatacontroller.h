#ifndef HEALTHDATACONTROLLER_H
#define HEALTHDATACONTROLLER_H

#include <QObject>
#include "../model/healthdatamodel.h"

class HealthDataView;

class HealthDataController : public QObject {
    Q_OBJECT
public:
    explicit HealthDataController(HealthDataView* view, QObject* parent = nullptr);

signals:
    void backToDashboardRequested();

public slots:
    void healthdataRequested();
    void updateMetrics(const HealthMetric& metric);
    HealthMetric getLatestMetrics() const;
    QVector<HealthMetric> getWeeklyData() const;
    QVector<ConnectedDevice> getConnectedDevices() const;
    void addDevice(const ConnectedDevice& device);
    void removeDevice(const QString& deviceName);
    void syncDevice(const QString& deviceName);
    void handleBackRequest();

private:
    void updateAllViewData();
    HealthDataModel* model;
    HealthDataView* view;
};

#endif // HEALTHDATACONTROLLER_H