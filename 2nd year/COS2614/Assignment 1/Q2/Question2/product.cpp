#include "product.h"

Product::Product(QString name, double price)
{
    m_Name = name;
    m_Price = price;
    //m_Supplier = ?;
}

void Product:: setSupplier(QString name, QString email, bool isManufacturer)
{
    m_Supplier.setDetails(name,email,isManufacturer);
}

QString Product::getManufacturerName() const
{
    if (m_Supplier.isManufacturer())
        return m_Supplier.getName();
    else
        return "No Name";
}

QString Product::toString(bool supplierDetails) const
{
    QString product = QString("Product name: %1, Product price: %2").arg(m_Name).arg(m_Price);
    if (supplierDetails)
        product.append(QString(", %1").arg(m_Supplier.toString()));
    return product;
}
