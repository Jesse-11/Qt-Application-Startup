// consultationcontroller.cpp
#include "consultationcontroller.h"
#include <QDebug>

ConsultationController::ConsultationController(ConsultationView* view, QObject* parent)
    : QObject(parent)
    , view(view)
    , model(new ConsultationModel(this))
{
    setupConnections();
    updateButtonStates();
}

void ConsultationController::setupConnections() {
    // Connect view signals to controller slots
    connect(view, &ConsultationView::muteClicked,
            this, &ConsultationController::handleMuteClicked);
    connect(view, &ConsultationView::stopVideoClicked,
            this, &ConsultationController::handleStopVideoClicked);
    connect(view, &ConsultationView::endCallClicked,
            this, &ConsultationController::handleEndCallClicked);
    connect(view, &ConsultationView::noteAdded,
            this, &ConsultationController::handleNoteAdded);

    // Connect model signals to controller slots
    connect(model, &ConsultationModel::muteStateChanged,
            this, &ConsultationController::onMuteStateChanged);
    connect(model, &ConsultationModel::videoStateChanged,
            this, &ConsultationController::onVideoStateChanged);
    connect(model, &ConsultationModel::callEnded,
            this, &ConsultationController::onCallEnded);
    connect(model, &ConsultationModel::noteAdded,
            this, &ConsultationController::onNoteAdded);
}

void ConsultationController::initializeConsultation(const QString& doctorName) {
    qDebug() << "Initializing consultation with:" << doctorName;
    model->setDoctorName(doctorName);
    view->setDoctorName(doctorName);
    updateButtonStates();
    view->show();
}

void ConsultationController::handleMuteClicked() {
    qDebug() << "Mute clicked";
    model->toggleMute();
}

void ConsultationController::handleStopVideoClicked() {
    qDebug() << "Stop video clicked";
    model->toggleVideo();
}

void ConsultationController::handleEndCallClicked() {
    qDebug() << "End call clicked";
    model->endCall();
}

void ConsultationController::handleNoteAdded(const QString& note) {
    qDebug() << "Note added";
    model->addConsultationNote(note);
}

void ConsultationController::onMuteStateChanged(bool isMuted) {
    qDebug() << "Mute state changed:" << isMuted;
    updateButtonStates();
}

void ConsultationController::onVideoStateChanged(bool isStopped) {
    qDebug() << "Video state changed:" << isStopped;
    updateButtonStates();
}

void ConsultationController::onCallEnded() {
    qDebug() << "Call ended";
    emit consultationEnded();
}

void ConsultationController::onNoteAdded(const QString& note) {
    qDebug() << "Note saved:" << note;
}

void ConsultationController::updateButtonStates() {
    // Update button states based on model state
    // This would update the UI to reflect current mute/video states
}