#include "languageselectionmodel.h"

LanguageSelectionModel::LanguageSelectionModel() : currentLanguage("en") {
    availableLanguages = {
        {"en", "English"},
        {"es", "Español"},
        {"fr", "Français"},
        {"de", "Deutsch"},
        {"it", "Italiano"},
        {"zh", "中文"},
        // Add more languages as needed
    };
}

QMap<QString, QString> LanguageSelectionModel::getAvailableLanguages() const {
    return availableLanguages;
}

void LanguageSelectionModel::setCurrentLanguage(const QString& languageCode) {
    if (availableLanguages.contains(languageCode)) {
        currentLanguage = languageCode;
    }
}

QString LanguageSelectionModel::getCurrentLanguage() const {
    return currentLanguage;
}


