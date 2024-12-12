#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int getScore()
{int testScore;//testScore2,testScore3,testScore4,testScore5;

    cout<<"Enter test score ";
    cin>>testScore;
    cout<<endl;

         while (testScore < 0 || testScore > 100) //&& testScore2 < 0 || testScore2 > 100 && testScore3 < 0 || testScore3 > 100 &&
           //testScore4 < 0 || testScore4 > 100 && testScore5 < 0 || testScore5 > 100)
    {
        cout << "You have entered an invalid number\n";
        cout << "Please enter a number from 0-100 for each test score: ";
        cin >> testScore; //>> testScore2 >> testScore3 >> testScore4 >> testScore5;
    }
    return testScore;
}


int findLowest (vector< int > v)
{ 
    int lowest =100;
    sort(v.begin(), v.end());
    lowest = v.front();
    return lowest;
}


float calcAverage(vector< int > v)
{   
    int lowestnum, sum;
    float average;

	v.erase(v.begin());
	sum = accumulate(v.begin(), v.end(), 0);

    average = sum / 4;
    	
	return average;
}


void displayOutput(vector< int > v)
{
cout<<"average is " << fixed << setprecision(2) << calcAverage(v)<<endl;
}


int main()

{
    vector< int > v;
    int testScore1,testScore2,testScore3,testScore4,testScore5;

        testScore1 = getScore();
        testScore2 = getScore();
        testScore3 = getScore();
        testScore4 = getScore();
        testScore5 = getScore();
        v.push_back(testScore1);
        v.push_back(testScore2);
        v.push_back(testScore3);
        v.push_back(testScore4);
        v.push_back(testScore5);

    	
        displayOutput(v);

return 0;
}
