#include<iostream>
#include <string>
using namespace std;

int main() {

const int THISYEAR = 2006;
string yourName;
int birthYear;
cout << " What is your name? " << flush;
cin >> yourName;
cout << "What year were you born? " ;
cin >> birthYear;
cout << "Your name is " << yourName
<< " and you are approximately "
<< (THISYEAR - birthYear)
<< " years old. " << endl;
}