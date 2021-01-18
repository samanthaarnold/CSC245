#include "bet.h"
#include<iostream>

using namespace std;

BET::BET()  //Constructor
{
	root=NULL;
}

BET::~BET()  //Destructor
{
	makeEmpty();
}

bool BET::isEmpty() const
{
	return root==NULL;
}

void BET::makeEmpty() //makeEmpty From Public
{
	makeEmpty(root);
}

//makeEmpty From Private
void BET::makeEmpty( BETPtr& t ) const
{	
	if(t!=NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		t=NULL;		
	}
}

void BET::insertPrefixOperator(char token)
{
	BETPtr ptr = new BinaryNode;
	ptr->info.theContent.opsymbol = token;
    ptr->info.whichType = OPERATOR;
    ptr->left = s.top();	s.pop();
    ptr->right = s.top();	s.pop();
    
	s.push(ptr);
    root = s.top();
}

void BET::insertPostfixOperator(char token) 
{
	BETPtr ptr = new BinaryNode;
	ptr->info.theContent.opsymbol = token;
    ptr->info.whichType = OPERATOR;
	ptr->right = s.top();	s.pop();
    ptr->left = s.top();	s.pop();
    
	s.push(ptr);
    root = s.top();
}


void BET::insertOperand(char token)
{
	BETPtr ptr1 = new BinaryNode;
	ptr1->info.theContent.variable = token;
	ptr1->info.whichType = OPERAND;
	ptr1->right = NULL;
	ptr1->left = NULL;
	s.push(ptr1);
}

void BET::preorder() const //preorder From Public
{
	if(isEmpty() )
		cout<<"Tree is empty"<<endl;
	else
		return preorder(root);
}

void BET::preorder( BETPtr t) const //preorder From Private
{
	if( t != NULL)
    {
    	if( (t->info.whichType) == OPERAND)                    
			cout<< t->info.theContent.variable <<" ";
    	else
             cout<< t->info.theContent.opsymbol <<" ";
		preorder(t->left);
    	preorder(t->right);
    }
}


void BET:: inorder() const //inorder from Public
{	
	if(isEmpty() )
		cout<< "Tree is empty"<<endl;
	else
		return inorder(root);
}

void BET::inorder( BETPtr t ) const //inorder from Private
{
	//Post: Function prints inorder traversal for public inorder
	if( t != NULL)
	{
		if( t->left != NULL)
			cout<<"(";
		inorder(t->left);
		if( (t->info.whichType) == OPERAND)
			cout<< t->info.theContent.variable <<" ";
		else
			cout<< t->info.theContent.opsymbol <<" ";
		inorder( t->right );
		if( t->right != NULL)
			cout<<") ";
	}
}

void BET:: postorder() const //postorder from Public
{
	if(isEmpty() )
		cout<<"Tree is empty"<<endl;
	else
		return postorder(root);
}

void BET::postorder( BETPtr t) const //postorder from Private
{
     if( t != NULL)
        {
			postorder(t->left);
			postorder(t->right);
			if( (t->info.whichType) == OPERAND)
				cout<< t->info.theContent.variable <<" ";
            else
                cout<< t->info.theContent.opsymbol <<" ";  
        }
}
  

