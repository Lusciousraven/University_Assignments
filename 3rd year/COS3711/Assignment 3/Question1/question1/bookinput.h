#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QTextEdit>
#include "BookWriter.h"

class BookInput : public QWidget {
    Q_OBJECT

public:
    explicit BookInput(QWidget *parent = nullptr);

private slots:
    void saveBook();

private:
    QLineEdit *titleEdit;
    QTextEdit *authorsEdit;
    QLineEdit *isbnEdit;
    QDateEdit *dateEdit;
    QPushButton *saveButton;

    BookWriter writer;
};

#endif // BOOKINPUT_H
