#include<iostream>

using namespace std;


double max(double n1, double n2)
  //Returns the highest of the two numbers n1 and n2.
    {
        double i=0;



        if(n1>i)
            i = n1;
        if(n2>i)
            i = n2;

        return i;

    }


  double max(double n1, double n2, double n3)
  //Returns the highest of the three numbers n1, n2, and n3.
{
     double i=0;


        if(n1>i)
            i = n1;
        if(n2>i)
            i = n2;
        if(n3>i)
            i = n3;

        return i;
}

 int main( )
 {

    cout << "The highest number is " << max(5.5, 8.7) << endl;

    cout << "The highest number is " << max(67.6, 84.2, 99.9) << endl;



 return 0;
 }
