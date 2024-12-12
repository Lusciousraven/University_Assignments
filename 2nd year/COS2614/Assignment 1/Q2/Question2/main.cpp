#include <QCoreApplication>
#include <QTextStream>
#include "product.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString productN,vendorN,vendorE,pr;
    double price;
    char isManufacturer;
    bool isM;

    cout << "Product Details " << "\n";
    cout << "\n";
    cout << "Enter product name: ";
    cout << "\n";
    cout.flush();
    productN = cin.readLine();
    cout << "Enter product price: ";
    cout << "\n";
    cout.flush();
    pr = cin.readLine();
    price = pr.toDouble();

    cout << "Enter supplier name: ";
    cout << "\n";
    cout.flush();
    vendorN = cin.readLine();
    cout << "Enter email address: ";
    cout << "\n";
    cout.flush();
    vendorE = cin.readLine();
    cout << "Is the supplier also the manufacturer of this product (Answer with Y or N): ";
    cout << "\n";
    cout.flush();
    cin >> isManufacturer;

    if (isManufacturer == 'Y' || isManufacturer == 'y')
        isM = true;
    else if (isManufacturer == 'N' || isManufacturer == 'n')
        isM = false;


    Product p(productN,price);

    p.setSupplier(vendorN,vendorE,isM);
    cout << "\n";
    cout << "Product details without supplier information: \n";
    cout << p.toString(false) << "\n\n";
    cout << "Product details with supplier information: \n";
    cout << p.toString((true)) << "\n\n";
    cout << "Manufacturer details of product:  \n";
    cout << p.getManufacturerName() << "\n";
    cout << "\n";



    //return a.exec();
}
