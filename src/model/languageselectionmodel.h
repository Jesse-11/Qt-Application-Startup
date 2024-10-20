#pragma once 

#include <QString>
#include <QMap>

class LanguageSelectionModel {
public:
    LanguageSelectionModel();
    QMap<QString, QString> getAvailableLanguages() const;
    void setCurrentLanguage(const QString& languageCode);
    QString getCurrentLanguage() const;

private:
    QMap<QString, QString> availableLanguages;
    QString currentLanguage;
};