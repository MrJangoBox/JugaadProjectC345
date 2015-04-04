#include <string>
#include <vector>
#include "Country.h"
using namespace std;

class Country;

class LoadData 
{
private:
	// Private methods
	bool CountryExists(string countryName);
	void loadMap(string mapFile);
	void StoreContinent(string line);
	void StoreCountries(string line);
	void updateCountry(string countryName, string continentName);

	// Private vars
	string mapFile;
	vector<Country*> storedCountries;


public:
	// Default constructor
	LoadData();
	// Parametrized constructor
	LoadData(string mFile);
	// Public vars

};