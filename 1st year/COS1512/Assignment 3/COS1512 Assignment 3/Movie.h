#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;


class Movie
{
    public:
        Movie();

    void setmName(string sname)

    void setfpbRating(string srating)

    string getmName()

    string getfpbRating()

    void addRating(int irating)

    double getAverage()


    private:
    string name;
    string rating;
    int ratings[5];
};

#endif // MOVIE_H
