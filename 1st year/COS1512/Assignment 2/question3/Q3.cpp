
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    vector<string> boys;
    vector<string> boyss;
    vector<string> girlss;
    ifstream fin("BabyNames.dat");

    string num;
    int icount =0;


    while (fin >> num)
        boys.push_back(num);


    for(int i=0;i<boys.size();i++)

    {
        if(i%2 != 0)
        {
            girlss.push_back(boys[i]);
        }else
            {
                boyss.push_back(boys[i]);
            }
    }

    fin.close();

    ofstream myfile;
	myfile.open("BabyNamesOut.dat");





    string BorG;
    string prefix;
    cout << "Would you like a girl name or boy name? " << endl;
    cout << "Enter 'B' for Boy and 'G' for Girl: ";
    cin  >> BorG;
    cout << "Prefix please" << endl;
    cin >> prefix;
    if(BorG =="B")
    {
        for(int b=0;b<boyss.size();b++)

            {
            if(boyss[b].rfind(prefix,0) == 0)
                {
                myfile << to_string(b+1) << " "<<boyss[b] << endl;
                }
            }
    }else
    {
        for(int g=0;g<girlss.size();g++)
            {
                if(girlss[g].rfind(prefix,0) == 0)
                {
                    myfile << to_string(g+1) << " "<< girlss[g] << endl;
                }
            }
    }

    myfile.close();
    return 0;
}
