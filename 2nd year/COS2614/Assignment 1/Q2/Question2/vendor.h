#ifndef VENDOR_H
#define VENDOR_H
#include <QString>


class Vendor
{
public:
    Vendor();
    void setDetails(QString name, QString email, bool isManufacturer);
    bool isManufacturer() const;
    QString getName() const;
    QString toString() const;


private:
    QString m_Name;
    QString m_Email;
    bool m_isManufacturer;

};

#endif // VENDOR_H
