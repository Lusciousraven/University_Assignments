#include<iostream>
#include<vector>
using namespace std;

void SplitString(string s, vector<string> &v){

	string temp = "";
	for(int i=0;i<s.length();++i){

		if(s[i]==' '){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}



int main() {

	string s;
	vector<string> v = {"what", "book",  "is", "that", "you", "are", "reading"};
    for(int i=0;i<v.size();++i)
		cout<<v[i]<< " ";

    cout<<endl;
    getline(cin,s);


	SplitString(s, v);

	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;


}
