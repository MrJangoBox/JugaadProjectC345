#include "Continent.h"
#include "Graph.h"
#include "Node.h"

#include <vector>

using namespace std;

Continent::Continent(string name, int code, vector <Node>* countryVector, int armyPopulation) 
{
	this->name = name;
	this->code = code;
	this->country = countryVector;
	this-> armyPopulation = armyPopulation;
};

void addCountryToContinent(vector <Node>* countryVector)
{
	for(int i=0; countryVector->size(); i++)  //need vector of all countries from Cheng (don't use countryVector from this class)
	{
		if(countryVector->at(i).code == 1)
			countryVector->push_back(countries->at(i));   //error cuz I don't have Cheng's vector name
	}

};



/*Continent::~Continent() 
{
	//continent destructor method
}*/



