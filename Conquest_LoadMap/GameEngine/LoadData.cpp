#include "LoadData.h"
#include "Continent.h"
#include "Country.h"
#include "BaseRegion.h"
#include <vector>
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
	vector<Country*> storedCountries;
}

bool LoadData::CountryExists(string countryName)
{
	for(int i = 0; i < storedCountries.size(); i++) {cout << storedCountries.at(i) << endl;}
	int size = storedCountries.size();
	for(int i = 0; i < storedCountries.size(); i++)
	{
		cout << countryName + " vs " + storedCountries.at(i)->getCountryName() << endl;
		if(countryName == storedCountries.at(i)->getCountryName())
		{
			return true;
		}
	}
	return false;
}

void LoadData::StoreContinent(string line) 
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

void LoadData::updateCountry(string countryName, string continentName)
{
	for(int i = 0; i < storedCountries.size(); i++)
	{
		if(countryName == storedCountries.at(i)->getCountryName())
		{
			storedCountries[i]->setCountryContinentName(continentName);
		}
	}
}

void LoadData::StoreCountries(string line) 
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
	}

	for(int i = 0; i < tokens.size(); i++) 
	{
		//Country country;
		if(i == 0)
		{
			if(!CountryExists(tokens[i]))
			{
				cout << tokens[0] + " vs " + tokens[3] << endl;
				Country country = Country(tokens[0], 0, tokens[3]);
				Country* countryPointer = &country;
				countryPointer->PrintCountry();
				storedCountries.push_back(countryPointer);
				cout << storedCountries.at(i) << endl;
			} else {
				updateCountry(tokens[0], tokens[3]);
			}
		} else if(i > 3) {
			if(!CountryExists(tokens[i]))
			{
				Country nCountry = Country::Country(tokens[i], 0, " ");
				storedCountries.push_back(&nCountry);
				//country.AddNeighbour(&nCountry);
			}
		}
	}
	//if(line != "[Territories]" && line != "[Continents]" && line != "") {  
	//	//cout << line << endl;
	//	Continent continent = Continent::Continent(token, stoi(line));
	//}
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