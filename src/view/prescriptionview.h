#ifndef PRESCRIPTIONVIEW_H
#define PRESCRIPTIONVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "../model/prescriptionmodel.h"

class PrescriptionView : public QWidget {
    Q_OBJECT

public:
    explicit PrescriptionView(QWidget *parent = nullptr);
    void updatePrescriptionList(const QList<PrescriptionModel>& prescriptions);

signals:
    void refillRequested(const QString &prescriptionName);
    void backToDashboard();

private:
    QListWidget *prescriptionList;
    QPushButton *activeButton;
    QPushButton *pendingButton;
    QPushButton *historyButton;
    QPushButton *backButton;
    QStackedWidget *stackedWidget;

    void createLayout();
    void createPrescriptionWidget(const PrescriptionModel &prescription);
};

#endif // PRESCRIPTIONVIEW_H