#include <iostream>

using namespace std;

//Question 2a
void studentDetails(string &name, string &surname, string&schoolName)
{
    cout << "Please enter your first name: " << endl;
    getline(cin, name, '\n');
    cout << "Please enter your  surname: " << endl;
    getline(cin, surname, '\n');
    cout << "Please enter your  Schoolname: " << endl;
    getline(cin, schoolName, '\n');

}

//Question 2b
void getMarks(int &markEnglish,int &markMaths,int &markLO,int &markHistory,int &markComputerL,int &markGeography)
{
    cout << "Please enter your mark for English: " << endl;
    cin >> markEnglish;

    while (markEnglish<0 || markEnglish>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markEnglish;}

    cout << "Please enter your mark for Mathematics: " << endl;
    cin >> markMaths;

    while (markMaths<0 || markMaths>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markMaths;}

    cout << "Please enter your mark for Life Orientation: " << endl;
    cin >> markLO;

    while (markLO<0 || markLO>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markLO;}

    cout << "Please enter your mark for History: " << endl;
    cin >> markHistory;

    while (markHistory<0 || markHistory>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markHistory;}

    cout << "Please enter your mark for Computer Literacy: " << endl;
    cin >> markComputerL;

    while (markComputerL<0 || markComputerL>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markComputerL;}

    cout << "Please enter your mark for Geography: " << endl;
    cin >> markGeography;

    while (markGeography<0 || markGeography>100)
        {cout << "Please enter a mark between 0-100" << endl;
        cin >> markGeography;}

}

//Question 2c
void calcAverageYearMark(float markEnglish,float markMaths,float markLO,float markHistory,float markComputerL,float markGeography)
{
    float average;
    float sum;
    string symbol, code;

    sum = (markEnglish + markMaths + markLO + markHistory + markComputerL + markGeography);
    average = sum / 6;

    cout.setf(ios::fixed);
    cout.precision(2);

    switch(int(average))
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << endl;
                            cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                             code = "6";
                             cout << endl;
                             cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << endl;
                           cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << endl;
                           cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << endl;
                            cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << endl;
                            cout << "Average Year Mark: " << average << "%"  << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                            code = "1";
                            cout << endl;
                            cout << "Average Year Mark: " << average << "%" << " with Symbol " << symbol << " and code " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }




}

//Question 2d
void minMax(int markEnglish,int markMaths,int markLO,int markHistory,int markComputerL,int markGeography)
{
    int minimum = 100, maximum = 0;

    {
    if (markEnglish < minimum)
        minimum = markEnglish;

    if (markMaths < minimum)
        minimum = markMaths;

    if (markLO < minimum)
        minimum = markLO;

    if (markHistory < minimum)
        minimum = markHistory;

    if (markComputerL < minimum)
        minimum = markComputerL;

    if (markGeography < minimum)
        minimum = markGeography;
    }

    {
    if (markEnglish > maximum)
        maximum = markEnglish;

    if (markMaths > maximum)
        maximum = markMaths;

    if (markLO > maximum)
        maximum = markLO;

    if (markHistory > maximum)
        maximum = markHistory;

    if (markComputerL > maximum)
        maximum = markComputerL;

    if (markGeography > maximum)
        maximum = markGeography;
    }

        cout << "Lowest mark was " << minimum << "%" << endl;
        cout << "Highest mark was " << maximum << "%" <<endl << endl;

}

//Question 2e
void passOrFail(int markEnglish,int markMaths,int markLO,int markHistory,int markComputerL,int markGeography)
{
    int i = 0;


    if (markEnglish >= 50)
        i++;
    else if (markEnglish < 50)
        i = i;

    if (markMaths >= 50)
        i++;
    else if (markMaths < 50)
        i = i;

    if (markLO >= 50)
        i++;
    else if (markLO < 50)
        i = i;

    if (markHistory >= 50)
        i++;
    else if (markHistory < 50)
        i = i;

    if (markComputerL >= 50)
        i++;
    else if (markComputerL < 50)
        i = i;

    if (markGeography >= 50)
        i++;
    else if (markGeography < 50)
        i = i;

        //cout << "num is " << i << endl;

        if(i>=4 && markEnglish >= 50)
            {cout << "Outcome: Passed " << endl << endl;}
        else
            {cout << "Outcome: Failed " << endl << endl;}


}

//Question 2f
void awardDistinction(int markEnglish,int markMaths,int markLO,int markHistory,int markComputerL,int markGeography)
{

    float average;
    float sum;

    sum = (markEnglish + markMaths + markLO + markHistory + markComputerL + markGeography);
    average = sum / 6;

    if (markEnglish >= 75)
        cout << "Distinction recieved for English" << endl;

    if (markMaths >= 75)
        cout << "Distinction recieved for Mathematics" << endl;

    if (markLO >= 75)
        cout << "Distinction recieved for Life Orientation" << endl;

    if (markHistory >= 75)
        cout << "Distinction recieved for History" << endl;

    if (markComputerL >= 75)
        cout << "Distinction recieved for Computer Literacy" << endl;

    if (markGeography >= 75)
        cout << "Distinction recieved for Geography" << endl;

    if (average >= 75 && markEnglish>=50)
        cout << "Passed with distinction" << endl;


}

//Question 2g
void codeSymbol(int markEnglish,int markMaths,int markLO,int markHistory,int markComputerL,int markGeography)
{
    string code, symbol;

    switch(markEnglish)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "English              " << markEnglish << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                             code = "6";
                             cout << "English              " << markEnglish << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "English              " << markEnglish << "%       ";
                           cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "English              " << markEnglish << "%       ";
                           cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "English              " << markEnglish << "%       ";
                           cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "English              " << markEnglish << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                            code = "1";
                            cout << "English              " << markEnglish << "%       ";
                           cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }

    switch(markMaths)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                            code = "6";
                            cout << "Mathematics          " << markMaths << "%       ";
                           cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                            code = "1";
                            cout << "Mathematics          " << markMaths << "%       ";
                            cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }

    switch(markLO)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                            code = "6";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                            code = "1";
                            cout << "Life Orientation     " << markLO << "%       ";
                            cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }

    switch(markHistory)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                            code = "6";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "History              " << markHistory << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                           code = "1";
                           cout << "History              " << markHistory << "%       ";
                           cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }


    switch(markComputerL)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                            code = "6";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "Computer Literacy    " << markComputerL << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                           code = "1";
                           cout << "Computer Literacy    " << markComputerL << "%       ";
                           cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;

    }


    switch(markGeography)
    {
        case 80 ... 100 :   symbol = "A";
                            code = "7";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 70 ... 79 :    symbol = "B";
                            code = "6";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 60 ... 69 :    symbol = "C";
                            code = "5";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 50 ... 59 :    symbol = "D";
                            code = "4";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 40 ... 49 :    symbol = "E";
                            code = "3";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 30 ... 39 :    symbol = "F";
                            code = "2";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "       " << code << endl;
                            break;

        case 0 ... 29 :    symbol = "FF";
                            code = "1";
                            cout << "Geography            " << markGeography << "%       ";
                            cout << symbol << "      " << code << endl;
                            break;

        default :   cout << "" ;
                    break;


    }

}


//Question 2h
void displayOutput(string name, string surname, string schoolName)
{
  cout << "***********************************************" << endl;
    cout << "               **** STUDENT ACADEMIC RECORD     " << endl;
    cout << "This program inputs the learner marks of matric " << endl << "level subjects and prints the student final report." << endl << endl;
    cout << "***********************************************" << endl;
    cout << "****" << endl;
    cout << "Name and Surname: " << name << " " << surname;
    cout << "     ";
    cout << "School: " << schoolName << endl << endl;
    cout << "Subject              " << "Mark   " << "Symbol    " << "Code " << endl;
}


int main()
{
    int markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography;
    float average;
    string name,surname,schoolName;

    studentDetails(name,surname,schoolName);

    getMarks(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);

    displayOutput(name,surname,schoolName);

    codeSymbol(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);

    calcAverageYearMark(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);

    passOrFail(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);

    minMax(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);

    awardDistinction(markEnglish,markMaths,markLO,markHistory,markComputerL,markGeography);



   return 0;
}
