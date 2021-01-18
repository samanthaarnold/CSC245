#include<iostream>
#include "bet.h"
#include<string>
#include<stack>

using namespace std;

void PrintMenu();
void PrintExit(char &a);
BET BuildTreePrefix();
BET BuildTreePostfix();
BET ConvertInfixToPostfix();
void PrintTree(BET b);
int operatorPrec(char m);

int main()
{
    BET b;
    string expression;
    int sel;
    char stop;
    do
    {
        PrintMenu();
        cin>>sel;
        switch (sel)
        {
        case 1:
            //build tree type Prefix
           PrintTree(BuildTreePrefix());
            break;
        case 2:
            //build tree type Infix
            PrintTree(ConvertInfixToPostfix());
            break;

        case 3:
            //build tree type Postfix
            PrintTree(BuildTreePostfix());
            break;

        default:
            cout<<"Error. Try Again."<<endl;
            break;
        }

        PrintExit(stop);

    } while (toupper(stop) != 'N');
    
    return 0;   
}

void PrintMenu()
{
    cout<<"&&&&&&&&&&& BUILDING BINARY EPRESSION TREES &&&&&&&&&&&"<<  endl;
    cout<<"\t (1) Prefix \t (2) Infix \t (3) Postfix"<<endl;
    cout<<endl;
    cout<<"Your Expression Type ==>  ";
}

void PrintExit(char & stop)
{
    cout<<"Build Another Tree? (Y/N) ";
    cin>>stop;
    if(toupper(stop)== 'N')
        cout<<"Program Now Deconstructing Tree & Exiting... "<<endl;
    cout<<endl;
}

BET BuildTreePrefix()
{
    BET b;
    cout<<endl;
    string e;
    cout<<"Your Expression ==>  ";
    cin.ignore();
    getline(cin, e);
    cout<<endl;

    char c;
    for (int i = e.length()-1; i>=0; i--)
    {
        c=e[i];
        if(c==' ') { }
        else if(c=='+')
            b.insertPrefixOperator(c);
        else if (c=='-')
            b.insertPrefixOperator(c);
        else if (c=='*')
            b.insertPrefixOperator(c);
        else if (c=='/')
            b.insertPrefixOperator(c);
        else
            b.insertOperand(c);
    }
    return b;
}

BET BuildTreePostfix()
{
    BET b;
    cout<<endl;
    string e;
    cout<<"Your Expression ==>  ";
    cin.ignore();
    getline(cin, e);
    cout<<endl;

    char c;
    for (int  i = 0; i< e.length(); i++)
    {
        c=e[i];
        if(c==' ') { }
        else if(c=='+')
            b.insertPostfixOperator(c);
        else if (c=='-')
            b.insertPostfixOperator(c);
        else if (c=='*')
            b.insertPostfixOperator(c);
        else if (c=='/')
            b.insertPostfixOperator(c);
        else
            b.insertOperand(c);
    }
    return b;
}

BET ConvertInfixToPostfix()
{
    BET b;
    cout<<endl;
    string e;
    cout<<"Your Expression ==>  ";
    cin.ignore();
    getline(cin, e);
    cout<<endl;

    string postfix;
    stack<char>infix;
    char c;
    e+=')';
    e='('+ e;
    infix.push(e[0]);
    for(int i=1; i<e.length(); i++)
    {
        c=e[i];
        if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
        {
            char k = infix.top(); 
            if(c=='(')
            {
                infix.push(c);
            }
            else if(c==')')
            {
                while(infix.top()!='(')
                {
                    postfix = postfix+infix.top();
                    infix.pop();
                }
                infix.pop();
            }
            else if (operatorPrec(c)<=operatorPrec(k))
            {
                while (operatorPrec(c)<=operatorPrec(k))
                {
                    infix.pop();
                    postfix = postfix+k;
                    k = infix.top();
                }
                infix.push(c);
            }
            else
            {
                 infix.push(c);
            } 
        }  
        else if(c==' ') { }
        else 
            postfix = postfix+c;
    }
    
    char g;
    for (int  x = 0; x< postfix.length(); x++)
    {
        g=postfix[x];
        if(g==' ') { }
        else if(g=='+')
            b.insertPostfixOperator(g);
        else if (g=='-')
            b.insertPostfixOperator(g);
        else if (g=='*')
            b.insertPostfixOperator(g);
        else if (g=='/')
            b.insertPostfixOperator(g);
        else
            b.insertOperand(g);
    }
    return b;
}

int operatorPrec(char m)  
{  
    if(m ==')')
        return (5);
    else if ( m=='*'||m=='/'  )
        return (2);
    else if(m=='+'||m=='-' ) 
        return (1);
    else
        return (0); 
}

void PrintTree(BET b)
{
    cout<<endl;
    cout<<"Prefix Expression Produced From Tree : "<<endl;
    b.preorder();
    cout<<endl;
    cout<<"Infix Expression Produced From Tree : "<<endl;
    b.inorder();
    cout<<endl;
    cout<<"Postfix Expression Produced From Tree : "<<endl;
    b.postorder();
    cout<<endl;
    cout<<endl;
}
