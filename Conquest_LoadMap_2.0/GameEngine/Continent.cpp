#include <iostream>
#include "Continent.h"
#include "Country.h"
#include <vector>

using namespace std;

//Constructor
Continent:: Continent(string Name, int armyWorth)
{
	continentName = Name;
	armyValue = armyWorth;
}

string Continent:: getContinentName() {
	return continentName;
}

int Continent:: getArmyValue() {
	return armyValue;
}
vector<Country*> Continent::getCCountries(){
	return cCountries;
}
int Continent::CountryVectorSize() {
	return cCountries.size();
}

bool Continent:: CountryExists(string name) {
	for (int i = 0; i < cCountries.size(); i++)
	{
		if(cCountries[i]->getCountryName() == name)
			return true;
	}
	return false;
}

void Continent::AddContinentCountries(Country* country) {
	cCountries.push_back(country);
}

void Continent::PrintContinent() {
	cout << continentName << " | " ;
	cout << "Continent is worth : " << armyValue << " armies" << endl;
}

void Continent::PrintCountries() {
	for(int i = 0; i < cCountries.size(); i++) {
		cout << "OPTION : " << (i+1) << " | " << cCountries.at(i)->getCountryName() << " | " ;
	}
}