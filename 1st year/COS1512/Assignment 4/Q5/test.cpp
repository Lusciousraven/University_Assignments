#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;

template<class Tkeys, class Tvalues>

class Dictionary
{
 public:
 Dictionary();
 void add(Tkeys key,const Tvalues &value);
 Tvalues find (Tkeys key);
 void display();

 private:
 vector<Tkeys> keys;
 vector<Tvalues> values;
};

template<class Tkeys, class Tvalues>
Dictionary<Tkeys, Tvalues>::Dictionary()
{
 //nothing to do, vector member variables are empty on
 //declaration
};

template<class Tkeys, class Tvalues>
void Dictionary<Tkeys, Tvalues>::add(Tkeys key,const Tvalues &value)
{
 keys.push_back(key);
 values.push_back(value);
}

template<class Tkeys, class Tvalues>
Tvalues Dictionary<Tkeys, Tvalues>::find (Tkeys key)
{
 for (int i = 0; i < keys.size(); i++)
 {
     if (key == keys[i])
     return values[i];
     else return "no such key can be found";
 }

}

template<class Tkeys, class Tvalues>
void Dictionary<Tkeys, Tvalues>::display()
{
 for (unsigned int i = 0; i < keys.size(); i++)
 cout << keys[i] << ' ' << values[i] << endl;

}

int main()
{
 Dictionary <int,string> parts;


 string part;

 int key;

 //add 4 values to the parts dictionary
 for (int i = 0; i <= 3; i++)
 {
 cout << "Please enter a part name and a key to add to the parts dictionary." << endl;

 cout << "Part name: ";

 getline(cin, part);

 cout << "Key for part name: ";

 cin >> key;


 parts.add(key, part);
 //cin.get();
 }

 cout << endl;

 parts.display();

 cout << endl;
 //find the part for a key

 cout << "For which key do you want to find the part? ";

 cin >> key;

 cout << "The part for key " << key << " is ";

 cout << parts.find(key) << endl;
 // cout << parts.find(100002);
 return 0;
}
