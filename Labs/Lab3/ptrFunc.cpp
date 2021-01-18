#include <iostream>
#include <string>
using namespace std;

bool varEquality(double *ptr1, double *ptr2);
bool addEquality(double *ptr1, double *ptr2);

int main()
{
	double data=0;
	double *ptr1 = &data;
	double *ptr2 = &data;
	cout<<varEquality(ptr1,ptr2)<<endl;
	cout<<"the address are equivalent: "<<addEquality(ptr1,ptr2)<<endl;
	
	return 0;
}

bool addEquality(double *ptr1, double *ptr2)
{
	if(&ptr1==&ptr2)
		return true;
	else
		return false;
}

bool varEquality(double *ptr1, double *ptr2)
{
	if(*ptr1==*ptr2)
		return true;
	else
		return false;
}

