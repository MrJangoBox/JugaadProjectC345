#include <hash_map>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Country.h"

using namespace std;

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

vector <Country> Player:: getCountriesOwned() {
	return *countriesOwned;
}
Country* Player::getCountry(int index) {
	return &countriesOwned->at(index);
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
/*
void Player:: PrintCountries() {
for(int i = 0; i < countriesOwned.size(); i++) {
cout << "\t" << countriesOwned[i].getCountryName() << " | " ;
cout << "Armies placed here : " << countriesOwned[i].getArmiesPlaced() <<endl;
}
}*/

//implement remove country function 


void Player::PrintPlayerStats() {

	cout << playerName << " : " << endl;
	cout << "Total number of countries owned : " << countriesOwned->size() << endl;
	cout << "Total number of armies owned : " << remainingArmies <<endl;

	for(int i = 0; i < countriesOwned->size(); i++) {
		cout << "OPTION " << (i+1) << " : ";
		countriesOwned->at(i).PrintCountries();
	}
}
