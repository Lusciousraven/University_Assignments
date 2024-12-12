#ifndef DICTIONARY_H
#define DICTIONARY_H
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
#endif // DICTIONARY_H
