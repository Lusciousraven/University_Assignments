#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QString>
#include <QDate>

class Registration
{
public:
    Registration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate);

    virtual double registrationFee() const = 0;
    virtual QString toString() const;

    QString getAttendee() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QDate getBookingDate() const;

protected:
    QString m_name;
    QString m_affiliation;
    QString m_email;
    QDate m_bookingDate;
};

class StandardRegistration : public Registration
{
public:
    StandardRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate);

    double registrationFee() const override;
    QString toString() const override;
};

class StudentRegistration : public Registration
{
public:
    StudentRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate);

    double registrationFee() const override;
    QString toString() const override;
};

class GuestRegistration : public Registration
{
public:
    GuestRegistration(const QString &name, const QString &affiliation, const QString &email, const QDate &bookingDate);

    double registrationFee() const override;
    QString toString() const override;
};

#endif // REGISTRATION_H
