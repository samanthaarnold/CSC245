#include "time.h"
#include <iostream>
using namespace std;

int main(){

	Time myTime(9,30,0);
	myTime.Write();

	
	myTime.WriteAmPm();

	myTime.Set(8,0,0);
	myTime.Write();
	myTime.mealTime();
	return 0;
}

void Time::WriteAmPm() const
{
	bool am;
	int tempHrs;

	am = (hrs <= 11);
	if (hrs == 0)
		tempHrs = 12;
	else if (hrs >= 13)
		tempHrs = hrs-12;
	else
		tempHrs = hrs;

	if (tempHrs <10)
		cout << '0';
	cout << tempHrs << ':';
	if (mins < 10)
		cout<<'0';
	cout << mins << ':';
	if (secs <10)
		cout << '0';
	cout<<secs;
	if(am)
		cout<<" AM";
	else
		cout<<" PM";

	cout<<endl;

}

Time::~Time()
{
	cout << "Destructor Called" << endl;
}

void Time::mealTime() const 
{
	if(hrs==8 && mins==0 && secs==0)
		{cout<<"Breakfast"<<endl;}
	else if(hrs==12 && mins==0 && secs==0)
		{cout<<"Lunch"<<endl;}	
	else if(hrs==7 && mins==0 && secs==0)
		{cout<<"Dinner"<<endl;}
}
