#include <queue>
#include <vector>
#include <iostream>
#include <cstdlib>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int maxElemLength(const vector<int>& v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> > & QA, int numVals);
void RadixSort(vector<int> & L, int numDigits);
void PrintVector(const vector<int> & L);
string toString(int & a);

int main(int argc, char *argv[])
{
    int b[]={380,95,345,382,260,100,492};
    vector<int> L (b, b+7); // the list to be sorted
    vector<queue<int> > QA(10); // vector of quees indexed 0-9
    RadixSort(L,maxElemLength(L));
    PrintVector(L);
   
	return 0;
}

//returns the number of digits of the largest integer within vector v
int maxElemLength(const vector<int>& v)
{
    int maxElement = *max_element(v.begin(), v.end());
    return toString(maxElement).length();
}

//returns the kth digit of the number
int GetDigit(int number, int k)
{
    if(k < toString(number).length())
        return toString(number)[toString(number).length()-k-1]-'0';
    else
        return 0;   
}

//creates and returns the intermediate array of 10 queues
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
    vector<queue<int> > V(10);
    for(int i=0; i < L.size(); i++)
        V[GetDigit(L[i],k)].push(L[i]);
    return V; 
}

//convert array of queues to array
vector<int> QueuesToArray(vector<queue<int> > & QA, int numVals)
{
    vector<int> s(numVals);
    int k = 0;
    for(int i=0; i < QA.size(); i++)
    {
        int size = QA[i].size();
        for(int j=0; j < size; j++)
        {
            s[k] = QA[i].front();
            QA[i].pop();  
            k++;
        } 
    }
    return s;
}

void RadixSort(vector<int> & L, int numDigits)
{
    vector<queue<int> > QA(10);
    for(int k=0; k<numDigits; k++)
    {
        QA = ItemsToQueues(L,k);
        L = QueuesToArray(QA, L.size());
    }
}

void PrintVector(const vector<int> & L)
{
    for(int i=0; i<L.size(); i++)
        cout<<L[i]<<" ";
    cout<<endl;
}

string toString(int & a)
{
    string s;
    stringstream ss;
    ss << a;
    return s=ss.str();
}
