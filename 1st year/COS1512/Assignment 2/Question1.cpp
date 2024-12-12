#include<iostream>
#include <cassert>

using namespace std;


double calcDiscount(double &price, double discount, bool fixed)


{
    double mPrice;
    cout << "Enter price of the item: ";
    cin >> price;

    cout << "Enter Discount: ";
    cin >> discount;
    cout   <<"Enter 1 to calculate discount as fixed amount(true) " << endl <<"OR" << endl <<"Enter 0 to calculate discount as percentage(false): ";
    cin >> fixed;


    if(fixed)
        {
            mPrice = price-discount;

        }

    else if(!fixed)
        {

            mPrice = price-(price*(discount/100));
        }


    assert(discount > 0);

    assert(mPrice > 0);



    return mPrice;
}



 int main( )
 {
    double price, discount, mPrice;
    bool dStatus;

   mPrice = calcDiscount(price, discount, dStatus);

    cout << mPrice;


 return 0;
 }
