//Redo this question
#include <iostream>

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

    int findLowest (int &testScore1,int &testScore2,int &testScore3,int &testScore4,int &testScore5)
{   int lowest=100;

    	if(testScore1<lowest)
	{
        	lowest = testScore1;
	}
  	if(testScore2<lowest)
	{
        	lowest = testScore2;
	}
        if(testScore3<lowest)
	{
        	lowest = testScore3;
	}
        if(testScore4<lowest)
	{
        	lowest = testScore4;
	}
        if(testScore5<lowest)
	{
        	lowest = testScore5;
	}

return lowest;


}


float calcAverage(int &testScore1,int &testScore2,int &testScore3,int &testScore4,int &testScore5)
{
    int lowestnum, sum;
    float average;

        //getScore();
	lowestnum = findLowest(testScore1,testScore2,testScore3,testScore4,testScore5);
	sum = testScore1 + testScore2 + testScore3 + testScore4 + testScore5 - lowestnum;

    	average = sum / 4;
    cout.setf(ios::fixed);
    cout.precision(2);

    	cout<<"Average of test scores after dropping lowest number is "<< average<<endl;

	return average;
}


void displayOutput(int &testScore1,int &testScore2,int &testScore3,int &testScore4,int &testScore5)
{   // int testScore1,testScore2,testScore3,testScore4,testScore5;


cout<<"average is "<<calcAverage<<endl;
cout.setf(ios::fixed);
cout.precision(2);
//calcAverage();


}


int main()

{
    int testScore1,testScore2,testScore3,testScore4,testScore5;

        testScore1 = getScore();
        testScore2 = getScore();
        testScore3 = getScore();
        testScore4 = getScore();
        testScore5 = getScore();
        calcAverage(testScore1,testScore2,testScore3,testScore4,testScore5);

    	//findLowest(testScore1,testScore2,testScore3,testScore4,testScore5);
        displayOutput;

return 0;
}
