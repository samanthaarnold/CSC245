#include "graph.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<climits>
#include <iomanip>

using namespace std;

vector<string> BuildGraph(Graph<string> & myGraph, string fileName, vector<string> & cities, vector<bool> & mark);
void DijkstrasAlg(const Graph<string> & myGraph, vector<string> & cities, vector<string> & city, 
    vector<bool> & mark, vector<int> & dist, vector<string> & prev);
void PrintMyGraph(const Queue<string> & myQ);
int getIndex(string vertex, vector<string> & cities, vector<string> & city);
void PrintSummaryTable(Graph<string> & myGraph, const vector<string> & cities);
void printRow(int index, vector<string> & city, vector<int> & dist, vector<string> & prev);
void printCities(const vector<string> & cities);
string startingVertex(vector<string> & cities, vector<string> & city);
void printSum();
void printArrays(int currentSize, vector<string> & city, 
    vector<bool> & mark, vector<int> & dist, vector<string> & prev);

int main(int argc, char **argv)
{
    Graph<string> myGraph(50);
    Queue<string> myQ(50);
    
    vector<string> cities;
    
    vector<string> city;
    vector<bool> mark;
    vector<int> dist;
    vector<string> prev;

    ifstream file;
    string fileName = argv[1];
    file.open(fileName.c_str());   

    if(file.is_open())
    {
        BuildGraph(myGraph, fileName, cities, mark);
        printCities(cities);
        DijkstrasAlg(myGraph, cities, city, mark, dist, prev);
    }
    else
        cout<<"File not open"<<endl;
    
    file.close();
    
    return 0;
}

//opens file, builds the graph, and returns the number of vertices
vector<string> BuildGraph(Graph<string> & myGraph, string fileName, vector<string> & cities, vector<bool> & mark)
{
    ifstream file;
    file.open(fileName.c_str());
    
    string vertice1="";
    string vertice2 =""; 
    string weight="";
    int distance;

    while(file)
    {
        getline(file, vertice1, ';');
        //cout<<"vertice 1: "<<vertice1<<endl;
        getline(file, vertice2, ';');
        //cout<<"vertice 2: "<<vertice2<<endl;
        getline(file, weight, '\n'); //stops at the end of the line
        //cout<<"distance: "<<weight<<endl;

        if( (find(cities.begin(), cities.end(), vertice1)) == cities.end() && vertice1 !="")
        {
            myGraph.AddVertex(vertice1);
            cities.push_back(vertice1);
        }
        
        if( (find(cities.begin(), cities.end(), vertice2)) == cities.end() && vertice2 !="") 
        {
            myGraph.AddVertex(vertice2);
            cities.push_back(vertice2);
        }

        if(vertice1 != "")
        {
            distance = atoi(weight.c_str());
            myGraph.AddEdge(vertice1, vertice2, distance);
        }
    }

    //prints cities added
    //for(int i=0; i<cities.size(); i++)
   // {
     //  cout<<cities[i]<<endl;
   // }
    return cities;
}

//prints what is conncected to a given vertice
void PrintMyGraph(const Queue<string> & myQ)
{
    Queue<string> TempQ = myQ;

    while(! TempQ.isEmpty())
    {
        cout<<TempQ.getFront() <<endl;
        TempQ.dequeue();
    }
}

//determines whether a string entered is valid index
string startingVertex(vector<string> & cities, vector<string> & city)
{
    string start; 
    cout<<"Please input your starting vertex: ";
    while(!(cin >> start) || find(cities.begin(), cities.end(), start) == cities.end() )
    {
        cin.clear();
        cout<<"Please enter a valid starting location. "<<endl;
        cout<<"Please input your starting vertex: ";
    }
    return start;
}

//prints begining of the summary table
void printSum()
{
    cout<<"----------------------------------------------------------------------------------"<<endl;
    cout << setw(20) << "Vertex" << setw(18) << "Distance" << setw(20) << "Previous" << endl;
    cout<<endl;
}

//prints four arrays
void printArrays(int currentSize, vector<string> & city, vector<bool> & mark, vector<int> & dist, vector<string> & prev)
{
    for(int i=0; i<currentSize; i++)
   {
       cout<<"\t"<<city[i]<<"\t"<<mark[i]<<"\t"<<dist[i]<<"\t"<<prev[i]<<endl;
    }    
}

void DijkstrasAlg(const Graph<string> & myGraph, vector<string> & cities, vector<string> & city, 
vector<bool> & mark, vector<int> & dist, vector<string> & prev)
{
    //sets starting point
    city.push_back(startingVertex(cities,city));
    printSum();
    mark.push_back(true);
    dist.push_back(0);
    prev.push_back("N/A");

    Queue<string> tempQ;
    
    printRow(0,city,dist,prev);
    
    int cityDist;
    string name;
    int minIndex;
    
    for(int index=0; index < cities.size()-1; index++)
    {
        //adds vertices to temparay queue
        myGraph.GetToVertices(city[index],tempQ);
        //PrintMyGraph(tempQ);
    
        while(!tempQ.isEmpty())
        {
            name = tempQ.getFront();
            //vertex has already been added to vector
            if(find(city.begin(), city.end(), name) != city.end())
            {
                //removes point if it has already been visited
                tempQ.dequeue();
            }
            else
            {
                cityDist = myGraph.WeightIs(city[index],name)+dist[index];
                city.push_back(name);
                dist.push_back(cityDist);
                prev.push_back(city[index]);
                tempQ.dequeue();
            }     
        }
        //sets min distance
        int min = INT_MAX;
        for(int i=0;i<city.size();i++)
        {
            if(dist[i]<=min && mark[i] == false)
            {
                min=dist[i];
                minIndex=i;
            }
        }
        mark[minIndex]=true;
        printRow(minIndex,city,dist,prev);

        //check to see what has been added to the arrays
        //int currentSize = city.size();
        //printArrays(currentSize, city, mark, dist, prev);
    } 
}

//finds the index of a city in cities
int getIndex(string vertex, vector<string> & cities, vector<string> & city)
{
    int i = 0;
    while (i<cities.size())
    {
        if(city[i] != vertex)
          i++;
        else
            return -1;
    }
    return i;
}

//prints a given row in summary table
void printRow(int index, vector<string> & city, vector<int> & dist, vector<string> & prev)
{
	cout << setw(20) << city[index] << setw(20) << dist[index] << setw(20) << prev[index] << endl;
}

//prints cities
void printCities(const vector<string> & cities)
{
    vector<string> tempCities = cities;
    sort(tempCities.begin(), tempCities.end()); 
    int numVertices = tempCities.size();

    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^ DIJKSTRA'S ALGORITHM ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<endl;
    cout<<"A Weighted Graph Has Been Built for These "<<numVertices<<" Cities : "<<endl;
    cout<<endl;
    //print cities 3 per line
    for(int i=0; i<tempCities.size(); i++)
        cout << "\t"<< tempCities[i] << ((i%3 == 2) ? "\n" : "\t\t"); 
    cout<<endl;
    cout<<endl;
    
}
