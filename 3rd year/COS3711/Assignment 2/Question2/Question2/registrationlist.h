#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include <QObject>
#include <QList>
#include <QString>
#include "Registration.h"

class RegistrationList : public QObject
{
    Q_OBJECT

public:
    RegistrationList(QObject *parent = nullptr);
     ~RegistrationList();

    void addRegistration(Registration* registration);
    bool isRegistered(const QString &name) const;
    int countByInstitution(const QString &institution) const;
    double totalFees(const QString &type = "All") const;

    QList<Registration*> registrations() const;
    QStringList getAllBookings() const;

private:
    QList<Registration*> m_registrations;
};

#endif // REGISTRATIONLIST_H
