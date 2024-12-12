#include "Book.h"

// Constructor
Book::Book(QObject* parent)
    : QObject(parent) {}

// Getter for title
QString Book::title() const {
    return m_title;
}

// Setter for title
void Book::setTitle(const QString& title) {
    m_title = title;
}

// Getter for authors
QStringList Book::authors() const {
    return m_authors;
}

// Setter for authors
void Book::setAuthors(const QStringList& authors) {
    m_authors = authors;
}

// Getter for ISBN
QString Book::isbn() const {
    return m_isbn;
}

// Setter for ISBN
void Book::setIsbn(const QString& isbn) {
    m_isbn = isbn;
}

// Getter for publication date
QDate Book::publicationDate() const {
    return m_publicationDate;
}

// Setter for publication date
void Book::setPublicationDate(const QDate& date) {
    m_publicationDate = date;
}
