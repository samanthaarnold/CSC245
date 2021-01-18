#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"huffman.h"

using namespace std;

void closeFiles(string unzipFile, ofstream & zipfile);
void openFile(char **argv, HuffmanTree & h, int Letters[]);
void readFiles(string unzipFile, ofstream & zipfile, HuffmanTree & h, int Letters[]);
void CountLetters (int Letters[], string unzipFile, HuffmanTree & h);
void buildHuffman(int Letters[], HuffmanTree & h);
void zipFile(string unzipFile, ofstream & zipfile, HuffmanTree & h, int Letters[]);
void compressionRatio(int Letters[], HuffmanTree & h);

int main(int argc, char **argv)
{   
    HuffmanTree h;
    const int NumLetters = 256;
    int Letters[NumLetters]; 
    
    if(argc<=3)
        openFile(argv, h, Letters);
    else if(argc==1)
        cout<<"Please enter the correct amount of arguments."<<endl;
    else
        cout<<"Please enter the correct amount of arguments."<<endl;

    return 0;
}

void openFile(char **argv, HuffmanTree & h, int Letters[])
{
    ifstream unzipfile;
    ofstream zipfile;
    string unzipFile;
    string argv1 = argv[1];

    //--t, prints encoding table and zips file
    if(argv1 == "--t")
    {   
        string argv2 = argv[2];
        readFiles(argv2, zipfile, h, Letters); 
        h.PrintTable();
        closeFiles(unzipFile, zipfile);
        
    }
    //--help
    else if(argv1 == "--help")
    {
        cout<<endl;
        cout<<"If you would like to zip a file, type ./a.out filename"<<endl;
        cout<<"If you would like to be shown the encoding table of a zip file, type ./a.out --t filename"<<endl;
        cout<<endl;
    }
    //zip files and print compression formula
    else
    {
        readFiles(argv1, zipfile, h, Letters); 
        closeFiles(unzipFile, zipfile);
    }
}

//makes sure unzipfile is open 
void readFiles(string unzipFile, ofstream & zipfile, HuffmanTree & h, int Letters[])
{
    ifstream unzipfile;
    unzipfile.open(unzipFile.c_str());
    zipfile.open((unzipFile+".zip").c_str()); 

    if(unzipfile.is_open())
    {
        CountLetters(Letters, unzipFile, h);
     
        buildHuffman(Letters, h);
       
        zipFile(unzipFile, zipfile, h, Letters);
        compressionRatio(Letters, h);
    }  
    else
        cout<<"File not open"<<endl;
}

//building the huffman tree
void buildHuffman(int Letters[], HuffmanTree & h)
{
    //Letters[i]= frequency or weight 
    for(int i=0; i<126; i++)
    {
        if(Letters[i]!=0)
            h.insert((char)i,Letters[i]);
    }
    h.build();
}

//compressing file and printing in zipfile
void zipFile(string unzipFile, ofstream & zipfile, HuffmanTree & h, int Letters[])
{
    ifstream unzipfile;
    unzipfile.open(unzipFile.c_str());
    
    //first line prints number of characters
    zipfile<<h.numNodes()<<endl;

    //printing ASCII value and code
    for(int i=0; i<126; i++)
    {
        if(Letters[i]!=0)
            zipfile<<i<<" "<<h.GetCode((char)i)<<endl;  
    }
    
    //printing compressed data in binary
    char ch;
    while(unzipfile)
	{
        unzipfile.get(ch);
        zipfile<<h.GetCode(ch);
	}
}

//printing compression ratio
void compressionRatio(int Letters[], HuffmanTree & h)
{
    int zipSum=0;
    int unzipSum=0;
    for(int i=0; i<126; i++)
    {
        if(Letters[i]!=0)
        {
            //frequency (used for both unzip and zip calculation)
            int frequency = Letters[i];
            //length of the compressed code
            int lengthOfCode = h.GetCode((char)i).length();
            //total bits per char
            int numBits = frequency*lengthOfCode;
            zipSum += numBits;
            //chars from source file
            int numSorceFile = frequency*8;
            unzipSum += numSorceFile;
        }
    }
    //compression ratio
    float ratio = (1-(float)zipSum/unzipSum)*100;
    cout<<"File Successfully Compressed To "<<zipSum<<" Bits (";
    printf("%.2f",ratio);
    cout<<"% Less)."<<endl;
}

void closeFiles(string unzipFile, ofstream & zipfile)
{
   //close files
    ifstream unzipfile;
    zipfile.close();
    unzipfile.close();
}

//From Dr. Digh's letters.cpp
void CountLetters (int Letters[], string unzipFile, HuffmanTree & h)
{
	char ch;
    ifstream unzipfile;
    unzipfile.open(unzipFile.c_str());

	for (char ch = char(0);  ch <= char(126);  ch++)
		Letters[ch] = 0;

	unzipfile.get(ch);
    
    while (unzipfile)
	{
		Letters[ch] += 1;
		unzipfile.get(ch);
	}
} 
