#ifndef SAVEDATA_H
#define SAVEDATA_H
#include <string>
#include <vector>

#include "Continent.h"
#include "Country.h"
#include "Player.h"

using namespace std;

class SaveData 
{
private:
	// Private variables
	vector<Player> *playersList;

	// Private Methods
	void SaveGame(vector<Player> playersSPtr);
	

public:
	SaveData(); // Default constructor
	SaveData(vector<Player> *playersLPtr); // Parametrized constructor

};
#endif