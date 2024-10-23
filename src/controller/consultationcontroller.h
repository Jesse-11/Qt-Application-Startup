// consultationcontroller.h
#ifndef CONSULTATIONCONTROLLER_H
#define CONSULTATIONCONTROLLER_H

#include <QObject>
#include "../model/consultationmodel.h"
#include "../view/consultationview.h"

class ConsultationController : public QObject {
    Q_OBJECT

public:
    explicit ConsultationController(ConsultationView* view, QObject* parent = nullptr);
    void initializeConsultation(const QString& doctorName);

public slots:
    void handleMuteClicked();
    void handleStopVideoClicked();
    void handleEndCallClicked();
    void handleNoteAdded(const QString& note);

private slots:
    void onMuteStateChanged(bool isMuted);
    void onVideoStateChanged(bool isStopped);
    void onCallEnded();
    void onNoteAdded(const QString& note);

signals:
    void consultationEnded();

private:
    ConsultationModel* model;
    ConsultationView* view;
    void setupConnections();
    void updateButtonStates();
};

#endif