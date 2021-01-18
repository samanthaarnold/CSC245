#include <queue>
#include <vector>
#include <iostream>
#include<string>

using namespace std;

int maxElemLength(const vector<string>& v);
char GetString(string word, int k);
vector<queue<string> > ItemsToQueues(const vector<string>& L, int k);
vector<string> QueuesToArray(vector<queue<string> > & QA, int numVals);
void RadixSort(vector<string> & L, int numDigits);
void PrintVector(const vector<string> & L);
void addPadding(vector<string> & L);

int main(int argc, char *argv[])
{
   
    string a[]= {"zebra", "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};    
   
    vector<string> L (a, a+10); // the list to be sorted
    vector<queue<string> > QA(128); // vector of quees indexed 0-9
    
    addPadding(L);
    RadixSort(L,maxElemLength(L));
    PrintVector(L);
   
	return 0;
}

//returns the number of digits of the largest integer within vector v
int maxElemLength(const vector<string>& v)
{
    int t=0;
    for(int k=0; k<v.size();k++)
    {
        if(v[t].length()<v[k].length())           
            t=k;
    }
    return v[t].length();
}

//returns the last char or the word
char GetString(string word, int k)
{
    return word[word.length()-k-1];
}

//creates and returns the intermediate array of 10 queues
vector<queue<string> > ItemsToQueues(const vector<string>& L, int k)
{
    vector<queue<string> > V(128);
    for(int i=0; i < L.size(); i++)
        V[GetString(L[i],k)].push(L[i]);
    return V; 
}

//convert array of queues to array
vector<string> QueuesToArray(vector<queue<string> > & QA, int numVals)
{
    vector<string> s(numVals);
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

void RadixSort(vector<string> & L, int numDigits)
{
    vector<queue<string> > QA(128);
    for(int k=0; k<numDigits; k++)
    {
        QA = ItemsToQueues(L,k);
        L = QueuesToArray(QA, L.size());
    }
}

void PrintVector(const vector<string> & L)
{
    for(int i=0; i<L.size(); i++)
        cout<<L[i]<<endl;
}

//adds space to the end of each string to make them the same lenght
void addPadding(vector<string> & L)
{
    for(int i=0; i<L.size(); i++)
    {
        while(L[i].length() != maxElemLength(L))           
            L[i]+=" ";
    }
}

