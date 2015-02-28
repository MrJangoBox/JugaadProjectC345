#include <iostream>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <stddef.h>
#include "StartupPhase.h"
#include "Player.h"
#include "Country.h"
#include "MainPlayPhase.h"


using namespace std;

//Constructor that initialises the 'Game Board'.
StartupPhase::StartupPhase(int NoOfPlayers) {
	numberOfPlayers = NoOfPlayers;
	players = new vector <Player>; //Maximum number of players is 6.
	vector <Country> countries; // Maximum number of countries is 42.
}

int StartupPhase:: getNumberOfPlayers() {
	return numberOfPlayers;
}

vector<Player> StartupPhase:: getPlayers() {
	return *players;
}
vector<Country> StartupPhase:: getCountries() {
	return countries;
}

//This function would eventually implement to retrieve the Map from task 1.  
void StartupPhase:: ChooseMap() {
	cout << "Chosen Map : The Map of Risk\n" << "6 continents and 42 countries." << endl;	
}


//Return the initial number of armies allowed for the number of players chosen.
//ReadMe file contains the references of the game rules.
int StartupPhase::  getIntialArmyPlacements(int NumberOfPlayers) {
	if(NumberOfPlayers == 2)
		return 40;
	if(NumberOfPlayers == 3)
		return 35;
	if(NumberOfPlayers == 4)
		return 30;
	if(NumberOfPlayers == 5)
		return 25;
	else if(NumberOfPlayers == 6)
		return 20;
}

/*
create the number of Players the user defined.
This function will create Player objects.  */
void StartupPhase::CreatePlayers() {
	int armies = getIntialArmyPlacements(numberOfPlayers);
	cout <<  "\nEach player starts with " << armies << " armies (Infantry)." << endl;

	for(int i = 0; i < numberOfPlayers; i++) {
		stringstream playerName;
		playerName << "PLAYER " << (i+1);
		Player player = Player(playerName.str(), armies);
		players->push_back(player); // Add players to the list.
	}

	/* Check :
	cout << "Players in this round : " << endl;
	for(int i = 0; i < numberOfPlayers;  i++) {
	cout << players->at(i).getPlayerName() << endl;
	} */
}

void StartupPhase:: ShuffleCountries() {
	//Create Country objects just for demonstartion purposes.
	for(int i = 0; i < 42 ; i++) {
		stringstream countryName;
		countryName << "Country " << (i+1);
		Country country = Country(countryName.str(), 0); //Number of armies placed in this country is initially 0. 
		countries.push_back(country);
	}

	//Shuffle elements in the vector countries.
	srand((unsigned int)time(0)); //provide a seed for the random generator
	random_shuffle(countries.begin(), countries.end());
}

//This function implements an array of Country objects to demonstration functionalities of the Game Engine. 
void StartupPhase:: AssignCountries() {
	cout << "Assigning random countries to each player." << endl;
	ShuffleCountries(); // create Country objects and Shuffle them.
	cout << "\nNumber of countries in the vector : " << countries.size() << endl;

	//Assign cards to players. works the same as shuffling a deck of cards and dealing 
	//a card to each player at every turn. 
	int j = 0;
	for(int i = 0; i < countries.size(); i++) {
		if (j == numberOfPlayers)
			j = 0;
		players->at(j).AddCountry(countries.at(i));
		j++;
	}

	PrintPlayerInfo(); //Check

}

void StartupPhase::PrintPlayerInfo() {
	for(int i = 0; i < numberOfPlayers; i++) {
		players->at(i).PrintPlayerStats();
	}
}

void StartupPhase:: StartGame() {
	MainPlayPhase mainPhaseObj = MainPlayPhase(players, countries.size());
	mainPhaseObj.StartRoundRobin();
}
