#include "BookInput.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>

BookInput::BookInput(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Title input
    layout->addWidget(new QLabel("Title:"));
    titleEdit = new QLineEdit(this);
    layout->addWidget(titleEdit);

    // Authors input
    layout->addWidget(new QLabel("Authors (comma-separated):"));
    authorsEdit = new QTextEdit(this);
    layout->addWidget(authorsEdit);

    // ISBN input
    layout->addWidget(new QLabel("ISBN:"));
    isbnEdit = new QLineEdit(this);
    layout->addWidget(isbnEdit);

    // Date input
    layout->addWidget(new QLabel("Date of Publication:"));
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setDisplayFormat("yyyy-MM-dd");
    layout->addWidget(dateEdit);

    // Save button
    saveButton = new QPushButton("Save Book", this);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &BookInput::saveBook);
}

void BookInput::saveBook() {
    QString title = titleEdit->text();
    QStringList authors = authorsEdit->toPlainText().split(",");
    QString isbn = isbnEdit->text();
    QDate publicationDate = dateEdit->date();

    Book book(title, authors, isbn, publicationDate);

    QString fileName = QFileDialog::getSaveFileName(this, "Save Book", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        writer.saveBook(book, fileName);
    }
}
