#include <iostream>

using namespace std;

class Marks

{

public:

//constructors

Marks();

Marks (string name, string number, int asg1, int asg2,

int asg3, double test);

//const functions

double calcMark() const;

double getAssignmentMarks() const;

string getName() const;

string getStudentNumber()const;

private:

//member variables

string stdtName;

string stdNumber;

int assignments[3];

double testMark;

};

//default constructor initializing variables

Marks :: Marks(){

stdtName = "Jack";

stdNumber = "67454614";

assignments[0] = 67;

assignments[1]= 74;

assignments[2] = 60;

testMark = 77;

}

//Parameterized constructor initializing variables

Marks :: Marks(string name, string number, int asg1, int asg2,

int asg3, double test){

stdtName = name;

stdNumber = number;

assignments[0] = asg1;

assignments[1]= asg2;

assignments[2] = asg3;

testMark = test;

}

//function provides the net assignment marks

double Marks :: getAssignmentMarks() const{

return assignments[0] + assignments[1] + assignments[2];

};

//function provides the marks value

double Marks :: calcMark() const{

return testMark;

}

//function provides the student name

string Marks::getName() const{

return stdtName;

}

//function provides the student number

string Marks::getStudentNumber() const{

return stdNumber;

}

//child class Final Mark, public inheritance

class FinalMark : public Marks

{

double examMark;

public:

FinalMark()

: Marks{}{

examMark = 78;

}

//parameterized constructor calling Marks constructor as well

FinalMark(string name, string number, int asg1, int asg2,
          int asg3, double test, double eMark) : Marks{name, number, asg1, asg2, asg3, test}
{
    examMark = eMark;
}

//function provides the computed marks

int calcMark(){

double testValue = 0.2 * Marks::calcMark();

double avg = (Marks::getAssignmentMarks())/3.0;

double value = testValue + avg * 0.1 + 0.7 * examMark;

return int(value);

}

};

int main()

{

// Marks class object

Marks marks;

cout<<marks.getName() <<" has got "<<marks.calcMark() << " marks\n";

//FinalMark object

FinalMark myMark;

cout<<myMark.getName() <<" "<< myMark.getStudentNumber()<<" has got "<<myMark.calcMark() << " marks\n";

//parameterized FinalMark object

FinalMark newMark("John ", "63483215 ", 67, 89, 80, 95.1, 90);

cout<<newMark.getName()<<"has final mark of "<<newMark.calcMark() << " marks";

return 0;

}
