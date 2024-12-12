#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDate>

class Book : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QStringList authors READ authors WRITE setAuthors)
    Q_PROPERTY(QString isbn READ isbn WRITE setIsbn)
    Q_PROPERTY(QDate publicationDate READ publicationDate WRITE setPublicationDate)

public:
    explicit Book(QObject* parent = nullptr);

    QString title() const;
    void setTitle(const QString& title);

    QStringList authors() const;
    void setAuthors(const QStringList& authors);

    QString isbn() const;
    void setIsbn(const QString& isbn);

    QDate publicationDate() const;
    void setPublicationDate(const QDate& date);

private:
    QString m_title;
    QStringList m_authors;
    QString m_isbn;
    QDate m_publicationDate;
};

#endif // BOOK_H
