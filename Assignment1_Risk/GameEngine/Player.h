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
	int remainingArmies;
	vector<Country> *countriesOwned;

public:
	Player(string Name, int Armies);

	string getPlayerName();
	vector<Country> getCountriesOwned();
	int getRemainingArmies();
	Country* getCountry(int index);

	void IncrementNumberOfArmies(int Armies);
	void DecrementNumberOfArmies(int Armies);
	void AddCountry(Country country);
	void PrintPlayerStats();
};

#endif





