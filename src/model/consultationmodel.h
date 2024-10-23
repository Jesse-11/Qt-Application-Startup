#ifndef CONSULTATIONMODEL_H
#define CONSULTATIONMODEL_H
#include <QObject>
#include <QString>
#include <QStringList>
using namespace std;


class ConsultationModel : public QObject {
    Q_OBJECT
public:
    explicit ConsultationModel(QObject *parent = nullptr);
    
    void setDoctorName(const QString& name);
    QString getDoctorName() const;
    void addNote(const QString& note);
    QStringList getNotes() const;
    bool isMuted() const;
    bool isVideoStopped() const;

public slots:
    void toggleMute();
    void toggleVideo();
    void endCall();
    void addConsultationNote(const QString& note);

signals:
    void muteStateChanged(bool muted);
    void videoStateChanged(bool stopped);
    void callEnded();
    void noteAdded(const QString& note);

private:
    QString m_doctorName;
    QStringList m_consultationNotes;
    bool m_isMuted;
    bool m_isVideoStopped;
};

#endif // CONSULTATIONMODEL_H