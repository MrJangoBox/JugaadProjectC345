#ifndef CONTINENT_H
#define CONTINENT_H
#include "BaseRegion.h"
#include "Country.h"
#include <string>
#include <vector>

using namespace std;

class Continent: public BaseRegion 
{
private:
	string continentName;
	int armyValue;
	vector<Country*> cCountries;

public:
	void AddContinentCountries(Country* country);
	Continent(string Name, int armyValue);
	string getContinentName();
	int getArmyValue();
	vector<Country*> getCCountries();
	void PrintContinent();
	void PrintCountries();
};
#endif