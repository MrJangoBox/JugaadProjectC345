#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>

using namespace std;

class Country 
{
private:
	string countryName;
	int armiesPlaced;

public:
	Country(string Name, int NoOfArmiesPlaced);
	string getCountryName();
	int getArmiesPlaced();	
	void PrintCountries();
	void IncrementArmyCount(int Armies);
	void DecrementArmyCount(int Armies);

};
#endif