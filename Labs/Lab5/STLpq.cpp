using namespace std;
#include<iostream>
#include<queue>

void print(priority_queue<string> pq);
void addNames(priority_queue<string> & pq);

int main()
{
    priority_queue<string> pq;
    addNames(pq);
    print(pq);

    return 0;
}

void addNames(priority_queue<string> & pq)
{
    pq.push("Jillian");
    pq.push("Lindsey");
    pq.push("Annika");
    pq.push("Josh");
    pq.push("Emma");
    pq.push("Henry");
    pq.push("Bryce");
    pq.push("Noah");
    pq.push("Jake");
    pq.push("Samantha");
}

void print (priority_queue<string> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" "<<endl;
        pq.pop();
    }

}