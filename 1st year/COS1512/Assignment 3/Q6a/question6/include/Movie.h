#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include<string>
#include "Movie.h"

using namespace std;
class Movie
{
    public:
        Movie(string mName, string fpbRating);
        void setmName(string sname);
        void setfpbRating(string srating);
        string getmName();
        string getfpbRating();
        void addRating(int irating);
        double getAverage();
        ~Movie();

    private:
    string name;
    string rating;
    int ratings[5];
    double avratings = 0;
};

#endif // MOVIE_H
