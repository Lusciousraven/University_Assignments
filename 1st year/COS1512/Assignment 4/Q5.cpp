#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Dictionary {
public:
Dictionary();
void Add(int key, const string &value);
string Find (int key) const;
private:
vector<int> Keys;
vector<string> Values;
};



int main()
{


    return 0;
}
