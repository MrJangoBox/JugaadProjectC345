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
	vector<Country*> cNeighbours;

public:
	void SetNeighbours(vector<Country*> neighbours);
	Country(string Name, int NoOfArmiesPlaced);
	string getCountryName();
	int getArmiesPlaced();
	vector<Country*> getCNeighbours();
	void PrintCountry();
	void IncrementArmyCount(int Armies);
	void DecrementArmyCount(int Armies);
	void PrintNeighbours();

};
#endif