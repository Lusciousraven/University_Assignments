#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>



using namespace std;

int main() {
    vector<string> boys;
    vector<string> boys1;
    vector<string> girlss;
    ifstream inStream;
    ofstream outStream;
    string num, Gender, letter;
    int icount = 0;


    inStream.open("BabyNames.dat");

    if (inStream.fail( ))
        {
            cout << "Input file opening failed. ";
            exit(1);
        }

    outStream.open("ChosenNames.dat");

        if (outStream.fail( ))
        {
            cout << "Output file opening failed. ";
            exit(1);
        }


    while (inStream >> num)
        boys.push_back(num);


    for(int i=0;i<boys.size();i++)
        {
            if(i%2 != 0)
            {
                girlss.push_back(boys[i]);
            }
            else
            {
                boys1.push_back(boys[i]);
            }
        }


    cout << "Would you like a girl name or boy name? " << endl;
    cout << "Enter 'B' for Boy and 'G' for Girl: ";
    cin  >> Gender;
    cout << "Please enter which letter (A-Z), name should start with? " << endl;
    cin >> letter;


    if(Gender =="B")
        {
            for(int b=0;b<boys1.size();b++)
            {
                if(boys1[b].rfind(letter,0) == 0)
                    {
                cout << boys1[b+1] << " " << boys1[b] << endl;
                    }
            }
        }
            else
        {
        for(int g=0;g<girlss.size();g++)
            {
                if(girlss[g].rfind(letter,0) == 0)
                {
                    cout << girlss[g-1] << " " << girlss[g] << endl;
                }
            }
        }


    return 0;
}
