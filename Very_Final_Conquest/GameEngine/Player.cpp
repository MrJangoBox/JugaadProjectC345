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
	countriesOwned =  new vector <Country*> ;

	if(playerName != "PLAYER 1")
	{
		setTypeOfPlayer();
	} else {
		typeOfPlayer = "Human";
	}
}

// *************************** Added for Assignement 2 - Strategy **********************************

void Player:: setDefinedTypeOfPlayer(string type)
{
	typeOfPlayer = type;
}

void Player:: setTypeOfPlayer()
{
	playerTypeNum = 0;

	// Generates random player type and returns the name
	playerTypeNum = rand() % 3 + 1;

	switch(playerTypeNum) 
	{
		case 1 : typeOfPlayer = "Aggressive";
				 break;
		case 2 : typeOfPlayer = "Defensive";
				 break;
		case 3 : typeOfPlayer = "Random";
				 break;
	}
}

string Player:: getTypeOfPlayer()
{
	return typeOfPlayer;
}

// *************************************************************************************************

string Player:: getPlayerName() {
	return playerName;
}

void Player:: setRemainingArmies(int numOfRArmies)
{
	remainingArmies = numOfRArmies;
}

int Player:: getRemainingArmies() {
	return remainingArmies;
}

vector <Country*>* Player:: getCountriesOwned() {
	return countriesOwned;
}

void Player:: addCountriesOwned(Country* addedCountryPtr)
{
	countriesOwned->push_back(addedCountryPtr);
}

Country* Player::getCountry(int index) {
	return countriesOwned->at(index);
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

void Player::AddCountry(Country *country) {
	countriesOwned->push_back(country);
}

//implement remove country function 


void Player::PrintPlayerStats() {
	cout << "\n\n" << playerName << "   -   Stategy: " << typeOfPlayer << endl;
	cout << "\nTotal number of countries owned : " << countriesOwned->size() << endl;
	cout << "Total number of armies owned : " << remainingArmies <<endl;

	for(int i = 0; i < countriesOwned->size(); i++) {
		cout << "OPTION " << (i+1) << " : ";
		Country *country = countriesOwned->at(i);
		country->PrintCountry();
	}
}

void Player::PrintCountriesAndNeighbours() {
	
	for(int i = 0; i < countriesOwned->size(); i++) {
		cout << "OPTION " << (i+1) << " : ";
		countriesOwned->at(i)->PrintCountry();
		cout << "\nNeighbours : " << endl;
		countriesOwned->at(i)->PrintNeighbours();
		cout << "\n----------------------------------------------- " << endl;
	}

}
