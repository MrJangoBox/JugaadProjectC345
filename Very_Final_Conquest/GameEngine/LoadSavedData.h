#ifndef LOADSAVEDDATA_H
#define LOADSAVEDDATA_H
#include <string>
#include <vector>

#include "Continent.h"
#include "Country.h"
#include "Player.h"

using namespace std;

class LoadSavedData 
{
private:
	// Private variables
	vector<Player> *playersList;
	vector<Country*>* map;

	// Private Methods
	void LoadSavedGame(vector<Player> playersLPtr);
	void LoadGame(string filename);
	void LoadPlayer(string previousLine);
	

public:
	LoadSavedData(); // Default constructor
	LoadSavedData(vector<Player> *playersLPtr, vector<Country*>* LoadedMap); // Parametrized constructor

};
#endif