#ifndef CONTINENT_H_
#define CONTINENT_H_

#include "Graph.h"
#include "Country.h"
#include <string>
#include <vector>

using namespace std;

class Country;

class Continent 
{
public:
	Continent();
	Continent::Continent(string name, int code, vector<Country> *countryVector, int armyPopulation);
	//Continent::Continent(string name, int code); //vector <Node> *countryVector //int armyPopulation
	void addCountryToContinent(vector<Country>* countryVector);
	//virtual ~Continent();

	void setName(int n)
	{
		name = n;
	};
	
	void setCode(int co)
	{ 
		code = co;
	};

	int getCode()
	{ 
		return code;
	};

	// Public variables
	vector<Country>* countries;

private:
	string name;
	int code;
	int armyPopulation; //fixed army pop
};

#endif CONTINENT_H_ 
