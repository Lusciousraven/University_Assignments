#include "vendor.h"

Vendor::Vendor()
{

}

void Vendor:: setDetails(QString name, QString email, bool isManufacturer)
{
    m_Name = name;
    m_Email = email;
    m_isManufacturer = isManufacturer;
}

bool Vendor:: isManufacturer () const
{
    return m_isManufacturer;
}

QString Vendor:: getName() const
{
    return m_Name;
}

QString Vendor::toString() const
{
     if (m_isManufacturer==true)
    {
        return QString("Vendor name: %1, Email: %2, Manufacturer: %3").arg(m_Name).arg(m_Email).arg("True");
    }
     else return QString("Vendor name: %1, Email: %2, Manufacturer: %3").arg(m_Name).arg(m_Email).arg("False");

}
