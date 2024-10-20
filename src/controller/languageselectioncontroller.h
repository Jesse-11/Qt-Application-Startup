#pragma once

#include <QObject>
#include "../model/languageselectionmodel.h"
#include "../view/languageselectionview.h"

class LanguageSelectionController : public QObject {
    Q_OBJECT
public:
    explicit LanguageSelectionController(LanguageSelectionModel* model, LanguageSelectionView* view, QObject* parent = nullptr);

signals:
    void languageChanged(const QString& language);
     void cancelRequested();

private slots:
    void onLanguageSelected(const QString& language);
    void onCancelClicked();
private:
    LanguageSelectionModel* model;
    LanguageSelectionView* view;
};