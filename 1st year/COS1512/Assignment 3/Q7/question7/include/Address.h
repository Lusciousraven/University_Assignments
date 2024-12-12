#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>

using namespace std;

class Address
{
    public:
        Address();
        ~Address();
        void setStreetname(string sName);
        void setStreetnum(int iNum);
        void setCity(string sCity);
        void setPostalcode(string sCode);
        string getStreetname();
        int getStreetnum();
        string getCity();
        string getPostalcode();
        friend istream &operator>>(istream &inp, Address &add);
        friend ostream &operator<<(ostream &outp, const Address &add);


    private:
        string streetName;
        int streetNr;
        string city;
        string postalCode;

};

#endif // ADDRESS_H
