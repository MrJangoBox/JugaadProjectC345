#include <iostream>
#include "Country.h"

using namespace std;

Country:: Country() 
{
	//default constructor
}
Country:: Country(string Name, int NoOfArmiesPlaced)
{
	countryName = Name;
	armiesPlaced = NoOfArmiesPlaced;
}

string Country:: getCountryName()
{
	return countryName;
}

int Country:: getArmiesPlaced()
{
	return armiesPlaced;
}

void Country::PrintCountries() {
	cout << countryName << " | " ;
	cout << "Armies placed here : " << armiesPlaced << endl;

}

void Country::IncrementArmyCount(int Armies) {
	armiesPlaced += Armies;
}

void Country::DecrementArmyCount(int Armies) {
	armiesPlaced -= Armies;
}
