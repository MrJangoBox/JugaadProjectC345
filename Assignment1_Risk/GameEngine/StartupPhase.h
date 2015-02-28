#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H
#include <vector>
#include "Player.h"
#include "Country.h"

using namespace std;

class StartupPhase {

	friend class MainPlayPhase;
private:
	int numberOfPlayers;
	vector <Player> *players;
	vector<Country> countries;

	int getIntialArmyPlacements(int NumberOfPlayers);
	void ShuffleCountries();
	void PrintPlayerInfo();

public:
	StartupPhase(int NoOfPlayers); 

	int getNumberOfPlayers();
	vector <Player> getPlayers();
	vector <Country> getCountries();

	void setNumberOfPlayers(int input);
	void StartGame();
	void ChooseMap();
	void CreatePlayers();
	void AssignCountries();


};
#endif
