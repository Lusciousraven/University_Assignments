#ifndef MONEY_H
#define MONEY_H
#include <iostream>


using namespace std;
class Money
{
    public:
         Money();
         Money(int r, int c);
        ~Money();
         int theRands() const;
         int theCents() const;
         Money Plus(Money m);
         Money operator+ (Money & m);
         bool GreaterThan(Money m);
         friend ostream &operator<<(ostream &ocout, const Money &m);
         friend bool operator > (const Money m1, const Money m2);



    private:
        int rands;
        int cents;

};

#endif // MONEY_H
