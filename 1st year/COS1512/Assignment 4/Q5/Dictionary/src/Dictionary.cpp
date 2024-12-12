#include "Dictionary.h"
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;

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
