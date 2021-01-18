using namespace std;
#include "BinaryHeap.h"

void printLSubtree();

int main()
{
    BinaryHeap<char> PQ(50);

    for(int i=0; i<10; i++)
    {
        PQ.insert('A'+i);
    }
    cout<<"Leaves of the Heap: ";
    PQ.printLeaves();
    cout<<endl;

    /*
    PQ.deleteMin();
    cout<<"Printing Left Subtree of the Root of Heap: ";
    PQ.printLtSubtree();
    cout<<endl;
    cout<<"The Height of Heap Is: "<<PQ.Height()<<endl;
    cout<<"The Maximum Value of Heap Is : "<<PQ.findMax()<<endl;
    */

    
    return 0;
}


