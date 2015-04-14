#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H
#include <vector>
#include "Player.h"
#include "Country.h"
#include "LoadData.h"

using namespace std;

class StartupPhase {

private:
	// Private Variables
	int numberOfPlayers; //Number of players chosen by the user.
	vector <Player> *players; //List of players
	vector<Country*> listOfCPtr; //List of all the countries in the map.
	vector<Country> neighbours;
	vector<Country*>* LoadedMap;
	
	// Private Methods
	int getInitialArmyPlacements(int NumberOfPlayers); //Computes the intial number of armies according to the numberOfPlayers.
	void ShuffleCountries(); //Shuffle elements in the countries vector.
	void AddCountries();
	void AddNeighbours();
	void PrintPlayerInfo(); //Display
	vector<Country*>* LoadMapStep(); //Loads the base risk map

public:
	StartupPhase(int NoOfPlayers); 

	int getNumberOfPlayers();
	vector <Player> getPlayers();
	vector <Country> getCountries();
	void StartGame();
	void ChooseMap();
	void CreatePlayers();
	void AssignCountries();
	void ErasePlayers();
};
#endif
