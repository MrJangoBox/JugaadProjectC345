#include <iostream>
#include "Continent.h"
#include "Country.h"
#include <vector>

using namespace std;

//Constructor
Continent:: Continent(string Name, int armyValue)
	: BaseRegion(Name), armyValue(armyValue) 
{
}

string Continent:: getContinentName() {
	return getBaseName();
}

int Continent:: getArmyValue() {
	return armyValue;
}
vector<Country*> Continent::getCCountries(){
	return cCountries;
}

void Continent::AddContinentCountries(Country* country) {
	cCountries.push_back(country);
}

void Continent::PrintContinent() {
	cout << getBaseName() << " | " ;
	cout << "Continent is worth : " << armyValue << " armies" << endl;
}

void Continent::PrintCountries() {
	for(int i = 0; i < cCountries.size(); i++) {
		cout << "OPTION : " << (i+1) << " | " << cCountries.at(i)->getBaseName() << " | " ;
	}
}