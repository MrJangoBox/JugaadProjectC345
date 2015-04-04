#ifndef COUNTRY_H
#define COUNTRY_H
#include "BaseRegion.h"
#include <string>
#include <vector>

using namespace std;

class Country
{
private:
	// Private vars
	string countryName;
	string countryContinentName;
	int armiesPlaced;
	vector<Country*> cNeighbours;

public:
	// Public Constructor
	Country(string Name, int NoOfArmiesPlaced, string countryContinentName);

	// Default Constructor
	Country();


	// Public methods
	void SetNeighbours(vector<Country*> neighbours);
	string getCountryName();
	int getArmiesPlaced();
	vector<Country*> getCNeighbours();
	string getCountryContinentName();
	void PrintCountry();
	void IncrementArmyCount(int Armies);
	void DecrementArmyCount(int Armies);
	void PrintNeighbours();
	void setCountryContinentName(string continentName);
	void AddNeighbour(Country* country);

};
#endif