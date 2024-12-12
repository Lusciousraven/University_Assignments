#include "Money.h"

Money::Money()
{
 rands = 0;
 cents = 0;
}

Money::Money(int r, int c)
{
 rands = r;
 cents = c;
}

int Money::theRands() const
{
 return rands;
}

int Money::theCents() const
{
 return cents;
}

Money Money::Plus(Money m)
{
    Money sum;
    int i;

    i = (cents + m.cents) + (100 * (rands + m.rands ));
    sum.rands = i / 100;
    sum.cents = i % 100;
    return sum;
}


Money Money::operator+ (Money &m)
{
    Money sum;
    int i;

    i = (cents + m.cents) + (100 * (rands + m.rands ));
    sum.rands = i / 100;
    sum.cents = i % 100;
    return sum;
}

bool Money::GreaterThan(Money m)
{
    return ((100*rands + cents) > (100*m.theRands() + m.theCents()));

}

ostream &operator<<(ostream &ocout, const Money &m)
{
    if (m.theCents() < 10)
        ocout << "R" << m.theRands() << ".0" << m.theCents() ;
    else
        ocout << "R" << m.theRands() << "." << m.theCents() ;
    return ocout;
}

Money::~Money()
{
    //dtor
}
