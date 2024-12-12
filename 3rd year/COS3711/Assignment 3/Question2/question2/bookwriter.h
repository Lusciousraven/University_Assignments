#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "book.h"

class BookWriter : public QObject
{
    Q_OBJECT
public:
    explicit BookWriter(QObject *parent = nullptr);

    bool writeToFile(const QString &fileName, Book *book);
    void saveBook(const Book& book, const QString& fileName);
private:
    void writeBook(QTextStream &out, Book *book);
};

#endif // BOOKWRITER_H
