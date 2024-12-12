#include "Registration.h"

const double STANDARD_FEE = 100.0;

Registration::Registration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate)
    : m_name(name), m_affiliation(affiliation), m_email(email), m_bookingDate(bookingDate)
{
}

QString Registration::getAttendee() const
{
    return m_name;
}

QString Registration::getAffiliation() const
{
    return m_affiliation;
}

QString Registration::getEmail() const
{
    return m_email;
}

QDate Registration::getBookingDate() const
{
    return m_bookingDate;
}

QString Registration::toString() const
{
    return QString("Name: %1, Affiliation: %2, Email: %3, Booking Date: %4").arg(m_name, m_affiliation, m_email, m_bookingDate.toString());
}

StandardRegistration::StandardRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate)
    : Registration(name, affiliation, email, bookingDate)
{
}

double StandardRegistration::registrationFee() const
{
    return STANDARD_FEE;
}

QString StandardRegistration::toString() const
{
    return QString("Standard - ") + Registration::toString() + QString(", Fee: %1").arg(registrationFee());
}

StudentRegistration::StudentRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate)
    : Registration(name, affiliation, email, bookingDate)
{
}

double StudentRegistration::registrationFee() const
{
    return STANDARD_FEE / 2;
}

QString StudentRegistration::toString() const
{
    return QString("Student - ") + Registration::toString() + QString(", Fee: %1").arg(registrationFee());
}

GuestRegistration::GuestRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate)
    : Registration(name, affiliation, email, bookingDate)
{
}

double GuestRegistration::registrationFee() const
{
    return STANDARD_FEE * 0.1;
}

QString GuestRegistration::toString() const
{
    return QString("Guest - ") + Registration::toString() + QString(", Fee: %1").arg(registrationFee());
}
