#include <iostream>
#include <string>

using namespace std;


string initials(string name)
{
   int space, space2;
   string snew,snew2,sl;
   space = name.find(" ",0);
   space2 = name.find(" ",space);

     snew = name.erase(1,space);
     snew2 = name.substr(space+1);

   return snew+snew2;
}





int main()
{

string sname;
 cout << "Please enter name" << endl;
 getline(cin, sname);
  cout << initials(sname);


switch(inum)



    return 0;
}
