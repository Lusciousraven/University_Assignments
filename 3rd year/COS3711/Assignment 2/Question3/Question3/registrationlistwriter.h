#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QObject>
#include <QXmlStreamWriter>
#include <QFile>
#include "RegistrationList.h"

class RegistrationListWriter : public QObject
{
    Q_OBJECT

public:
    RegistrationListWriter(QObject *parent = nullptr);
    bool writeToFile(const QString &fileName, const RegistrationList *registrationList);

private:
    void writeRegistration(QXmlStreamWriter &xmlWriter, const Registration *registration);
};

#endif // REGISTRATIONLISTWRITER_H
