#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H
#include <vector>
#include "Player.h"
#include "Country.h"

using namespace std;

class StartupPhase {

private:
	int numberOfPlayers; //Number of players chosen by the user.
	vector <Player> *players; //List of players
	vector<Country> countries; //List of all the countries in the map.
	vector<Country> neighbours;

	int getIntialArmyPlacements(int NumberOfPlayers); //Computes the intial number of armies according to the numberOfPlayers.
	void ShuffleCountries(); //Shuffle elements in the countries vector.
	void AddCountries();
	void AddNeighbours();
	void PrintPlayerInfo(); //Display

public:
	StartupPhase(int NoOfPlayers); 

	int getNumberOfPlayers();
	vector <Player> getPlayers();
	vector <Country> getCountries();
	void StartGame();
	void ChooseMap();
	void CreatePlayers();
	void AssignCountries();
};
#endif
