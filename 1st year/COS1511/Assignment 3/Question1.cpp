#include <iostream>

using namespace std;

//Question 1.1
void getData(float &weight, float &height)
{
   cout << "Please input your weight in KG ";
   cin >> weight;
   cout << "Please input your height in M ";
   cin >> height;
}

//Question 1.2
float calcBMI(float weight, float height)
{
    float BMI;
    BMI = weight/(height*height);
    return BMI;
}

//Question 1.3
string displayFitnessResults (float BMI)
{
    string message;

    if (BMI<18.5)
        message = "Underweight";
    else if(BMI >= 18.5 && BMI <= 24.9) // else if used if value being compared in this case BMI is the only one,
        message = "Healthy";            // if there are others use if statements only, no else.
    else if(BMI >= 25.0 && BMI <= 29.9)
        message = "Overweight";
    else if (BMI >= 30.0)
        message = "Obese";

    return message;
}


//Question 1.4
int main()
{
    float weight, height, BMI;
    string message;

        getData(weight,height);
        BMI = calcBMI(weight,height);
        message = displayFitnessResults(BMI);

        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Your BMI is " << BMI << endl;
        cout << "Weight status: " << message << endl;

   return 0;
}
