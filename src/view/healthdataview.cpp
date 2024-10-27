#include "healthdataview.h"
#include "../controller/healthdatacontroller.h"
#include "../model/healthdatamodel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QFont>
#include <QTabWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QPainter>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

HealthDataView::HealthDataView(QWidget *parent)
    : QWidget(parent)
    , controller(nullptr)
    , tabWidget(nullptr)
    , chartView(nullptr)
    , chart(nullptr)
    , heartRateSeries(nullptr)
    , stepsSeries(nullptr)
    , sleepSeries(nullptr)
{
    setStyleSheet("background-color: white;");
    
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget(this);
    mainLayout->addWidget(tabWidget);
}

void HealthDataView::setController(HealthDataController* newController) {
    qDebug() << "Setting controller in HealthDataView";
    controller = newController;
    refreshView();
}

void HealthDataView::refreshView() {
    qDebug() << "Refreshing view with controller:" << (controller ? "valid" : "null");
    if (!controller) return;

    while (tabWidget->count() > 0) {
        tabWidget->removeTab(0);
    }

    
    tabWidget->addTab(createAnalyticsTab(), "Health Analytics");
    tabWidget->addTab(createDevicesTab(), "Connected Devices");
}

QWidget* HealthDataView::createAnalyticsTab() {
    QWidget* analyticsTab = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(analyticsTab);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(16, 16, 16, 16);
    
    
    QFrame* topBar = new QFrame();
    topBar->setStyleSheet(
        "QFrame {"
        "   background-color: white;"
        "   border-bottom: 1px solid #e0e0e0;"
        "   margin-bottom: 10px;"
        "}"
    );
    QHBoxLayout* topBarLayout = new QHBoxLayout(topBar);
    topBarLayout->setContentsMargins(0, 0, 0, 10);  
    
    QPushButton* backButton = new QPushButton("← Back to Dashboard");
    backButton->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   border: none;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   color: #2196F3;"  
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   text-align: left;"
        "}"
        "QPushButton:hover {"
        "   background-color: #f0f0f0;"
        "}"
    );
    connect(backButton, &QPushButton::clicked, this, &HealthDataView::backRequested);
    
    topBarLayout->addWidget(backButton);
    topBarLayout->addStretch();
    

    mainLayout->addWidget(topBar);
    
    QHBoxLayout* headerLayout = new QHBoxLayout();
    QLabel* titleLabel = new QLabel("Health Data Overview");
    titleLabel->setStyleSheet(
        "font-size: 18px;"
        "font-weight: bold;"
        "margin-top: 10px;"
    );
    headerLayout->addWidget(titleLabel);
    
    QLabel* detailsLink = new QLabel("Detailed Reports");
    detailsLink->setStyleSheet(
        "color: #2196F3;"
        "text-decoration: underline;"
        "cursor: pointer;"
    );
    headerLayout->addStretch();
    headerLayout->addWidget(detailsLink);
    mainLayout->addLayout(headerLayout);
    
    if (controller) {
        // Metrics Cards
        auto metrics = controller->getLatestMetrics();
        QHBoxLayout* cardsLayout = new QHBoxLayout();
        cardsLayout->setSpacing(16);
        
        cardsLayout->addWidget(createMetricCard("Heart Rate", 
            QString::number(metrics.heartRate, 'f', 0) + " bpm",
            "Average last 7 days", ":/icons/heart.svg"));
        cardsLayout->addWidget(createMetricCard("Daily Steps",
            QString::number(metrics.steps),
            "Average last 7 days", ":/icons/steps.svg"));
        cardsLayout->addWidget(createMetricCard("Weight",
            QString::number(metrics.weight, 'f', 1) + " kg",
            "Last recorded", ":/icons/weight.svg"));
        cardsLayout->addWidget(createMetricCard("Sleep",
            QString::number(metrics.sleepHours, 'f', 1) + " hrs",
            "Average last 7 days", ":/icons/sleep.svg"));
            
        mainLayout->addLayout(cardsLayout);
    }
    
    // Chart Section
    QLabel* trendsLabel = new QLabel("Weekly Health Trends");
    trendsLabel->setStyleSheet("font-size: 16px; font-weight: bold; margin-top: 20px;");
    mainLayout->addWidget(trendsLabel);
    
    QFrame* chartFrame = new QFrame();
    chartFrame->setFrameStyle(QFrame::StyledPanel);
    chartFrame->setMinimumHeight(500);
    chartFrame->setStyleSheet(
        "QFrame {"
        "   background-color: white;"
        "   border: 1px solid #e0e0e0;"
        "   border-radius: 8px;"
        "   padding: 16px;"
        "}"
    );
    
    QVBoxLayout* chartLayout = new QVBoxLayout(chartFrame);
    createChart();
    if (chartView) {
        chartLayout->addWidget(chartView);
    }
    
    mainLayout->addWidget(chartFrame);
    mainLayout->addStretch();
    
    return analyticsTab;
}

void HealthDataView::createTabWidget() {
    if (!tabWidget) {
        tabWidget = new QTabWidget(this);
    }
    
    if (QWidget* analyticsTab = createAnalyticsTab()) {
        tabWidget->addTab(analyticsTab, "Health Analytics");
    }
    
    if (QWidget* devicesTab = createDevicesTab()) {
        tabWidget->addTab(devicesTab, "Connected Devices");
    }
}

void HealthDataView::createChart() {
    qDebug() << "Creating chart...";
    if (!controller) {
        qDebug() << "Error: Controller is null!";
        return;
    }

   
    auto weeklyData = controller->getWeeklyData();
    qDebug() << "Retrieved" << weeklyData.size() << "data points for chart";

    // Create chart and container
    QChart* newChart = new QChart();
    newChart->setMinimumSize(800, 400);  // Set explicit size
    newChart->setTitle("Weekly Health Trends");
    
    // Create series
    QLineSeries* heartSeries = new QLineSeries(newChart);
    QLineSeries* stepsSeries = new QLineSeries(newChart);
    QLineSeries* sleepSeries = new QLineSeries(newChart);

    // Set series names and styles
    heartSeries->setName("Heart Rate (BPM)");
    stepsSeries->setName("Daily Steps (thousands)");
    sleepSeries->setName("Sleep (hours)");

    // Style series
    QPen heartPen(QColor("#FF4B6F"));
    heartPen.setWidth(3);
    heartSeries->setPen(heartPen);

    QPen stepsPen(QColor("#4CAF50"));
    stepsPen.setWidth(3);
    stepsSeries->setPen(stepsPen);

    QPen sleepPen(QColor("#2196F3"));
    sleepPen.setWidth(3);
    sleepSeries->setPen(sleepPen);

    // Add data points
    qDebug() << "Adding data points to series...";
    for (const auto& metric : weeklyData) {
        qreal timestamp = metric.date.startOfDay().toMSecsSinceEpoch();
        heartSeries->append(timestamp, metric.heartRate);
        stepsSeries->append(timestamp, metric.steps / 1000.0);  // Convert to thousands
        sleepSeries->append(timestamp, metric.sleepHours);
        qDebug() << "Added point:" << metric.date.toString() << metric.heartRate << metric.steps/1000.0 << metric.sleepHours;
    }

    // Add series to chart
    newChart->addSeries(heartSeries);
    newChart->addSeries(stepsSeries);
    newChart->addSeries(sleepSeries);

    // Create axes
    QDateTimeAxis* axisX = new QDateTimeAxis(newChart);
    axisX->setFormat("MMM dd");
    axisX->setTitleText("Date");
    axisX->setGridLineVisible(true);
    axisX->setGridLineColor(QColor("#E0E0E0"));
    
    QValueAxis* axisYLeft = new QValueAxis(newChart);
    axisYLeft->setTitleText("Heart Rate & Sleep");
    axisYLeft->setRange(0, 100);
    axisYLeft->setGridLineVisible(true);
    axisYLeft->setGridLineColor(QColor("#E0E0E0"));
    
    QValueAxis* axisYRight = new QValueAxis(newChart);
    axisYRight->setTitleText("Steps (thousands)");
    axisYRight->setRange(0, 15);  // For steps in thousands
    axisYRight->setGridLineVisible(false);

    // Add axes to chart
    newChart->addAxis(axisX, Qt::AlignBottom);
    newChart->addAxis(axisYLeft, Qt::AlignLeft);
    newChart->addAxis(axisYRight, Qt::AlignRight);

    // Attach series to axes
    heartSeries->attachAxis(axisX);
    heartSeries->attachAxis(axisYLeft);
    
    sleepSeries->attachAxis(axisX);
    sleepSeries->attachAxis(axisYLeft);
    
    stepsSeries->attachAxis(axisX);
    stepsSeries->attachAxis(axisYRight);

    // Style chart
    newChart->setBackgroundVisible(true);
    newChart->setBackgroundBrush(QBrush(Qt::white));
    newChart->setPlotAreaBackgroundVisible(true);
    newChart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    newChart->legend()->setVisible(true);
    newChart->legend()->setAlignment(Qt::AlignTop);
    newChart->legend()->setMarkerShape(QLegend::MarkerShapeCircle);

    // Create chart view
    QChartView* newChartView = new QChartView(newChart);
    newChartView->setRenderHint(QPainter::Antialiasing);
    newChartView->setMinimumSize(800, 400);

    // Store as member variables
    if (chartView) {
        delete chartView;
    }
    if (chart) {
        delete chart;
    }
    
    chart = newChart;
    chartView = newChartView;
    
    qDebug() << "Chart creation completed";
}


QWidget* HealthDataView::createDevicesTab() {
    QWidget* devicesTab = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(devicesTab);
    
    // Header
    QHBoxLayout* headerLayout = new QHBoxLayout();
    QLabel* titleLabel = new QLabel("Connected Health Devices", devicesTab);
    QFont titleFont("Arial", 16, QFont::Bold);
    titleLabel->setFont(titleFont);
    headerLayout->addWidget(titleLabel);
    
    QPushButton* addDeviceBtn = new QPushButton("Add New Device", devicesTab);
    addDeviceBtn->setStyleSheet("background-color: #333; color: white; padding: 8px 16px; border-radius: 4px;");
    headerLayout->addStretch();
    headerLayout->addWidget(addDeviceBtn);
    layout->addLayout(headerLayout);
    
    // Devices List
    QScrollArea* scrollArea = new QScrollArea(devicesTab);
    QWidget* devicesContainer = new QWidget(scrollArea);
    QVBoxLayout* devicesLayout = new QVBoxLayout(devicesContainer);
    
    if (controller) {
        auto devices = controller->getConnectedDevices();
        for (const auto& device : devices) {
            devicesLayout->addWidget(createDeviceItem(device));
        }
    }
    
    devicesLayout->addStretch();
    scrollArea->setWidget(devicesContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    layout->addWidget(scrollArea);
    
    return devicesTab;
}


QWidget* HealthDataView::createDeviceItem(const ConnectedDevice& device) {
    QFrame* frame = new QFrame();
    frame->setStyleSheet(
        "QFrame {"
        "   background-color: white;"
        "   border: 1px solid #e0e0e0;"
        "   border-radius: 8px;"
        "   padding: 16px;"
        "   margin: 8px 0px;"
        "}"
    );
    
    QHBoxLayout* layout = new QHBoxLayout(frame);
    
    // Device icon and info
    QVBoxLayout* infoLayout = new QVBoxLayout();
    
    // Device type with icon
    QHBoxLayout* typeLayout = new QHBoxLayout();
    QLabel* iconLabel = new QLabel();
    // Add icon based on device type
    QString iconPath = getDeviceTypeIcon(device.type);
    QPixmap icon(iconPath);
    if (!icon.isNull()) {
        iconLabel->setPixmap(icon.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    
    QLabel* nameLabel = new QLabel(device.name);
    nameLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    
    typeLayout->addWidget(iconLabel);
    typeLayout->addWidget(nameLabel);
    typeLayout->addStretch();
    
    QLabel* syncLabel = new QLabel("Last synced: " + device.lastSync);
    syncLabel->setStyleSheet("color: #666666; font-size: 12px;");
    
    QLabel* dataLabel = new QLabel(device.dataTypes);
    dataLabel->setStyleSheet("color: #666666; font-size: 12px;");
    
    infoLayout->addLayout(typeLayout);
    infoLayout->addWidget(syncLabel);
    infoLayout->addWidget(dataLabel);
    
    layout->addLayout(infoLayout);
    layout->addStretch();
    
    // Action buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* syncBtn = new QPushButton("Sync");
    QPushButton* removeBtn = new QPushButton("Remove");
    
    syncBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   border: 1px solid #666666;"
        "   border-radius: 4px;"
        "   padding: 6px 12px;"
        "   color: #666666;"
        "}"
    );
    removeBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   border: 1px solid #666666;"
        "   border-radius: 4px;"
        "   padding: 6px 12px;"
        "   color: #666666;"
        "}"
    );
    
    buttonLayout->addWidget(syncBtn);
    buttonLayout->addWidget(removeBtn);
    layout->addLayout(buttonLayout);
    
    return frame;
}


void HealthDataView::onSyncButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString deviceName = button->property("deviceName").toString();
        emit deviceSyncRequested(deviceName);
    }
}

void HealthDataView::onRemoveButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString deviceName = button->property("deviceName").toString();
        emit deviceRemoveRequested(deviceName);
    }
}
QWidget* HealthDataView::createMetricCard(const QString& title, const QString& value,
                                        const QString& subtitle, const QString& iconPath) {
    QFrame* card = new QFrame();
    card->setFrameStyle(QFrame::StyledPanel);
    card->setStyleSheet(
        "QFrame { "
        "   background-color: white;"
        "   border: 1px solid #e0e0e0;"
        "   border-radius: 8px;"
        "   padding: 16px;"
        "   margin: 4px;"
        "}"
    );
    
    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setSpacing(4);

    QHBoxLayout* headerLayout = new QHBoxLayout();
    QLabel* iconLabel = new QLabel();

    QPixmap icon(iconPath);
    if (!icon.isNull()) {
        iconLabel->setPixmap(icon.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    
    QLabel* titleLabel = new QLabel(title);
    titleLabel->setStyleSheet("color: #666666; font-size: 12px;");
    
    headerLayout->addWidget(iconLabel);
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    
    QLabel* valueLabel = new QLabel(value);
    valueLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    
    QLabel* subtitleLabel = new QLabel(subtitle);
    subtitleLabel->setStyleSheet("color: #999999; font-size: 11px;");
    
    cardLayout->addLayout(headerLayout);
    cardLayout->addWidget(valueLabel);
    cardLayout->addWidget(subtitleLabel);
    
    return card;
}


void HealthDataView::refreshDevicesList(const QVector<ConnectedDevice>& devices) {

    QWidget* devicesTab = tabWidget->widget(1);  
    if (!devicesTab) return;

    QScrollArea* scrollArea = devicesTab->findChild<QScrollArea*>();
    if (!scrollArea) return;


    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(container);
    
    for (const auto& device : devices) {
        layout->addWidget(createDeviceItem(device));
    }
    
    layout->addStretch();
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
}

void HealthDataView::updateMetricsDisplay(const HealthMetric& metrics) {
    QWidget* analyticsTab = tabWidget->widget(0);  
    if (!analyticsTab) return;


    QHBoxLayout* cardsLayout = analyticsTab->findChild<QHBoxLayout*>();
    if (!cardsLayout) return;

   
    while (QLayoutItem* item = cardsLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }

   
    cardsLayout->addWidget(createMetricCard("Heart Rate", 
        QString::number(metrics.heartRate, 'f', 0) + " bpm",
        "Average last 7 days", ":/icons/heart.svg"));
    cardsLayout->addWidget(createMetricCard("Daily Steps",
        QString::number(metrics.steps),
        "Average last 7 days", ":/icons/steps.svg"));
    cardsLayout->addWidget(createMetricCard("Weight",
        QString::number(metrics.weight, 'f', 1) + " kg",
        "Last recorded", ":/icons/weight.svg"));
    cardsLayout->addWidget(createMetricCard("Sleep",
        QString::number(metrics.sleepHours, 'f', 1) + " hrs",
        "Average last 7 days", ":/icons/sleep.svg"));
}


void HealthDataView::updateChartData(const QVector<HealthMetric>& weeklyData) {
    if (!heartRateSeries || !stepsSeries || !sleepSeries) return;

    
    heartRateSeries->clear();
    stepsSeries->clear();
    sleepSeries->clear();

   
    for (const auto& metric : weeklyData) {
        qreal timestamp = metric.date.startOfDay().toMSecsSinceEpoch();
        heartRateSeries->append(timestamp, metric.heartRate);
        stepsSeries->append(timestamp, metric.steps / 100.0); 
        sleepSeries->append(timestamp, metric.sleepHours * 10); 
    }
}

QString HealthDataView::getDeviceTypeIcon(const QString& deviceType) {
    
    if (deviceType.toLower() == "smartphone") {
        return ":/icons/smartphone.svg";
    }
    else if (deviceType.toLower() == "smartwatch") {
        return ":/icons/smartwatch.svg";
    }
    else if (deviceType.toLower() == "smart scale") {
        return ":/icons/scale.svg";
    }
    else if (deviceType.toLower() == "smart thermometer") {
        return ":/icons/thermometer.svg";
    }
    
   
    return ":/icons/device.svg";
}


