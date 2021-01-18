#include "huffman.h"
#include <iostream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;
}

//return true if char is in tree
bool HuffmanTree:: inTree(char ch) {
    return (lookUp(ch)!=-1);
}

//public, returns weight of a given character
int HuffmanTree:: GetFrequency(char ch) {
    return GetFrequency(lookUp(ch));
}

//private, returns the weight at given index
int HuffmanTree:: GetFrequency(int i) {
    return nodes[i].weight;
}

//return index of given character in tree
int HuffmanTree:: lookUp(char ch) {
    for(int i=0; i<numNodes(); i++)
    {
        if(nodes[i].ch==ch)
             return i;  
    }
    return -1;        
}

//public, returns compressed code of given character in tree
string HuffmanTree:: GetCode(char ch) {
    return GetCode(lookUp(ch));
}

//private, returns compressed code of character at given index
string HuffmanTree:: GetCode(int i) {
    if(nodes[i].parent==-1)
        return "";
    else
        return(GetCode(nodes[i].parent)+(char)(nodes[i].childType+'0'));
}

//print encoding table
void HuffmanTree:: PrintTable() {
    cout<<endl;
    cout<<"\t ++++ ENCODING TABLE ++++ "<<endl;
    cout<<endl;
    cout<<"Index\tChar\tWeight\tParent\tChildType"<<endl;
    int x=0;
    for(int i=0;  i < numNodes(); i++)
    {
	  if (nodes[i].ch==' ')
	    cout<<i<<"\t sp"<<"\t"<<nodes[i].weight <<"\t"<<nodes[i].parent<<"\t"<<nodes[i].childType<<endl;
	  else if (nodes[i].ch=='\n')
	    cout<<i<<"\t nl"<<"\t"<<nodes[i].weight <<"\t"<<nodes[i].parent<<"\t"<<nodes[i].childType<<endl;
	  else if (nodes[i].ch=='\0')
      {
          x++;
          cout<<i<<"\t T"<<x<<"\t"<<nodes[i].weight <<"\t"<<nodes[i].parent<<"\t"<<nodes[i].childType<<endl;
      }
      else
        cout<<i<<"\t "<<nodes[i].ch<<"\t"<<nodes[i].weight <<"\t"<<nodes[i].parent<<"\t"<<nodes[i].childType<<endl;
    }
    cout<<endl;
}

//returns total number of nodes
int HuffmanTree:: numNodes() {
    return nodes.size();
}

//build huffman tree
void HuffmanTree:: build() {
    int sm1;
    int sm2;
    
    int i=0;
    while(!built)
    {
        sm1=i;
        sm2=0;
        //node without parent
        if(nodes[sm1].parent==-1)
        {
            //combind the nodes
            for(int x=0; x<nodes.size(); x++)
            {
                if((nodes[x].weight < nodes[sm1].weight) && nodes[x].parent==-1)
                    sm1=x; 
            }
            while(sm1==sm2 || nodes[sm2].parent!=-1)
                sm2++;
                
            for(int x=0; x<nodes.size(); x++)
            {
                if((nodes[x].weight < nodes[sm2].weight) && x!=sm1 && nodes[x].parent==-1)
                    sm2=x;    
            }
            HNode parentNode = {'\0', nodes[sm1].weight+nodes[sm2].weight, -1, -1};
            nodes.push_back(parentNode);
            nodes[sm1].parent=nodes.size()-1;
            nodes[sm2].parent=nodes.size()-1;    
            nodes[sm1].childType=0;
            nodes[sm2].childType=1;
        }
        i++;
        built=((2*numChars-1)==numNodes())?true:false;
    }
    
}

