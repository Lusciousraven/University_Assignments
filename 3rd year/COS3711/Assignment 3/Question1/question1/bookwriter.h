#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "Book.h"
#include <QString>

class BookWriter {
public:
    bool saveBook(const Book &book, const QString &fileName);
};

#endif // BOOKWRITER_H
