#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {

string str, nstr;
ifstream MyReadFile("question4inpfile.txt");
ofstream Myfile("question4outfile.txt");



    while (getline (MyReadFile, str))

    {

        for(int i=0; i<str.length();  )
            {

                if(str[i] == ' ')
                    {

                        if(i==0 || i==str.length()-1)
                    {
                        i++;
                        continue;
                    }

            while(str[i+1] == ' ')
                i++;
                    }

        nstr += str[i++];
            }
    Myfile << nstr;

    }


    MyReadFile.close();
    Myfile.close();

cout << "Removing excess blanks from input file " << endl;
cout << "Excess blanks removed! ";
    return 0;
}
