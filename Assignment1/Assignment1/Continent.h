#ifndef CONTINENT_H_
#define CONTINENT_H_

#include "Graph.h"

#include <string>
#include <vector>

using namespace std;

class Node;

class Continent 
{
public:
	Continent();
	Continent::Continent(string name, int code, vector <Node> *countryVector, int armyPopulation);
	//Continent::Continent(string name, int code); //vector <Node> *countryVector //int armyPopulation
	void addCountryToContinent(vector <Node>* countryVector);
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

private:
	string name;
	int code;
	vector <Node> * country;
	int armyPopulation; //fixed army pop
};

#endif CONTINENT_H_ 
