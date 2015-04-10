#ifndef CONTINENT_H
#define CONTINENT_H
#include "Country.h"
#include <string>
#include <vector>

using namespace std;

class Continent
{
private:
	string continentName;
	int armyValue;
	vector<Country*> cCountries;

public:
	Continent(string Name, int armyWorth); //Parametrised constructor
	string getContinentName();
	int getArmyValue();
	vector<Country*> getCCountries();
	
	bool CountryExists(string name);
	int CountryVectorSize();
	void AddContinentCountries(Country* country);
	void PrintContinent();
	void PrintCountries();
};
#endif