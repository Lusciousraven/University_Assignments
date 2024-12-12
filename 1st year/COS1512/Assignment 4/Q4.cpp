#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<class T>

int count(vector<T> v1, T val)
{

    int j = 0;

    for ( int i = 0; i < v1.size(); i++)
        {
              if(val == v1[i])
              j++;
        }
            return j;
}



int main()
{
    vector<int> v1;
    vector<char> v2;

    char calpha, cval;
    int inum, ival;

    cout << "Enter a list of numbers and end with number 0 " << endl;

    cin >> inum;

    while (inum!=0)
    {
        v1.push_back(inum);
        cout << "Enter next number: " << endl;
        cin >> inum;
    }

    cout << "Enter number to search for: " << endl;

    cin >> ival;

    cout << ival << " occurs " << count(v1, ival) << " times" << endl;

    //
    //

    cout << "Enter alphabet letters and end with character # " << endl;

    cin >> calpha;
    calpha = tolower(calpha);

    while (calpha!='#')
    {
        v2.push_back(calpha);
        cout << "Enter next alphabet letter: " << endl;
        cin >> calpha;
        calpha = tolower(calpha);
    }

    cout << "Enter alphabet to search for: " << endl;

    cin >> cval;
    cval = tolower(cval);

    cout << cval << " occurs " << count<char>(v2,cval) << " times" << endl;


    return 0;
}
