#include <iostream>
#include<fstream>
#include "Movie.h"

using namespace std;



int main()
{




        Movie Movie1("Your name", "16");
        Movie1.addRating(4);
        Movie1.addRating(3);
        Movie1.addRating(5);
        Movie1.addRating(3);
        Movie1.addRating(2);

        Movie Movie2("Lord of the rings", "18");
        Movie2.addRating(5);
        Movie2.addRating(2);
        Movie2.addRating(4);
        Movie2.addRating(2);
        Movie2.addRating(1);

        cout << "Movie name: " << Movie1.getmName() << endl;
        cout << "FPB rating: " << Movie1.getfpbRating() << endl;
        cout << "Average rating: " << Movie1.getAverage() << endl;

        cout << "Movie name: " << Movie2.getmName() << endl;
        cout << "FPB rating: " << Movie2.getfpbRating() << endl;
        cout << "Average rating: " << Movie2.getAverage() << endl;


    return 0;
}

