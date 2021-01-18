#include <iostream>
#include <string.h>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};


int main()
{
	int num = 5;	
	//int *intPtr = NULL;
	intPtr = &num;
	num = num*10;
	cout <<"\tintPtr points to :\t\t\t\t" << *intPtr << endl;

	struct RecType *recPtr;
	recPtr = new RecType;
	
	recPtr->age=25;
	recPtr->weight=190;
	recPtr->gender='M';
	recPtr->age=30;

	cout<<"\tThree Fields Pointed to By recPtr :\t\t" <<recPtr->age<<" "<<recPtr->weight<<" "<<recPtr->gender<<endl;

	delete recPtr;
	recPtr=NULL; 

	char *strPtr = new char [50];
	strcpy (strPtr, "Operating Systems"); 
	cout<<"\tstrPtr points to :\t\t\t\t" << strPtr<<endl;	
	
	int lowercount = 0;
	for(int i=0; i<=strlen(strPtr); i++)
	{
		if(islower(*(strPtr+i)))
			lowercount++;
			
	}
	cout<<"\tLowerCase Letters Pointed To By strPtr :\t" <<lowercount<<endl;
	
	strPtr=strPtr+10;

	cout<<"\tPrinting strPtr after adding 10 :\t\t"<<(strPtr)<< endl;
	
	strPtr=strPtr-10;
	delete strPtr;
	
	return 0;

}	
