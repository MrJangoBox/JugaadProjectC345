#include "Country.h"

#include <iostream>
#include <vector>

using namespace std;

//Default Constructor
Country::Country()
{

}
//Parametrised Constructor
Country:: Country(string Name, int NoOfArmiesPlaced, string continentName)
{
	countryName = Name;
	countryContinentName = continentName;
	armiesPlaced = NoOfArmiesPlaced; //Number of armies placed in the country.
	vector<Country*> cNeighbours;
}

string Country:: getCountryName() {
	return countryName;
}

string Country:: getCountryContinentName() {
	return countryContinentName;
}

int Country:: getArmiesPlaced() {
	return armiesPlaced;
}

void Country:: setArmies(int armies) {
	 armiesPlaced = armies;
}

vector<Country*> Country::getCNeighbours() {
	return cNeighbours;
}

void Country::SetNeighbours(vector<Country*> neighbours) {
	cNeighbours = neighbours;
}

void Country::setCountryContinentName(string name) {
	countryContinentName = name;
}

void Country::PrintCountry() {
	cout << countryName << " belongs to " << countryContinentName ;
	cout << "Armies placed here : " << armiesPlaced << endl;
}

void Country::PrintNeighbours() {
	for(int i = 0; i < cNeighbours.size(); i++) {
		cout << "OPTION : " << (i+1) << " | " << cNeighbours.at(i)->getCountryName() << " | " ;
		cout << "Armies placed here : " << cNeighbours.at(i)->getArmiesPlaced() << endl;
	}
}
void Country::AddNeighbour(Country* country)
{
	cNeighbours.push_back(country);
}

//Increments the number of armies placed in the country.
void Country::IncrementArmyCount(int Armies) {
	armiesPlaced += Armies;
}

//Decrements the number of armies placed in the country.
void Country::DecrementArmyCount(int Armies) {
	armiesPlaced -= Armies;
}
