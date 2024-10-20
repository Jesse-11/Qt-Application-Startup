#include "languageselectionview.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>

LanguageSelectionView::LanguageSelectionView(QWidget *parent) : QWidget(parent) {
    createLayout();
}

void LanguageSelectionView::createLayout() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Select Your Preferred Language", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    mainLayout->addWidget(titleLabel, 0, Qt::AlignHCenter);

    QLabel* subtitleLabel = new QLabel("Choose the language you'd like to use for the e-health system", this);
    subtitleLabel->setStyleSheet("font-size: 16px; color: #666;");
    mainLayout->addWidget(subtitleLabel, 0, Qt::AlignHCenter);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(10);

    QVector<QPair<QString, QString>> languages = {
        {"GB", "English"}, {"ES", "Español"}, {"FR", "Français"},
        {"DE", "Deutsch"}, {"IT", "Italiano"}, {"PT", "Português"},
        {"RU", "Русский"}, {"CN", "中文"}, {"JP", "日本語"},
        {"KR", "한국어"}, {"SA", "العربية"}, {"IN", "हिन्दी"}
    };

    int row = 0, col = 0;
    for (const auto& lang : languages) {
        QPushButton* button = createLanguageButton(lang.first, lang.second);
        gridLayout->addWidget(button, row, col);
        languageButtons[lang.first] = button;
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }

    mainLayout->addLayout(gridLayout);

    cancelButton = new QPushButton("Cancel", this);
    mainLayout->addWidget(cancelButton, 0, Qt::AlignHCenter);

    connect(cancelButton, &QPushButton::clicked, this, &LanguageSelectionView::cancelClicked);

    QLabel* requestLabel = new QLabel("Don't see your language? Request a new language", this);
    requestLabel->setStyleSheet("color: #666; margin-top: 20px;");
    mainLayout->addWidget(requestLabel, 0, Qt::AlignHCenter);
}


QPushButton* LanguageSelectionView::createLanguageButton(const QString& languageCode, const QString& languageName) {
    QPushButton* button = new QPushButton(this);
    button->setStyleSheet(
        "QPushButton {"
        "   text-align: left;"
        "   padding: 10px;"
        "   min-width: 200px;"
        "   min-height: 60px;"
        "   background-color: white;"
        "   border: 1px solid #ddd;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #f0f0f0;"
        "}"
    );
    
    QHBoxLayout* layout = new QHBoxLayout(button);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(10);

    QLabel* langCode = new QLabel(languageCode, button);
    langCode->setStyleSheet("font-weight: bold; color: #333;");
    
    QLabel* langName = new QLabel(languageName, button);
    langName->setStyleSheet("color: #333;");
    
    layout->addWidget(langCode);
    layout->addWidget(langName);
    layout->addStretch();

    if (languageCode == "GB") {  // Assuming English is the current language
        QLabel* checkMark = new QLabel("✓", button);
        checkMark->setStyleSheet("color: green; font-weight: bold;");
        layout->addWidget(checkMark);
    } else {
        QPushButton* selectButton = new QPushButton("Select Language", button);
        selectButton->setStyleSheet(
            "QPushButton {"
            "   background-color: #f0f0f0;"
            "   border: none;"
            "   padding: 5px 10px;"
            "   border-radius: 3px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #e0e0e0;"
            "}"
        );
        layout->addWidget(selectButton);

        connect(selectButton, &QPushButton::clicked, this, [this, languageCode]() {
            emit languageSelected(languageCode);
        });
    }
    
    return button;
}