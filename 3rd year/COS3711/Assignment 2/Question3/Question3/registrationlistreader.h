#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QList>
#include <QString>
#include <QXmlStreamReader>
#include "Registration.h"

class RegistrationListReader
{
public:
    RegistrationListReader();
    QList<Registration*> readFile(const QString &fileName);

private:
    QList<Registration*> m_registrations;
    QString m_currentType;
    QString m_currentText;
    Registration *m_currentRegistration;
};

#endif // REGISTRATIONLISTREADER_H
