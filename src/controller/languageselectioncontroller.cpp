#include "languageselectioncontroller.h"

LanguageSelectionController::LanguageSelectionController(LanguageSelectionModel* model, LanguageSelectionView* view, QObject* parent)
    : QObject(parent), model(model), view(view) {
    // We only need to connect the languageSelected signal
    connect(view, &LanguageSelectionView::languageSelected, this, &LanguageSelectionController::onLanguageSelected);
}

void LanguageSelectionController::onLanguageSelected(const QString& language) {
    model->setCurrentLanguage(language);
    emit languageChanged(language);
}

void LanguageSelectionController::onCancelClicked() {  
    emit cancelRequested();
}