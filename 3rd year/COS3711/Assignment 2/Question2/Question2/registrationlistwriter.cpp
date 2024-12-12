#include "registrationlistwriter.h"
#include <QFile>
#include <QXmlStreamWriter>

RegistrationListWriter::RegistrationListWriter(QObject *parent)
    : QObject(parent)
{
}

bool RegistrationListWriter::writeToFile(const QString &fileName, const RegistrationList *registrationList)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("registrationlist");

    for (const Registration* registration : registrationList->registrations())
    {
        writeRegistration(xmlWriter, registration);
    }

    xmlWriter.writeEndElement(); // registrationlist
    xmlWriter.writeEndDocument();

    return true;
}

void RegistrationListWriter::writeRegistration(QXmlStreamWriter &xmlWriter, const Registration *registration)
{
    xmlWriter.writeStartElement("registration");
    xmlWriter.writeAttribute("type", registration->toString().section(" - ", 0, 0));

    xmlWriter.writeStartElement("attendee");
    xmlWriter.writeTextElement("name", registration->getAttendee());
    xmlWriter.writeTextElement("affiliation", registration->getAffiliation());
    xmlWriter.writeTextElement("email", registration->getEmail());
    xmlWriter.writeEndElement(); // attendee

    xmlWriter.writeTextElement("bookingdate", registration->getBookingDate().toString());
    xmlWriter.writeTextElement("registrationfee", QString::number(registration->registrationFee()));

    xmlWriter.writeEndElement(); // registration
}
