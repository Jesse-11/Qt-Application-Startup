#pragma once
#include <QWidget>
#include <QPushButton>
#include <QMap>

class LanguageSelectionView : public QWidget {
    Q_OBJECT

public:
    explicit LanguageSelectionView(QWidget *parent = nullptr);

signals:
    void languageSelected(const QString& languageCode);
    void cancelClicked();

private:
    void createLayout();
    QPushButton* createLanguageButton(const QString& languageCode, const QString& languageName);
    QMap<QString, QPushButton*> languageButtons;
    QPushButton* cancelButton;
};