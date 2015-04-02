#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <vector>

using namespace std;

class Country 
{
private:
	string countryName;
	int armiesPlaced;
	vector<Country> *cNeighbours;

public:
	Country(string Name, int NoOfArmiesPlaced);
	string getCountryName();
	int getArmiesPlaced();	
	void PrintCountries();
	void IncrementArmyCount(int Armies);
	void DecrementArmyCount(int Armies);
	void PrintNeighbours();

};
#endif