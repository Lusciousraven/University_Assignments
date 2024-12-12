#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;


int main() {

    string str;
    bool test = true;
    cout << "Enter a word to check if it's a Palindrome" << endl;
    cin >> str;

    int n = str.length();
    char char_array[n];
    char char_array2[n];
    char temp;

    strcpy(char_array, str.c_str());

    temp = char_array[0];



    for (int i = 0; i < n; i++){

        if(i==n-1){
            char_array2[i] = temp;
        }else{
            char_array2[i] = char_array[i+1];
        }

    }
    char_array2[n] = temp;


    for (int i = 0; i < n; i++){

        if(char_array[i]!=char_array2[n-1-i]){
        test = false;
        }

    }

    if(test){
        cout<< str << " is a Palindrome when first letter is moved to the back" << endl;
    }else{
        cout << str << " is not a Palindrome when first letter is moved to the back" << endl;
    }

    return 0;
}
