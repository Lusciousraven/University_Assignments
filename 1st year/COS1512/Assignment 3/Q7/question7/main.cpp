#include <iostream>
#include<fstream>
#include "Address.h"
#include <string>
#include<array>

using namespace std;

int main()
{


    int icount = 0;
    int icount2 = 0;
    int icount3 = 0;

    string sInput;
    string sCode;
    Address Addressobs[20];
    Address Addresscode[20];




    cout << "Please enter postal code: " << endl;
    cin >> sCode;
    cout << endl;


    ifstream infile("Address.dat");


    if (infile.fail())
    {
        cout << "File opening failed!";
        exit(1);
    }

    while (getline(infile,sInput))
    {



        if(icount == 4)
        {
            icount2 = icount2 + 1;
            icount = 0;
        }


        if (icount == 0)
        {

            Addressobs[icount2].setStreetname(sInput);


        }

        else if (icount == 1)
        {

            Addressobs[icount2].setStreetnum(stoi(sInput));

        }

        else if (icount == 2)
        {
            Addressobs[icount2].setCity(sInput);
        }

        else
        {
            Addressobs[icount2].setPostalcode(sInput);


        }




        icount = icount + 1;


    }


        for (int j = 0; j < (icount2 - 1) ; j++)
        {
            if (sCode == Addressobs[j].getPostalcode())
            {
                Addresscode[icount3] = Addressobs[j];
                icount3 = icount3 + 1;

                cout << Addressobs[j].getStreetname() << endl;
                cout << Addressobs[j].getStreetnum() << endl;
                cout << Addressobs[j].getCity() << endl;
                cout << Addressobs[j].getPostalcode() << endl << endl;
            }

        }








    return 0;
}
