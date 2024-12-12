#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDate>
#include <QStringList>

class Book {
public:
    Book(const QString &title, const QStringList &authors, const QString &isbn, const QDate &dateOfPublication);

    QString getTitle() const;
    QStringList getAuthors() const;
    QString getISBN() const;
    QDate getDateOfPublication() const;

private:
    QString m_title;
    QStringList m_authors;
    QString m_isbn;
    QDate m_dateOfPublication;
};

#endif // BOOK_H
