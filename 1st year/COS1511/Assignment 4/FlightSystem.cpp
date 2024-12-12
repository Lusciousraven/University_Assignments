#include <iostream>
#include <string>
using namespace std;
const double flightTimes[5][2] = {{7.00 ,9.30},{9.00
,11.30},{11.00,13.30},{13.00,15.30},{15.00,17.30}};
const float tPrice = 1600.00;
const int NUM = 10;
struct booking
{
 string sName, sClass, sNumber;
 float arTime, deTime;
};
void menu(int &choice)
{
 cout << "The available travel times for flights are: " << endl;
 cout << " Depart" << " Arrive" << endl;
 for (int i = 0; i < 5; i++)
 {
 cout << i + 1 << "." << " " << flightTimes[i][0] << " " << flightTimes[i][1] << endl;
 }
 cout << "Choose the time by entering the option number from the displayed list:" << endl;
 cin >> choice;
 while ((choice < 1) || (choice > 5))
 {
 cout << "Incorrect option! Please choose from 1-5." << endl;
 cin >> choice;
 }
}
bool validateSeat(booking b[], string sNo, int tChoice)
{
 bool notbooked = true;
 float dTime;
 dTime = flightTimes[tChoice - 1 ][0];
 int i = 0;
 while (i < NUM)
 {
 if(b[i].sNumber == sNo && b[i].deTime == dTime)
 {
 notbooked = false;
 }
 i++;
 }
 if (notbooked == false)
 {
 return false;
 }
 else return true;
}
float calculateTprice(booking b)
{
 float price = 0.0;
 if ((b.sNumber.substr(0,1)) > "D")
 price = tPrice;
 else price = tPrice + (tPrice * 0.2);
 return price;
}
void displayTicket (booking b)
{
 cout << " " << "*" << endl;
 if ((b.sNumber.substr(0,1)) > "D")
 b.sClass = "Economy class" ;
 else b.sClass = "First class";
 cout << "Travel ticket for FLIGHT " << endl;
 cout << " " << "*" << endl;
 cout << " " << "Name :" << b.sName;
 cout << " " << "Travel ticket class: " << b.sClass << endl;
 cout << " " << "** Seat No: " << b.sNumber << endl;
 cout << " " << "Departure: " << " Johannesburg";
 cout << " " << "Departure Time: " << b.deTime << endl;
 cout << " " << "Destination: " << " Cape Town";
 cout << " " << "Arrival Time: " << b.arTime << endl;
 cout << " " << "*" << endl;
 cout << "Amount: R" << calculateTprice(b);
 cout << "Thank you for booking with COS1511. Your travel agent for queries is Annie Matthew" <<
endl;
 cout << " " << "*" << endl;
}
void seatArrangement()
{
 char row = 'A';
 int col = 1;
 string sNo;
 int iSeat = 0;
 int i;
 cout << "First class(" << tPrice + (tPrice*0.2) << ")" << endl;
 for (int i = 1; i < 51; i++)
 {
 sNo = "";
 if (i == 25)
 {
 cout << "Economy class(" << tPrice << ")" << endl;
 cout << "|";
 }
 sNo += row;
 sNo += to_string(col);
 if (i == 1)
 {
 cout << "|";
 }
 cout << sNo;
 col++;
 if (i % 3 == 0)
 {
 if (iSeat == 0)
 {
 cout << "|" << "----";
 iSeat = 1;
 }
 else
 {
 cout << "|" << endl;
 row = row + 1;
 col = 1;
 iSeat = 0;
 }
 }
 cout << "|";
}
}
void seatArrangement2(booking b[], int tchoice )
{
 char row = 'A';
 int col = 1;
 string sNo;
 int iSeat = 0;
 int i;
 bool notbooked;
 cout << "First class(" << tPrice + (tPrice*0.2) << ")" << endl;
 for (int i = 1; i < 51; i++)
 {
 sNo = "";
 if (i == 25)
 {
 cout << "Economy class(" << tPrice << ")" << endl;
 cout << "|";
 }
 sNo += row;
 sNo += to_string(col);
 cout << sNo;
 col++;
 notbooked = validateSeat(b,sNo,tchoice);
 if(notbooked == false)
 {
 cout << "**";
 col++;
 }
 else cout << row << col++;
 if (i % 3 == 0)
 {
 if (iSeat == 0)
 {
 cout << "|" << "----";
 iSeat = 1;
 }
 else
 {
 cout << "|" << endl;
 row = row + 1;
 col = 1;
 iSeat = 0;
 }
 }
 cout << "|";
}
}
int main()
{
 string name, seatNo;
 int tChoice;
 char ans;
 int i = 0;
 int t1,t2,t3,t4,t5 = 0;
 int time;
 booking b1[NUM];
 do
 {
 cout << "Welcome to COS1511 Flight Booking system" << endl << endl;
 cout << "Enter full name" << endl;
 getline(cin, name);
 cout << endl;
 cout.setf(ios::fixed);
 cout.precision(2);
 menu(tChoice);
 cout << "The available seats for "<< flightTimes[tChoice - 1][0] << " are as follows: " << endl;
 switch (tChoice)
 {
 case 1 : time = t1;
 break;
 case 2 : time = t2;
 break;
 case 3 : time = t3;
 break;
 case 4 : time = t4;
 break;
 case 5 : time = t5;
 break;
 }
 if (time == 0)
 {
 seatArrangement();
 cout << endl;
 cout << "Please key in a seat number to choose a seat (eg:A2)" << endl;
 }
 else
 {
 seatArrangement2(b1, tChoice);
 cout << "Please note seats already taken are indicated with a *" << endl;
 cout << "Please key in a seat number to choose a seat (eg:A2)" << endl;
 }
 do
 {
 cin >> seatNo;
 if (!validateSeat(b1, seatNo,tChoice))
 cout << "Sorry seat is taken." << endl;
 }
 while (!validateSeat(b1, seatNo,tChoice));
 b1[i].sName = name;
 if (seatNo.substr(0,1) > "D")
 b1[i].sClass = "Economy class";
 else
 b1[i].sClass = "First class";
 b1[i].deTime = flightTimes[tChoice - 1][0];
 b1[i].arTime = flightTimes[tChoice -1][1];
 b1[i].sNumber = seatNo;
 displayTicket(b1[i]);
 i++;
 cout << "Do you want to make another booking (Y/N) " << endl;
 cin >> ans;
 cin.get();
 if (tChoice == 1)
 t1++;
 else if (tChoice == 2)
 t2++;
 else if (tChoice == 3)
 t3++;
 else if (tChoice == 4)
 t4++;
 else if (tChoice == 5)
 t5++;
 }
 while (toupper(ans) == 'Y');
 cout << endl;
 cout << "Number of bookings made for " << flightTimes[0][0] << "a.m" << " " << t1 << endl;
 cout << "Number of bookings made for " << flightTimes[1][0] << "a.m" << " " << t2 << endl;
 cout << "Number of bookings made for " << flightTimes[2][0] << "a.m" << " " << t3 << endl;
 cout << "Number of bookings made for " << flightTimes[3][0] << "p.m" << " " << t4 << endl;
 cout << "Number of bookings made for " << flightTimes[4][0] << "p.m" << " " << t5 << endl;
 return 0;
}
