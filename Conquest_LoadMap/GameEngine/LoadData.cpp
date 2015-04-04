 #include "LoadData.h"
#include "Continent.h"

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

void StoreContinent(string line) 
{
	string delimeter = "=";

	size_t pos = 0;
	string token;
	while ((pos = line.find(delimeter)) != string::npos)
	{
		token = line.substr(0, pos);
		//cout << token << endl;
		line.erase(0, pos + delimeter.length());
	}
	if(line != "[Territories]" && line != "[Continents]" && line != "") {  
		//cout << line << endl;
		Continent continent = Continent::Continent(token, stoi(line));
	}
}

void StoreCountries(string line) 
{
	vector<string> tokens;
	string delimeter = ",";

	size_t endPos = 0;
	//size_t startPos = 0;
	string token;
	while (endPos != string::npos)
	{
		endPos = line.find(delimeter);
		token = line.substr(0, endPos);
		tokens.push_back(token);
		line = line.substr(endPos+delimeter.length(), string::npos);
		cout << line << endl;
	}
	//if(line != "[Territories]" && line != "[Continents]" && line != "") {  
	//	//cout << line << endl;
	//	Continent continent = Continent::Continent(token, stoi(line));
	//}
	for (int i = 0; i < tokens.size(); i++)
	{
		if(i = 0)
		{
			Country country = Country::Country(tokens[i],0,tokens[3]);
			country.PrintCountry();
		}
	}
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
            if(previousLine == "[Continents]")
			{
				while(previousLine != "[Territories]") // To get you all the lines.
				{
					previousLine=STRING;
					StoreContinent(previousLine);
					getline(infile,STRING); // Saves the line in STRING.
				}
				
				while(!infile.eof( )) // To get you all the lines.
				{
					previousLine=STRING;
					StoreCountries(previousLine);
					getline(infile,STRING); // Saves the line in STRING.
				}
			}
        }
    }
    infile.close();
}