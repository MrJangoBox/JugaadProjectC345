#include <hash_map>
#include <iostream>
#include <vector>
#include <string> 
#include "Player.h"
#include "Country.h"

using namespace std;

//Constructor
Player:: Player(string Name,int Armies) {
	playerName = Name;
	remainingArmies = Armies;
	countriesOwned =  new vector <Country> ; 
}

string Player:: getPlayerName() {
	return playerName;
}

int Player:: getRemainingArmies() {
	return remainingArmies;
}

vector <Country>* Player:: getCountriesOwned() {
	return countriesOwned;
}

Country* Player::getCountry(int index) {
	return &(countriesOwned->at(index));
}

Country* Player::getNeighbour(int cIndex, int nIndex) {
	//vector<Country*> country = getCountry(cIndex)->getCNeighbours();

	Country* coutry = getCountry(cIndex)->getCNeighbours().at(nIndex);
	return getCountry(cIndex)->getCNeighbours().at(nIndex);

}
void Player::IncrementNumberOfArmies(int Armies) {
	remainingArmies += Armies;
}

void Player::DecrementNumberOfArmies(int Armies) {
	remainingArmies -= Armies;
}

void Player::AddCountry(Country country) {
	countriesOwned->push_back(country);
}

//implement remove country function 


void Player::PrintPlayerStats() {
	cout << playerName << " : " << endl;
	cout << "Total number of countries owned : " << countriesOwned->size() << endl;
	cout << "Total number of armies owned : " << remainingArmies <<endl;

	for(int i = 0; i < countriesOwned->size(); i++) {
		cout << "OPTION " << (i+1) << " : ";
		Country country = countriesOwned->at(i);
		country.PrintCountry();
	}
}

void Player::PrintCountriesAndNeighbours() {
	
	for(int i = 0; i < countriesOwned->size(); i++) {
		cout << "OPTION " << (i+1) << " : ";
		countriesOwned->at(i).PrintCountry();
		cout << "\nNeighbours : " << endl;
		countriesOwned->at(i).PrintNeighbours();
		cout << "\n----------------------------------------------- " << endl;
	}

}
