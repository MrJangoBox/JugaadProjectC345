#ifndef COUNTRY_H
#define COUNTRY_H
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
	Country();
	Country(string Name, int NoOfArmiesPlaced, string countryContinentName);

	// Public methods
	void SetNeighbours(vector<Country*> neighbours);
	string getCountryName();
	int getArmiesPlaced();
	void setArmies(int armies);
	vector<Country*> getCNeighbours();
	string getCountryContinentName();
	void setCountryContinentName(string name);
	void PrintCountry();
	void IncrementArmyCount(int Armies);
	void DecrementArmyCount(int Armies);
	void PrintNeighbours();
	void AddNeighbour(Country* country);

};
#endif