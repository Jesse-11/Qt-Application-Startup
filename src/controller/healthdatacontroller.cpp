#include "healthdatacontroller.h"
#include "../view/healthdataview.h"

HealthDataController::HealthDataController(HealthDataView* view, QObject* parent)
    : QObject(parent)
    , view(view)
{
    model = new HealthDataModel(this);
    

    view->setController(this);

    
    connect(view, &HealthDataView::backRequested,
            this, &HealthDataController::backToDashboardRequested);
    connect(view, &HealthDataView::deviceSyncRequested,
            this, &HealthDataController::syncDevice);
    connect(view, &HealthDataView::deviceRemoveRequested,
            this, &HealthDataController::removeDevice);

    updateAllViewData();
}

void HealthDataController::healthdataRequested() {
    updateAllViewData();
}

void HealthDataController::updateMetrics(const HealthMetric& metric) {
    model->addMetric(metric);
    updateAllViewData();
}

HealthMetric HealthDataController::getLatestMetrics() const {
    return model->getLatestMetrics();
}

QVector<HealthMetric> HealthDataController::getWeeklyData() const {
    return model->getWeeklyData();
}

QVector<ConnectedDevice> HealthDataController::getConnectedDevices() const {
    return model->getConnectedDevices();
}

void HealthDataController::addDevice(const ConnectedDevice& device) {
    model->addDevice(device);
    view->refreshDevicesList(model->getConnectedDevices());
}

void HealthDataController::removeDevice(const QString& deviceName) {
    model->removeDevice(deviceName);
    view->refreshDevicesList(model->getConnectedDevices());
}

void HealthDataController::syncDevice(const QString& deviceName) {
    model->syncDevice(deviceName);
    updateAllViewData();
}

void HealthDataController::handleBackRequest() {
    emit backToDashboardRequested();
}

void HealthDataController::updateAllViewData() {
    if (!view) return;

    view->updateMetricsDisplay(model->getLatestMetrics());
    view->updateChartData(model->getWeeklyData());
    view->refreshDevicesList(model->getConnectedDevices());
}