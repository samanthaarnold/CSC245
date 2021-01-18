#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;


void Initialize(vector<int> &v);
void Print(vector<int> &v);
void Reverse(vector<int> &v);

int main()
{
	stack<string> s1, s2;
	s1.push("Hi There");
	s2.push("Welcome to lab 3");
	
	if(s1==s2)
		cout<<"s1 and s2 are equal"<<endl;
	else if (s1<s2)
		cout<<"s1 is less than s2"<<endl;
	else
		cout<<"s1 is greater than s2"<<endl;

	vector<int> v;
	Initialize(v);
	Print(v);
	Reverse(v);
	Print(v);
	sort(v.begin(),v.end());
	Print(v);
	return 0;

}

void Initialize(vector<int> &v)
{
	int a,b,c,d,e;
	for(int i=0; i<5; i++)
	{
		cout<<"Please enter an integer: "<<endl;
		cin>>a;
		v.push_back(a);
	}
}

void Print(vector<int> &v)
{
	for(int z=0; z<5; z++)
		cout<<v.at(z)<<" "<<endl;
}

void Reverse(vector<int> &v)
{
	int temp;
	int int1=0;
	int int2=4;
	while(int1<int2)
	{
		temp=v.at(int1);
		v.at(int1)=v.at(int2);
		v.at(int2)=temp;
		int1++;
		int2--;
	}

} 	
