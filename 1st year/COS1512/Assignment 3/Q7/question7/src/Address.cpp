#include "Address.h"

Address::Address()
        {
           streetName = " ";
           streetNr = 0;
           city = " ";
           postalCode = "0000";
        }


Address::~Address()
        {
    //dtor
        }

void Address::setStreetname(string sName)
        {
           streetName = sName;
        }
void Address::setStreetnum(int iNum)
        {
           streetNr = iNum;
        }
void Address::setCity(string sCity)
        {
           city = sCity;
        }
void Address::setPostalcode(string sCode)
        {
           postalCode = sCode;
        }

string Address::getStreetname()
        {
            return streetName;
        }
int Address::getStreetnum()
        {
            return streetNr;
        }
string Address::getCity()
        {
            return city;
        }
string Address::getPostalcode()
        {
            return postalCode;
        }

istream &operator>>(istream &inp, Address &add)
        {
            getline(inp, add.streetName);
            inp >> add.streetNr;
            inp >> add.city;
            inp >> add.postalCode;

            return inp;
        }

ostream &operator<<(ostream &outp, const Address &add)
        {
            outp << "Street Name: " << add.streetName << endl;
            outp << "Street Number: " << add.streetNr << endl;
            outp << "City: " << add.city << endl;
            outp << "Postal code: " << add.postalCode << endl;

            return outp;
        }
