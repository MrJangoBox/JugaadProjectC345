#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "LoadData.h"
#include "Continent.h"

using namespace std;

// Default constructor declaration
LoadData::LoadData() : mapFile()
{
}

// Parameterized constructor decalration
LoadData::LoadData(string mFile) : mapFile(mFile)
{
	cout << "A File is Loaded" << endl;
	allContinents = new vector <Continent>;
	allCountries = new vector <Country>;
	LoadMap(mapFile);
}

int LoadData:: ConvertToInt(string strLine)
{
	int i;
	stringstream ss(strLine);

	if((ss >> i).fail())
	{
		return -999; // We should probably add proper exceptions.
	}
	return i;
}

int LoadData::getIndexOfContinent(string name)
{
	for(int i = 0; i < allContinents->size(); i++) 
	{
		if(allContinents->at(i).getContinentName() == name)
			return i;
	}
	return 999; // need proper exceptions.
}

int LoadData::getIndexOfCountry(string name) 
{
		for(int i = 0; i < allCountries->size(); i++) 
	{
		if(allCountries->at(i).getCountryName() == name)
			return i;
	}
	return 999; // need proper exceptions.
}

bool LoadData::CountryExists(string name)
{
	for (int i = 0; i < allCountries->size(); i++)
	{
		if(allCountries->at(i).getCountryName() == name)
			return true;
	}
	return false;
}

bool LoadData::CountryExistsInTheContinent(int continentIndex, string countryName)
{
		if(allContinents->at(continentIndex).CountryExists(countryName) == true)
			return true;
		return false;
}

void LoadData:: StoreContinent(string line) 
{
	string token;
	string delimeter = "=";
	size_t pos = 0;

	while ((pos = line.find(delimeter)) != string::npos)
	{
		token = line.substr(0, pos);
		line.erase(0, pos + delimeter.length());
	}
	if(line != "[Territories]" && line != "[Continents]" && line != "") {  
		Continent continent = Continent::Continent(token, ConvertToInt(line));
		allContinents->push_back(continent);
	}
}

void LoadData:: StoreCountries(string line) 
{
	vector<string> tokens;
	string delimeter = ",";

	size_t endPos = 0;
	string token;
	while (endPos != string::npos)
	{
		endPos = line.find(delimeter);
		token = line.substr(0, endPos);
		tokens.push_back(token);
		line = line.substr(endPos+delimeter.length(), string::npos);
	}
	
	Country country;
	int continentIndex = getIndexOfContinent(tokens[3]);
	for (int i = 0; i < tokens.size(); i++)
	{
		if(i == 0 && !CountryExists(tokens[0]))
		{
			country = Country::Country(tokens[0], 0, tokens.at(3));
			allCountries->push_back(country);

			if(!CountryExistsInTheContinent(continentIndex,tokens[0]))
				allContinents->at(continentIndex).AddContinentCountries(&country);
			
		}
	
		//CountryExists returns true, 
		//countryIndex = index of the last accessed object (which is the equal object)
		else if ( i == 0 && CountryExists(tokens[0]))
		{
			int countryIndex = getIndexOfCountry(tokens[0]);
			allCountries->at(countryIndex).setCountryContinentName(tokens[3]);

		//	if(!CountryExistsInTheContinent(continentIndex,tokens[0]))
			//	Country *countryPtr = &(allCountries->at(countryIndex));
				allContinents->at(continentIndex).AddContinentCountries(&(allCountries->at(countryIndex)));
		}

		else if(i > 3 && !CountryExists(tokens[i]))
		{
			Country neighbourCountry = Country::Country(tokens.at(i), 0, " ");
			allCountries->push_back(neighbourCountry);
			country.AddNeighbour(&neighbourCountry);
			neighbourCountry.AddNeighbour(&country);
		}
	}
}
void LoadData::print()
{
	for(int i = 0; i < allContinents->size() ; i++) {
		allContinents->at(i).PrintContinent();
		cout << allContinents->at(i).getContinentName() << " ";
		cout << allContinents->at(i).getArmyValue() <<endl;
	}
}
void LoadData::LoadMap(string mapFile)
{
	string nextLine;
	string previousLine = " ";

	ifstream inputfile;
	inputfile.open (mapFile);

	while(!inputfile.eof( )) //Read the file till it reached the end.
	{
		getline(inputfile,nextLine); // Retrieves and stores the next line in the file.
		if (nextLine != previousLine)
		{
			previousLine = nextLine;
			if(previousLine == "[Continents]")
			{
				while(previousLine != "[Territories]") // Retrieve all the continents.
				{
					previousLine = nextLine;
					StoreContinent(previousLine);
					getline(inputfile, nextLine); // Saves the line in STRING.
				}
				//Store the countries.
				while(!inputfile.eof( )) // Retrieves all the territories.
				{
					previousLine =  nextLine;
					StoreCountries(previousLine);
					getline(inputfile, nextLine); // Saves the line in STRING.
				} 
			}
		}
	}
	inputfile.close();
	print();
}