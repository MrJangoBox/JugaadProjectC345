#include "LoadData.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Default constructor declaration
LoadData::LoadData() : mapFile()
{
}

// Parameterized constructor decalration
LoadData::LoadData(string mFile) : mapFile(mFile)
{
	cout << "A File is Loaded";
	loadMap(mapFile);
}

void LoadData::loadMap(string mapFile)
{
    string STRING;
    ifstream infile;
    infile.open (mapFile);
    int a=0;
    string previousLine="";
    while(!infile.eof( )) // To get you all the lines.
    {
        getline(infile,STRING); // Saves the line in STRING.
        if (STRING != previousLine)
        {
            previousLine=STRING;
            cout<<STRING<<endl; // Prints our STRING.
        }
    }
    infile.close();
}