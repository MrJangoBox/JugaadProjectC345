
#include<iostream>
#include <time.h>
#include "MainPlayPhase.h"
#include "StartupPhase.h"
#include "LoadData.h"

using namespace std;

int main() {
	srand((unsigned int)time(0));


	vector<Country*>* currentMap = LoadData::LoadData("world.map").getAllCountries();

	cout << currentMap->size();

	cout << "\t\tRISK- GameEngine!" << endl;
	cout << "NOTE: This is a game for 2- 6 players only!\n" << endl;
	cout << "Choose the number of players : " << endl;
	int userInput = 0;
	cin >> userInput;

	//Valid input Check:
	while( (userInput < 2) || (userInput > 6) ) 
	{
		if(userInput < 1)
			cout << userInput << " : Invalid number of players!\n" << endl;
		if(userInput == 1)
			cout << "You cannot play by yourself!\n" << endl;
		else if(userInput > 6)
			cout << userInput << "Maximum number of players in RISK is 6!\n"<< endl;
		cout << "INVALID! Try again :" << endl;
		cin >> userInput;
	}

	cout << "Intialising " << userInput << " players.\n" << endl; 

	StartupPhase game =	StartupPhase:: StartupPhase(userInput);
	game.ChooseMap();
	game.CreatePlayers();
	game.AssignCountries();
	game.StartGame();

	system("PAUSE");
	return 0;
}