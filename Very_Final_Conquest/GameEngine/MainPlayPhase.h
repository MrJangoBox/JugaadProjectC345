#ifndef MAINPLAYPHASE_H
#define MAINPLAYPHASE_H
#include <vector>
#include "Player.h"
#include "StartupPhase.h"
#include "CompAttack.h"
#include "SaveData.h"
#include "LoadSavedData.h"

using namespace std; 

class MainPlayPhase {
private:
	// Private Variables
	vector<Player> *listCopy; //copy of the pointer to the vector of Players
	int numberOfCountries; //Total number of countries in the map.
	vector<Country*>* map;

	// Private methods
	void setNumberOfCountries(int countries); //Demo Purpose
	void Reinforce(Player *player);
	void Attack(Player *player);
	void Fortify(Player *player);
	void UserInputForReinforcement(Player *player);
	int ComputeReinforcements(Player *player);
//	int SelectCountry(Player *player);
	int SelectOption(vector<Country*> *countries); 
	int SelectNeighbour(vector<Country*> cNeighbours);
	int ChooseNumberOfArmies(Player *player);
	string CompChosesStrategy(Player *player);
	void SaveGame(vector<Player> *playersPtr);
	void LoadSavedData(vector<Player> *playersPtr);

public:
	//Public Methods
	MainPlayPhase(vector <Player> *playersPtr, int NoOfCountries, vector<Country*>* LoadedMap);
	void PlaceInitialArmies();
	void StartRoundRobin();  //Start Game
};
#endif