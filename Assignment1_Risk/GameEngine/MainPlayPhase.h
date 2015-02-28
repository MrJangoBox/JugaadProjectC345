#ifndef MAINPLAYPHASE_H
#define MAINPLAYPHASE_H
#include <vector>
#include "Player.h"
#include "StartupPhase.h"

using namespace std; 

class MainPlayPhase {
private:
	vector <Player> * listCopy;
	int numberOfCountries;

	void setNumberOfCountries(int countries);
	void Reinforce(Player *player);
	void Attack(Player *player);
	void Fortify(Player *player);
	void InitialArmyPlacement();
	int ComputeReinforcements(Player *player);
	void UserInputForReinforcement(Player *player);
	int SelectCountry(Player *player);
	int ChooseNumberOfArmies(Player *player);

public:
	MainPlayPhase(vector <Player> *playersPtr, int NoOfCountries);
	//void InitialArmyPlacement();
	void StartRoundRobin(); // pass the pointer the list of players (vector players) 

};
#endif