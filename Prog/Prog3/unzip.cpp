#include<iostream>
#include<map>
#include<string>
#include<fstream>

using namespace std;

void openFile(char **argv);
void readFile(ifstream & zipfile, ofstream & unzipfile);
void closeFiles(ifstream & zipfile, ofstream & unzipfile);

int main(int argc, char **argv)
{
    if(argc==2)
    {
        //converts c-string to string
        string argv1 = argv[1];
        
        //checks to make sure end is zip
        if(argv1.substr(argv1.length()-4,4) !=".zip")
            cout<<"File is not .zip file"<<endl;
        else
            openFile(argv);    
    }
    return 0;
}

void openFile(char **argv)
{
    ifstream zipfile;
    ofstream unzipfile;

    string argv1 = argv[1];
            
    zipfile.open(argv[1]); 
    unzipfile.open(argv1.substr(0,argv1.length()-4).c_str());

    readFile(zipfile, unzipfile);

    closeFiles(zipfile, unzipfile);
}

void readFile(ifstream & zipfile, ofstream & unzipfile)
{
    map<string,int> map;
    //makes sure file is open 
    if(zipfile.is_open())
    {
        //first line in sample (number of unique characters)
        int numChars;
        zipfile>>numChars;
                
        //ASCII value of character
        int characters;
        //characters compressed string
        string key;

        //reading in characters and key, storing in map
        for(int i=0; i<numChars; i++)
        {
            zipfile>>characters;
            zipfile>>key;
            map[key]=characters;
        }

        //last line in sample (compressed data in binary)
        string input;
        zipfile>>input;
        
        string token=""; //initializing key

        //comparing elements in map to compressed data in binary
        //and sending to unzipfile
        for(int i=0; i<input.length(); i++)
        {
            token+=input[i];
            if(map.find(token)!= map.end())
            {
                unzipfile<<(char)map[token]; 
                token="";
            }
        }   
    }
}

void closeFiles(ifstream & zipfile, ofstream & unzipfile)
{
   //close files
    zipfile.close();
    unzipfile.close();
    cout<<"File Successfully Inflated Back to Original"<<endl;
}