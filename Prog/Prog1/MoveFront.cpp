#include<iostream>

using namespace std;
#include"dlist.h"


void PrintMenu(char& a);
void HeadInsert(DList<int>& list);
void TailInsert(DList<int>& list);
void AccessItem(DList<int>& list);
void Delete(DList<int>& list);
void PrintList(DList<int>& list);
void FindAndMove(DList<int>& list,int x);
void PrintLength(DList<int>& list);

int main()
{

	DList<int> list;
	char sel;

	do
	{
		PrintMenu (sel);
		switch (toupper(sel))
		{
			case 'H' : 
				HeadInsert(list);
				 break;
			case 'T' :
				 TailInsert(list);
				 break;
			case 'A' :
				 AccessItem(list); 
				break;
			case 'D' :
				 Delete(list);
				 break;
			case 'P' :
				 PrintList(list);
				 break;
			case 'L' :
				 PrintLength(list);
				 break;
			case 'Q' :
				 cout<< "\tExiting Program...\n";
				 break;
			default :
				 cout<<"\tError. Try Again." <<endl;	
		}
	}while (toupper(sel) != 'Q');

	return 0;

}

//Menu
void PrintMenu(char & sel)
{

	cout<<"|-----------------------------|"<<endl;
	cout<<"|------------Menu-------------|"<<endl;
	cout<<"|-----------------------------|"<<endl;
	cout<<"|                             |"<<endl;
	cout<<"| H: Insert item at front     |"<<endl;
	cout<<"| T: Insert item at back      |"<<endl;
	cout<<"| A: Access an item in list   |"<<endl;
	cout<<"| D: Delete an item in list   |"<<endl;
	cout<<"| P: Print the list           |"<<endl;
	cout<<"| L: Print the list's length  |"<<endl;
	cout<<"| Q: Quit the program         |"<<endl;
	cout<<"|                             |"<<endl;
	cout<<"|-----------------------------|"<<endl;
	cout<<"|                             |"<<endl;
	cout<<"|  Please enter your choice:  |"<<endl;
	cin>> sel;
}

//add item to head of list using .insertHead
void HeadInsert(DList<int> &list)
{
	int item;
	cout<<"\v\t Item to be Inserted to the Front of List : ";
	cin >> item;
	if(! list.inList(item))
		list.insertHead(item);
	else
		cout<<"\t Item already Exists. No Duplicates Allowed."<<endl;
}

//add item to tail using .appendTail
void TailInsert(DList<int>& list)
{
	int item;
	cout<< "\v\t Item to be inserted to the tail of List : ";
	cin >> item;
	if( ! list.inList(item))
		list.appendTail(item);
	else
		cout<<"\t Item already Exists. No Duplicates Allowed." <<endl;
	
}

//access item in list using .inList
void AccessItem(DList<int>& list)
{
	if( ! list.isEmpty())
	{
		int item;
		cout <<"\v\t Item to be Accessed in the List : ";
		cin >> item;
		FindAndMove(list,item);
	}
	else
		cout<<"\t Error -- List is Empty. " << endl;


}

//delete from list using .deleteItem
void Delete(DList<int>& list)
{	
	int item;
	cout << "\v\t Item to be deleted : ";
	cin >> item;
	if(list.inList(item))
		list.deleteItem(item);
	else if(list.isEmpty())
		cout<<"\t Error -- List is Empty."<<endl;
	else
		cout<<"\t Item does dot Exist in List"<<endl;
}

//print list using .print
void PrintList(DList<int>& list)
{
	if(! list.isEmpty())
		list.print();
	else
		cout<<"\t Error -- List is Empty."<<endl;
}

//print length using .length
void PrintLength(DList<int> &list)
{
	cout<<"The length is "<< list.lengthIs()<<endl;
}

//moving item in list
void FindAndMove(DList<int>& list, int item)
{
	list.deleteItem(item);
	list.insertHead(item);
}
