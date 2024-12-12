#include "Book.h"

Book::Book(const QString &title, const QStringList &authors, const QString &isbn, const QDate &dateOfPublication)
    : m_title(title), m_authors(authors), m_isbn(isbn), m_dateOfPublication(dateOfPublication) {}

QString Book::getTitle() const {
    return m_title;
}

QStringList Book::getAuthors() const {
    return m_authors;
}

QString Book::getISBN() const {
    return m_isbn;
}

QDate Book::getDateOfPublication() const {
    return m_dateOfPublication;
}

