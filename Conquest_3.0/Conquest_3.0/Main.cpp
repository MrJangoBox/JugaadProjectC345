
#include<iostream>
#include <time.h>
#include "MainPlayPhase.h"
#include "StartupPhase.h"
#include "LoadData.h"
#include "Menu.h"

using namespace std;

int main() {
	srand((unsigned int)time(0));

	cout<<	"_____ _____ _____ _____ _____ _____ _____ ______ " << endl <<
		"|     |     |   | |     |  |  |   __|   __|_   _|" << endl <<
		"|   --|  |  | | | |  |  |  |  |   __|__   | | |"   << endl <<
		"|_____|_____|_|___|__  _|_____|_____|_____| |_| " << endl <<
		"		          |__|                       "   << endl;

	int userInput = 0;

	InitialMenu iMenu = InitialMenu();
	int optionChoice = iMenu.getOptionChoice();

	if(optionChoice == 1) {

		cout << "\nNOTE: This is a game for 2- 6 players only!\n" << endl;
		cout << "Choose the number of players : " << endl;
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
		game.StartGame();

	} else if(optionChoice == 2) {
		userInput = 2;
		StartupPhase game =	StartupPhase:: StartupPhase(userInput);
		
		LoadSavedData loadSaved = LoadSavedData(&game.getPlayers(), game.getLoadedMap());
		game.StartGame();
	} else if(optionChoice == 3) {
		return 0;
	} 

	system("PAUSE");
	return 0;
}