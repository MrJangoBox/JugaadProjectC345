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
	vector<Player> *playerVector;

	// Private Methods
	vector<Player>* LoadSavedGame();
	vector<Player>* LoadGame(string filename);
	Player LoadPlayer(string previousLine);
	int getIndexOfCountry(string name); 
	

public:
	LoadSavedData(); // Default constructor
	LoadSavedData(vector<Player> *playersLPtr, vector<Country*>* LoadedMap); // Parametrized constructor
	vector<Player>* getLoadedVector();

};
#endif