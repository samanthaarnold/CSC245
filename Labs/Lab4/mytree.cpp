#include <iostream>
#include "bst.h"
using namespace std;

void checkHeight(BinarySearchTree<int> &t);
void checkBalance(BinarySearchTree<int> &t);
void printNumLeaves(BinarySearchTree<int> &t);

int main()
{
	BinarySearchTree<int> t(0);
	
	t.insert(6);
	t.insert(2);
	t.insert(1);
	t.insert(4);
	t.insert(3);
	t.insert(8);

	//t.printTree();
	//t.postOrder();
	//checkHeight(t);	
	//checkBalance(t);
	
	t.insert(9);
	t.postOrder();
	checkHeight(t);
	checkBalance(t);
	printNumLeaves(t);	

	return 0;

}


//t.Height() calls height from bts.cpp and  sends message when root is empty
void checkHeight(BinarySearchTree<int> &t) 
{
	if( t.isEmpty()  )
		cout << "Empty tree" << endl;
	else
		cout<<"Height : "<< t.height() << endl;

}

//print  t.isBalanced() 
void checkBalance(BinarySearchTree<int> &t)
{
	if( t.isBalanced() )
		cout << "It's Balanced!" << endl;
	else
		cout << "It's Not Balanced!" <<endl;
}

void printNumLeaves(BinarySearchTree<int> &t)
{
	if( t.isEmpty() )
		cout << "Empty tree" << endl;
	else
		cout <<"Number of Leaves : " << t.numLeaves() << endl;

}
