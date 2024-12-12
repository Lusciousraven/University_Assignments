#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Book.h"
#include "BookWriter.h"

class BookInput : public QWidget {
    Q_OBJECT

public:
    explicit BookInput(QWidget* parent = nullptr);

private slots:
    void saveBook();

private:
    QLineEdit* titleEdit;
    QLineEdit* authorsEdit;
    QLineEdit* isbnEdit;
    QLineEdit* publicationDateEdit;
};

#endif // BOOKINPUT_H
