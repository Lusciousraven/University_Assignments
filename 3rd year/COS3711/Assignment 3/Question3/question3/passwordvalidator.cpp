#include "PasswordValidator.h"
#include <QMessageBox>

PasswordValidator::PasswordValidator(QWidget* parent)
    : QWidget(parent),
    passwordEdit(new QLineEdit(this)),
    rule1CheckBox(new QCheckBox("Rule 1: Minimum 5 characters, no spaces", this)),
    rule2CheckBox(new QCheckBox("Rule 2: 5 characters, third can be digit or a-f/A-F", this)),
    rule3CheckBox(new QCheckBox("Rule 3: 4-6 digits, starting digit not 0", this)),
    resultLabel(new QLabel(this)) {

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(rule1CheckBox);
    layout->addWidget(rule2CheckBox);
    layout->addWidget(rule3CheckBox);
    layout->addWidget(new QLabel("Enter Password:", this));
    layout->addWidget(passwordEdit);
    QPushButton* validateButton = new QPushButton("Validate", this);
    layout->addWidget(validateButton);
    layout->addWidget(resultLabel);

    connect(validateButton, &QPushButton::clicked, this, &PasswordValidator::validatePassword);

    setLayout(layout);
}

void PasswordValidator::validatePassword() {
    QString password = passwordEdit->text();
    QString result;

    if (rule1CheckBox->isChecked()) {
        if (validateRule1(password)) {
            result = "Password satisfies Rule 1.";
        } else {
            result = "Password does NOT satisfy Rule 1.";
        }
    } else if (rule2CheckBox->isChecked()) {
        if (validateRule2(password)) {
            result = "Password satisfies Rule 2.";
        } else {
            result = "Password does NOT satisfy Rule 2.";
        }
    } else if (rule3CheckBox->isChecked()) {
        if (validateRule3(password)) {
            result = "Password satisfies Rule 3.";
        } else {
            result = "Password does NOT satisfy Rule 3.";
        }
    } else {
        result = "No rule selected.";
    }

    resultLabel->setText(result);
}

bool PasswordValidator::validateRule1(const QString& password) {
    return password.length() >= 5 && !password.contains(' ');
}

bool PasswordValidator::validateRule2(const QString& password) {
    if (password.length() != 5) return false;
    QChar thirdChar = password[2];
    return thirdChar.isDigit() || (thirdChar >= 'a' && thirdChar <= 'f') || (thirdChar >= 'A' && thirdChar <= 'F');
}

bool PasswordValidator::validateRule3(const QString& password) {
    int length = password.length();
    if (length < 4 || length > 6) return false;

    // Check the first digit
    QChar firstChar = password[0];
    if (!firstChar.isDigit() || firstChar.digitValue() == 0) return false;

    // Check the remaining characters
    for (int i = 1; i < length; ++i) {
        if (!password[i].isDigit()) return false;
    }

    return true;
}

