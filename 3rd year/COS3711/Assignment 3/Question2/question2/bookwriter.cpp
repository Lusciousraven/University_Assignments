#include "bookwriter.h"
#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>


BookWriter::BookWriter(QObject *parent) : QObject(parent) {}

bool BookWriter::writeToFile(const QString &fileName, Book *book)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    writeBook(out, book);
    return true;
}

void BookWriter::writeBook(QTextStream &out, Book *book)
{
    const QMetaObject *metaObj = book->metaObject();
    for (int i = 0; i < metaObj->propertyCount(); ++i)
    {
        QMetaProperty prop = metaObj->property(i);
        QString propertyName = prop.name();
        QVariant value = book->property(prop.name());
        out << propertyName << ": " << value.toString() << "\n";
    }
}

void BookWriter::saveBook(const Book& book, const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning("Failed to open file for writing.");
        return;
    }

    QTextStream out(&file);
    const QMetaObject* metaObject = book.metaObject();
    int propertyCount = metaObject->propertyCount();

    for (int i = 0; i < propertyCount; ++i) {
        QMetaProperty property = metaObject->property(i);
        if (property.isReadable()) {
            QVariant value = property.read(&book);
            out << property.name() << ": " << value.toString() << "\n";
        }
    }

    file.close();
}
