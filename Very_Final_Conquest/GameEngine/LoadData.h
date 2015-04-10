#ifndef LOADDATA_H
#define LOADDATA_H
#include <string>
#include <vector>

#include "Continent.h"

using namespace std;

class LoadData 
{
private:
	string mapFile;
//	int countryIndex; //stores the index of the last accessed object in the vector.
	vector<Continent>* allContinents; //Stores all the continents in the map.
	vector<Country*>* allCountries; //Stores all the countries in the map
	
	void print();
	vector<Country*>* LoadMap(string mapFile);
	//void SplitString(string stringInput);
	void StoreContinent(string line);
	void StoreCountries(string line);
	
	int ConvertToInt(string strLine);
	int getIndexOfCountry(string name);
	int getIndexOfContinent(string name);
	bool CountryExists(string name);
	bool CountryExistsInTheContinent(int continentIndex,string countryName);
	

public:
	LoadData(); // Default constructor
	LoadData(string mFile); // Parametrized constructor

	vector<Continent>* getAllContients();
	vector<Country*>* getAllCountries();

};
#endif