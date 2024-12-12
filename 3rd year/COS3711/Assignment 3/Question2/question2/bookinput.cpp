#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "Book.h"
#include "BookWriter.h"

class BookInput : public QWidget {
    Q_OBJECT

public:
    BookInput(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        titleEdit = new QLineEdit(this);
        authorsEdit = new QLineEdit(this);
        isbnEdit = new QLineEdit(this);
        publicationDateEdit = new QLineEdit(this);
        QPushButton* saveButton = new QPushButton("Save Book", this);

        layout->addWidget(titleEdit);
        layout->addWidget(authorsEdit);
        layout->addWidget(isbnEdit);
        layout->addWidget(publicationDateEdit);
        layout->addWidget(saveButton);

        connect(saveButton, &QPushButton::clicked, this, &BookInput::saveBook);
    }

private slots:
    void saveBook() {
        Book book;
        book.setTitle(titleEdit->text());
        book.setAuthors(authorsEdit->text().split(","));
        book.setIsbn(isbnEdit->text());
        book.setPublicationDate(QDate::fromString(publicationDateEdit->text(), "yyyy-MM-dd"));

        BookWriter writer;
        writer.saveBook(book, "book.txt");
    }

private:
    QLineEdit* titleEdit;
    QLineEdit* authorsEdit;
    QLineEdit* isbnEdit;
    QLineEdit* publicationDateEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BookInput bookInput;
    bookInput.show();

    return app.exec();
}
