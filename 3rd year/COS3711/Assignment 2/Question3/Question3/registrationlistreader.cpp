#include "RegistrationListReader.h"
#include "Registration.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>

RegistrationListReader::RegistrationListReader() : m_currentRegistration(nullptr)
{
}

QList<Registration*> RegistrationListReader::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QList<Registration*>();

    QXmlStreamReader reader(&file);
    while (!reader.atEnd())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            if (reader.name() == QLatin1String("registration"))
            {
                QString type = reader.attributes().value("type").toString();
                QString name, affiliation, email;
                QDate bookingDate;

                while (!(reader.isEndElement() && reader.name() == QLatin1String("registration")))
                {
                    reader.readNext();
                    if (reader.isStartElement())
                    {
                        if (reader.name() == QLatin1String("name"))
                            name = reader.readElementText().trimmed();
                        else if (reader.name() == QLatin1String("affiliation"))
                            affiliation = reader.readElementText().trimmed();
                        else if (reader.name() == QLatin1String("email"))
                            email = reader.readElementText().trimmed();
                        else if (reader.name() == QLatin1String("bookingdate"))
                            bookingDate = QDate::fromString(reader.readElementText().trimmed(), Qt::ISODate);
                    }
                }

                if (type == QLatin1String("Standard"))
                    m_registrations.append(new StandardRegistration(name, affiliation, email, bookingDate));
                else if (type == QLatin1String("Student"))
                    m_registrations.append(new StudentRegistration(name, affiliation, email, bookingDate));
                else if (type == QLatin1String("Guest"))
                    m_registrations.append(new GuestRegistration(name, affiliation, email, bookingDate));
            }
        }
    }

    if (reader.hasError())
        qDebug() << "Error: " << reader.errorString();

    file.close();
    return m_registrations;
}
