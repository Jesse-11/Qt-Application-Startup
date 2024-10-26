#ifndef HEALTHDATAVIEW_H
#define HEALTHDATAVIEW_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QVector>
#include "../model/healthdatamodel.h"

class HealthDataController;
class QLabel;
class QTabWidget;

QT_CHARTS_USE_NAMESPACE

class HealthDataView : public QWidget {
    Q_OBJECT
public:
    explicit HealthDataView(QWidget *parent = nullptr);
    void setController(HealthDataController* controller);

public slots:
    void refreshDevicesList(const QVector<ConnectedDevice>& devices);
    void updateMetricsDisplay(const HealthMetric& metrics);
    void updateChartData(const QVector<HealthMetric>& weeklyData);

signals:
    void backRequested();
    void deviceSyncRequested(const QString& deviceName);
    void deviceRemoveRequested(const QString& deviceName);

private slots:
    void onSyncButtonClicked();
    void onRemoveButtonClicked();

private:
    void createTabWidget();
    QWidget* createAnalyticsTab();
    QWidget* createDevicesTab();
    void createMetricCards();
    void createChart();
    QWidget* createMetricCard(const QString& title, const QString& value,
                             const QString& subtitle, const QString& iconPath);
    QWidget* createDeviceItem(const ConnectedDevice& device);
    QString getDeviceTypeIcon(const QString& deviceType);
    void refreshView();

    HealthDataController* controller;
    QTabWidget* tabWidget;
    QChartView* chartView;
    QChart* chart;
    QLineSeries* heartRateSeries;
    QLineSeries* stepsSeries;
    QLineSeries* sleepSeries;
};

#endif // HEALTHDATAVIEW_H