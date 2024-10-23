#include "../model/consultationmodel.h"

ConsultationModel::ConsultationModel(QObject *parent) 
    : QObject(parent)
    , m_isMuted(false)
    , m_isVideoStopped(false) {
}

void ConsultationModel::setDoctorName(const QString& name) {
    m_doctorName = name;
}

QString ConsultationModel::getDoctorName() const {
    return m_doctorName;
}

void ConsultationModel::toggleMute() {
    m_isMuted = !m_isMuted;
    emit muteStateChanged(m_isMuted);
}

void ConsultationModel::toggleVideo() {
    m_isVideoStopped = !m_isVideoStopped;
    emit videoStateChanged(m_isVideoStopped);
}

void ConsultationModel::endCall() {
    emit callEnded();
}

void ConsultationModel::addConsultationNote(const QString& note) {
    m_consultationNotes.append(note);
    emit noteAdded(note);
}

bool ConsultationModel::isMuted() const {
    return m_isMuted;
}

bool ConsultationModel::isVideoStopped() const {
    return m_isVideoStopped;
}

QStringList ConsultationModel::getNotes() const {
    return m_consultationNotes;
}