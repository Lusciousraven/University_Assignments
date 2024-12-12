#include <iostream>

using namespace std;

class Address
{
    public:

        Address()
        {
           streetName = " ";
           streetNr = 0;
           city = " ";
           postalCode = "0000";
        }

        void setStreetname(string sName)
        {
           streetName = sName;
        }
        void setStreetnum(int iNum)
        {
           streetNr = iNum;
        }
        void setCity(string sCity)
        {
           city = sCity;
        }
        void setPostalcode(string sCode)
        {
           postalCode = sCode;
        }

        string getStreetname()
        {
            return streetName;
        }
        int getStreetnum()
        {
            return streetNr;
        }
        string getCity()
        {
            return city;
        }
        string getPostalcode()
        {
            return postalCode;
        }

    private:
        string streetName;
        int streetNr;
        string city;
        string postalCode;

};

int main()
{
    Address Address1;
    string strName;
    int strNr;
    string sCity;
    string pCode;

    cout << "Please enter your address: " << endl;

    cout << "Street Name: ";
    getline(cin, strName, '\n');
    Address1.setStreetname(strName);

    cout << "Street Number: ";
    cin >> strNr;
    Address1.setStreetnum(strNr);

    cout << "City: ";
    cin >> sCity;
    Address1.setCity(sCity);

    cout << "Postal Code: ";
    cin >> pCode;
    Address1.setPostalcode(pCode);

    cout << "Your Address is: " << endl;
    cout << Address1.getStreetnum() << " " << Address1.getStreetname() << endl;
    cout << Address1.getCity() << " " << Address1.getPostalcode();



    return 0;
}
