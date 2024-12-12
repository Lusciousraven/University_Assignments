#include "RegistrationList.h"

RegistrationList::RegistrationList(QObject *parent)
    : QObject(parent)
{
}

void RegistrationList::addRegistration(Registration* registration)
{
    m_registrations.append(registration);
}

bool RegistrationList::isRegistered(const QString &name) const
{
    for (const Registration* reg : m_registrations)
    {
        if (reg->getAttendee() == name)
            return true;
    }
    return false;
}

int RegistrationList::countByInstitution(const QString &institution) const
{
    int count = 0;
    for (const Registration* reg : m_registrations)
    {
        if (reg->getAffiliation() == institution)
            count++;
    }
    return count;
}

double RegistrationList::totalFees(const QString &type) const
{
    double total = 0;
    for (const Registration* reg : m_registrations)
    {
        if (type == "All" || (type == "Standard" && dynamic_cast<const StandardRegistration*>(reg)) ||
            (type == "Student" && dynamic_cast<const StudentRegistration*>(reg)) ||
            (type == "Guest" && dynamic_cast<const GuestRegistration*>(reg)))
        {
            total += reg->registrationFee();
        }
    }
    return total;
}

QList<Registration*> RegistrationList::registrations() const
{
    return m_registrations;
}

QStringList RegistrationList::getAllBookings() const
{
    QStringList bookings;
    for (const Registration* reg : m_registrations)
    {
        bookings.append(reg->toString());
    }
    return bookings;
}
