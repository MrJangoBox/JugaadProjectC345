#include <iostream>
#include <vector>
#include "MainPlayPhase.h"
#include "StartupPhase.h"
#include "Player.h"
#include "Country.h"
#include "battle.h"
#include "CompAttack.h"


using namespace std;

MainPlayPhase:: MainPlayPhase(vector<Player> *playersPtr, int NoOfCountries, vector<Country*>* LoadedMap) {
	
	listCopy = playersPtr;
	map = LoadedMap;
	numberOfCountries = NoOfCountries;

	PlaceInitialArmies();

	LoadSavedData::LoadSavedData(playersPtr, map);

	SaveGame(playersPtr);

	StartRoundRobin();
}

//This function is only for the purpose of demonstration.
void MainPlayPhase:: setNumberOfCountries(int countries) {
	numberOfCountries = countries;
}

//Place the initial set of armies on the countries owned by the Player. 
void MainPlayPhase:: PlaceInitialArmies() {
	for(int i = 0; i < listCopy->size(); i++) {
		int j = 0 ; 
		while(listCopy->at(i).getRemainingArmies() > 0) {
			listCopy->at(i).getCountry(j)->IncrementArmyCount(1);
			listCopy->at(i).DecrementNumberOfArmies(1);

			j++;
			if(j == listCopy->at(i).getCountriesOwned()->size())
				j = 0; // loop to the first element in the vector.
		}
		//listCopy->at(i).PrintPlayerStats();
	}
} 

void MainPlayPhase:: StartRoundRobin() {
	int roundCounter = 1; 
	int i = 0;	
	//Assuming a player wins when he owns all the countries.
	cout << "\n\t-------------ROUND " << roundCounter << " ------------ " << endl;
	while( listCopy->at(i).getCountriesOwned()->size() != numberOfCountries ) {
		cout << listCopy->at(i).getPlayerName() << " : " <<endl;
		Reinforce(&listCopy->at(i));
		Attack(&listCopy->at(i));
		Fortify(&listCopy->at(i));

		i++;
		if( i == listCopy->size()) {
			i = 0; // loop to Player 1.
			roundCounter++; // Counter for the number of turns.
			cout << "\n\t-------------ROUND " << roundCounter << " ------------ " << endl;
		}
		if(roundCounter == 2) //To avoid infinite looping for the purpose of demonstration.
			setNumberOfCountries(listCopy->at(i).getCountriesOwned()->size());
	} // end of while 

	if(listCopy->at(i).getCountriesOwned()->size() == numberOfCountries)
		cout << listCopy->at(i).getPlayerName() << " is the winner!" << endl;
}

int MainPlayPhase::ComputeReinforcements(Player *player) {
	return (player->getCountriesOwned()->size()/3);
}

void MainPlayPhase::Reinforce(Player *player) {
	char ch = 'Y';
	cout << "Reinforcement :" <<  "\n" << endl;

	int reinforcements = ComputeReinforcements(player);
	cout << "Total number of reinforcements for this turn : " << reinforcements << endl;
	player->IncrementNumberOfArmies(reinforcements);

	cout << "\nDo you want to reinforce your forces? Enter Y/N : " << endl;
	cin >> ch;

	//While the player still has Armies, place them in countries if the user chooses to.
	while((player->getRemainingArmies() > 0) && (toupper(ch) == 'Y')) {
		UserInputForReinforcement(player);
		player->PrintPlayerStats();
		cout << "Do you want to place more armies? Enter Y/N : " << endl;
		cin >> ch;
		while((toupper(ch) != 'Y') && (toupper(ch) != 'N')) {
			cout << "Invalid input! Try again. " << endl;
			cin >> ch;
		}
	}
}

//int MainPlayPhase::SelectCountry(Player *player) {
int MainPlayPhase::SelectOption(vector<Country*> * countries) {
	int optionNo;
	cin >> optionNo;
//	while( optionNo < 1 || optionNo > player->getCountriesOwned().size()) {
	while( optionNo < 1 || optionNo > countries->size()) {
		cout <<  "Please enter a valid number!" <<endl;
		cin >> optionNo;
	}
	return optionNo;
}

int MainPlayPhase::SelectNeighbour(vector<Country*> cNeighbours) {
	int optionNo;
	cin >> optionNo;
	while( optionNo < 1 || optionNo > cNeighbours.size()) {
		cout <<  "Please enter a valid number!" <<endl;
		cin >> optionNo;
	}
	return optionNo;
}

int MainPlayPhase::ChooseNumberOfArmies(Player *player) {
	int chosenArmies;
	cout << "How many armies (Infantries) would you like to place there? " << endl;
	cin >> chosenArmies;
	while( chosenArmies > player->getRemainingArmies()) {
		cout << "You have " << player->getRemainingArmies() << " remaining!" << endl;
		cout << "Please enter a valid number!" << endl;
		cin >> chosenArmies;
	}
	return chosenArmies;
}

void MainPlayPhase::UserInputForReinforcement(Player *player) {
	cout << "\n~PLAYER'S STATS~ " << endl;
	player->PrintPlayerStats();

	cout << "\nOn which country would you like to place armies?" << endl;
	cout << "Enter the Option Number : " << endl;
	int option = SelectOption(player->getCountriesOwned());
	int armiesToBePlaced = ChooseNumberOfArmies(player);

	player->getCountry(option - 1)->IncrementArmyCount(armiesToBePlaced);
	player->DecrementNumberOfArmies(armiesToBePlaced);
}

void MainPlayPhase::Attack(Player *player) {
	 
	// Determines if computer player or human player
	if(player->getPlayerName() != "PLAYER 1")
	{

		// *************************** Added for Assignement 2 - Strategy **********************************
		cout << "\n\n";
		player->PrintPlayerStats();

		// Based on the player type, sets the strategy to use during attack
		string playerType = player->getTypeOfPlayer();

		CompAttack compAttack(new RandomAttack());

		if (playerType == "Aggressive")
		{
			compAttack.setAttackStrategy(new AggresiveAttack());
		} else if (playerType == "Defensive") {
			compAttack.setAttackStrategy(new DefensiveAttack());
		}
		
		// Executes the randomly determined strategy for the player
		cout << "\n\n";
		compAttack.executeAttackStrategy(player);

		player->PrintPlayerStats();

		// *************************************************************************************************

	} else {
		char ch;	
		int from;
		int attack;
		cout << "\nYOUR turn to ATTACK!" << endl;
		cout << "\nDo you want to attack?" << endl;
	
		cin >> ch;

		while(toupper(ch) != 'Y' && toupper(ch) != 'N') {
				cout << "Not vald input" <<endl;
				cin >> ch;
			}

		while (toupper(ch) == 'Y') 
		{
		ch = 'B';
		cout << "These are your options : " << endl;
		player->PrintCountriesAndNeighbours();

		cout << "Which country would you like to ATTACK from?\nChoose an option." << endl;
		from = SelectOption(player->getCountriesOwned());

		cout << "Which country are you attacking?" <<endl;
		Country* country = player->getCountry(from - 1);
		vector<Country*> neighbours = country->getCNeighbours();
		attack = SelectNeighbour(country->getCNeighbours());
		// simplify above ?
	
		Country *atkrCountryP = player->getCountry(from - 1);
		Country *dfndrCountryP = player->getNeighbour(from - 1, attack - 1);

		Battle myBattle(player, atkrCountryP, dfndrCountryP);
	
		while(toupper(ch) != 'Y' && toupper(ch) != 'N') {
			cout << "\nDo you want to attack?" << endl;
				cin >> ch;
			
			}
		}
	}
}

//Has to be implemented according to adjacent countries.
//CHANGE VECTOR TO NEIGHBOURING COUNTRIES YOU OWN VECTOR
void MainPlayPhase::Fortify(Player *player) {
	char ch ;
	int from, to, armies;

	cout << "\nFortification" << "\n" << endl;
	cout << "Do you want to place armies on a different country you own?" << endl;
	cout << "Enter Y/N : " << endl;
	
	cin >> ch; 
	while(toupper(ch) != 'Y' && toupper(ch) != 'N') {
		cout << "Invalid Entry! \n Enter Y/N : " << endl;
		cin >> ch;
	}

	if(toupper(ch) == 'Y') {
		cout << "Current player stats " << endl;
		player->PrintPlayerStats();

		cout << "\nWhich country do you want to move armies from? Select the option. " << endl;
		from = SelectOption(player->getCountriesOwned());

		cout << "\nWhich country do you want to move it to? Select the option. " << endl;
		to = SelectOption(player->getCountriesOwned());

		cout << "\nHow many armies do you want to move? " << endl;
		cin >> armies;
		while(armies > (player->getCountry(from - 1)->getArmiesPlaced())) {
			cout << "Invalid input. Try again." << endl;
			cout << "You can move maximum " << player->getCountry(from)->getArmiesPlaced() << " armies!" << endl;
			cin >> armies;		
		}

		player->getCountry(from - 1)->DecrementArmyCount(armies);
		player->getCountry(to - 1)->IncrementArmyCount(armies);
		player->PrintPlayerStats();
	} // end of if-statement
}


// Saves the game in user defined file
void MainPlayPhase::SaveGame(vector<Player> *playersPtr) {
	SaveData save = SaveData(playersPtr);
}


