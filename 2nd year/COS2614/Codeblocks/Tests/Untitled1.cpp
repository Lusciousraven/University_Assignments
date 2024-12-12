#include <assert.h>
#include <iostream>
#include <string>
using namespace std;


/*int main(int argc, char* argv[]) //the char* argv[] if declared inside int main does not give an error.. why
{

int i=0;
char array1[34] = "This is a dreaded C array of char";
char array2[] = "if not for main, we could avoid it entirely.";
char *charp = array1;
string stlstring = "This is an Standard Library string. Much preferred." ;
assert (sizeof(i) == sizeof(int));
cout << "sizeof char = " << sizeof(char) << '\n';
cout << "sizeof wchar_t = " << sizeof(wchar_t) << '\n';
cout << "sizeof int = " << sizeof(int) << '\n';
cout << "sizeof long = " << sizeof(long) << '\n';
cout << "sizeof float = " << sizeof(float) << '\n';
cout << "sizeof double = " << sizeof(double) << '\n';
cout << "sizeof double* = " << sizeof(double*) << '\n';
cout << "sizeof array1 = " << sizeof(array1) << '\n';
cout << "sizeof array2 = " << sizeof(array2) << '\n';
cout << "sizeof stlstring = " << sizeof(stlstring) << endl;
cout << "length of stlstring= " << stlstring.length() << endl;
cout << "sizeof char* = " << sizeof(charp) << endl;
return 0;
}*/

int main() {
const char tab = '\t';
int n = 13;
int* ip = new int(n + 3);
double d = 3.14;
double* dp = new double(d + 2.3);
char c = 'K';
char* cp = new char(c + 5);
cout << *ip << tab << *dp << tab << *cp << endl;
int* ip2 = ip;
cout << ip << tab << ip2 << endl;
*ip2 += 6;
cout << *ip << endl;
delete ip;
cout << *ip2 << endl;
cout << ip << tab << ip2 << endl;
}
