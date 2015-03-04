#include <iostream>
#include "Country.h"

using namespace std;

//Constructor
Country:: Country(string Name, int NoOfArmiesPlaced) {
	countryName = Name;
	armiesPlaced = NoOfArmiesPlaced; //Number of armies placed in the country.
}

string Country:: getCountryName() {
	return countryName;
}

int Country:: getArmiesPlaced() {
	return armiesPlaced;
}

void Country::PrintCountries() {
	cout << countryName << " | " ;
	cout << "Armies placed here : " << armiesPlaced << endl;
}

//Increments the number of armies placed in the country.
void Country::IncrementArmyCount(int Armies) {
	armiesPlaced += Armies;
}

//Decrements the number of armies placed in the country.
void Country::DecrementArmyCount(int Armies) {
	armiesPlaced -= Armies;
}
