#include <iostream>
#include "Country.h"
#include <vector>

using namespace std;

//Constructor
Country:: Country(string Name, int NoOfArmiesPlaced) {
	countryName = Name;
	armiesPlaced = NoOfArmiesPlaced; //Number of armies placed in the country.
	vector<Country*> cNeighbours;
}

string Country:: getCountryName() {
	return countryName;
}

int Country:: getArmiesPlaced() {
	return armiesPlaced;
}
vector<Country*> Country::getCNeighbours(){
	return cNeighbours;
}

void Country::SetNeighbours(vector<Country*> neighbours) {
	cNeighbours = neighbours;
}

void Country::PrintCountry() {
	cout << countryName << " | " ;
	cout << "Armies placed here : " << armiesPlaced << endl;
}

void Country::PrintNeighbours() {
	for(int i = 0; i < cNeighbours.size(); i++) {
		cout << "OPTION : " << (i+1) << " | " << cNeighbours.at(i)->getCountryName() << " | " ;
		cout << "Armies placed here : " << armiesPlaced << endl;
	}
}

//Increments the number of armies placed in the country.
void Country::IncrementArmyCount(int Armies) {
	armiesPlaced += Armies;
}

//Decrements the number of armies placed in the country.
void Country::DecrementArmyCount(int Armies) {
	armiesPlaced -= Armies;
}
