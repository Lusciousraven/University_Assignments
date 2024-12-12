#include "Movie.h"
#include <iostream>

Movie::Movie(string mName, string fpbRating)
{
        name = mName;
        rating = fpbRating;
        ratings[0] = ratings[1] = ratings[2] = ratings[3] = ratings[4] = 0;
}


void Movie::setmName(string sname)
{
    name = sname;
}

void Movie::setfpbRating(string srating)
{
    rating = srating;
}

string Movie::getmName()
{
    return name;
}

string Movie::getfpbRating()
{
    return rating;
}

void Movie::addRating(int irating)
{
    if (irating>0 && irating<6)
        {
            switch(irating)
            {
                case 1: ratings[0]++;
                        avratings = avratings + 1;
                        break;
                case 2: ratings[1]++;
                        avratings = avratings + 2;
                        break;
                case 3: ratings[2]++;
                        avratings = avratings + 3;
                        break;
                case 4: ratings[3]++;
                        avratings = avratings + 4;
                        break;
                case 5: ratings[4]++;
                        avratings = avratings + 5;
                        break;
            }
        }
        else cout << "Please enter a rating from 1-5 " << endl;
}

double Movie::getAverage()
{
        double average;

        average = avratings/5;

        return average;
}




Movie::~Movie()
{
    //dtor
}
