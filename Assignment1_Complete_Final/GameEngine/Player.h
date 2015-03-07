#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <hash_map>
#include <vector>
#include "Country.h"

using namespace std;

class Player
{
private:
	string playerName;
	int remainingArmies; //Unused armies.
	vector<Country*> *countriesOwned; //Countries owned/conquered by the player.
	

public:
	Player(string Name, int Armies); 
	string getPlayerName();
	vector<Country*>* getCountriesOwned();
	int getRemainingArmies();
	Country* getCountry(int index); //Returns the address of the element at vector[index]
	Country* getNeighbour(int cIndex, int nIndex);

	void IncrementNumberOfArmies(int Armies);
	void DecrementNumberOfArmies(int Armies);
	void AddCountry(Country *country); //Add country to the list of countries owned.
	void PrintPlayerStats(); //Display
	void PrintCountriesAndNeighbours();
};

#endif





