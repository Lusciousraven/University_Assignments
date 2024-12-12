#include <iostream>
#include<string>


using namespace std;


class Marks
{

public:
 Marks();

 Marks (string name, string number, int asg1, int asg2, int asg3, double test);

 double calcMark() const;

 string getName() const;

 string getNumber() const;

 double getassignmentMarks()const;



private:
 string stdtName;
 string stdNumber;
 int assignments [3];
 double testMark;

};

Marks::Marks()
{
    stdtName = "Eric";

    stdNumber = "654653176 ";

    assignments[0] = 67;

    assignments[1] = 74;

    assignments[2] = 60;

    testMark = 77;

}


Marks::Marks(string name, string number, int asg1, int asg2, int asg3, double test)

{
    stdtName = name;

    stdNumber = number;

    assignments[0] = asg1;

    assignments[1] = asg2;

    assignments[2] = asg3;

    testMark = test;
}


double Marks::calcMark() const
{
    return testMark;
}



string Marks::getName() const
{
    return stdtName;
}



string Marks::getNumber() const
{
    return stdNumber;
}


double Marks:: getassignmentMarks() const
{
    return(assignments[0] + assignments[1] + assignments[2]);
}


////
////
class FinalMark : public Marks
{

 double eMark;

 public:

FinalMark(): Marks{}
{
    eMark = 78;
}

FinalMark(string name, string number, int asg1, int asg2,
          int asg3, double test, double exMark) : Marks{name, number, asg1, asg2, asg3, test}
{
    eMark = exMark;
}


int calcMark() const
{
    double asgMarks, test, fmark;

    test =  Marks::calcMark();

    asgMarks = (Marks::getassignmentMarks())/3.0;

    fmark = test*0.2 + asgMarks*0.1 + eMark*0.7;

    return int(fmark);
}
};



 int main()
 {


    Marks marks;

    cout<< marks.getName() << ", " << marks.getNumber() << "has got "<<marks.calcMark() << " marks " << endl;



    FinalMark myMark;

    cout<<myMark.getName() <<", "<< myMark.getNumber()<<"has final mark of "<<myMark.calcMark() << " marks " << endl;



     return 0;
 }
