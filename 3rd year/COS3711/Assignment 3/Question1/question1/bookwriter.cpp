#include "BookWriter.h"
#include <QFile>
#include <QTextStream>

bool BookWriter::saveBook(const Book &book, const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "Title: " << book.getTitle() << "\n";
    out << "Authors: " << book.getAuthors().join(", ") << "\n";
    out << "ISBN: " << book.getISBN() << "\n";
    out << "Publication Date: " << book.getDateOfPublication().toString("yyyy-MM-dd") << "\n";

    file.close();
    return true;
}
