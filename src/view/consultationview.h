#ifndef CONSULTATION_VIEW_H
#define CONSULTATION_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class ConsultationView : public QWidget {
    Q_OBJECT
public:
    explicit ConsultationView(QWidget *parent = nullptr);
    void setDoctorName(const QString& name);

signals:
    void muteClicked();
    void stopVideoClicked();
    void endCallClicked();
    void noteAdded(const QString& note);

private:
    void setupUI();
    void setupChatArea();
    void setupVideoArea();
    void setupControlsArea();
    void setupNotesArea();
    
    // Main layout sections
    QHBoxLayout* mainLayout;
    QWidget* leftSection;
    QWidget* rightSection;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    
    // UI Elements
    QLabel* m_doctorNameLabel;
    QLabel* m_videoArea;
    QPushButton* m_muteButton;
    QPushButton* m_stopVideoButton;
    QPushButton* m_endCallButton;
    QTextEdit* m_notesArea;
    QTextEdit* m_chatArea;
    QGroupBox* m_chatBox;
    QGroupBox* m_notesBox;
};

#endif