#include <iostream>
#include <sstream>
#include <algorithm>
#include <stddef.h>
#include "StartupPhase.h"
#include "Player.h"
#include "Country.h"
#include "MainPlayPhase.h"
#include "LoadData.h"

using namespace std;

//Constructor that initialises the 'Game Board'.
StartupPhase::StartupPhase(int NoOfPlayers) {
	numberOfPlayers = NoOfPlayers;
	players = new vector <Player>; //Maximum number of players is 6.
	vector <Country> countries; // Maximum number of countries is 42.

	ChooseMap();
	LoadedMap = LoadData::LoadData("world.map").getAllCountries();
	CreatePlayers();
	AssignCountries();
}

int StartupPhase:: getNumberOfPlayers() {
	return numberOfPlayers;
}

vector<Player> StartupPhase:: getPlayers() {
	return *players;
}
//vector<Country> StartupPhase:: getCountries() {
//	return countries;
//}

//This function would eventually implement to retrieve the Map from task 1.  
void StartupPhase:: ChooseMap() {
	cout << "Chosen Map : The Map of Risk\n" << "6 continents and 42 countries." << endl;	
}

//Return the initial number of armies allowed for the number of players chosen.
int StartupPhase::  getInitialArmyPlacements(int NumberOfPlayers) {
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

// Load Map
vector<Country*>* LoadMapStep()
{
	// Loads generic risk map
	 return LoadData::LoadData("world.map").getAllCountries();
}

//Create Player Objects.
void StartupPhase::CreatePlayers() {
	int armies = getInitialArmyPlacements(numberOfPlayers);
	cout <<  "\nEach player starts with " << armies << " armies (Infantry)." << endl;

	for(int i = 0; i < numberOfPlayers; i++) {
		stringstream playerName;
		playerName << "PLAYER " << (i+1);
		Player player = Player(playerName.str(), armies);
		players->push_back(player); // Add players to the list.
	}
}

//void StartupPhase::AddCountries() 
//{
//	//Create Country objects for the purpose of demonstration.
//	for(int i = 0; i < 42 ; i++) {
//		stringstream countryName;
//		countryName << "Country " << (i+1);
//		Country country = Country(countryName.str(), 0, "Continent"); //Number of armies placed in this country is initially 0. 
//		countries.push_back(country);
//	}
//}
//
//void StartupPhase::AddNeighbours() 
//{
//	//srand((unsigned int)time(0));
//
//	//Create Country neighbour vectors for the purpose of demonstration.
//	for(int i = 0; i < countries.size() ; i++) {
//		vector<Country*> neighbours;
//
//		for(int j = 0; j < 5; j++) {
//			int neighbour = 0;
//			vector<int> nIndex; 
//
//			while(neighbour == 0) { 
//				int cIndex = rand() % 41;
//				
//				if(cIndex != i && !(find(nIndex.begin(), nIndex.end(), cIndex) != nIndex.end())) {
//					nIndex.push_back(cIndex);
//					neighbours.push_back(&countries.at(cIndex));
//					neighbour = 1;
//				}
//			}
//		}
//
//		countries.at(i).SetNeighbours(neighbours);
//		
//	}
//}

//This function assigns random countries to each player.
void StartupPhase:: AssignCountries() {
	cout << "Assigning random countries to each player." << endl;
	
	
	//AddCountries();
	//AddNeighbours();
	

	ShuffleCountries(); // create Country objects and Shuffle them.

	//Same as dealing a deck of cards. 
	int j = 0;
	for(int i = 0; i < listOfCPtr.size(); i++) {
		if (j == numberOfPlayers)
			j = 0;
		players->at(j).AddCountry(listOfCPtr.at(i));
		j++;
	}
	//PrintPlayerInfo(); 
}

void StartupPhase:: ShuffleCountries() {
	
	//Shuffle elements in the vector countries.
	//srand((unsigned int)time(0)); //provide a seed for the random generator

	for(int i=0; i<LoadedMap->size(); i++)
	{ 
		listOfCPtr.push_back(LoadedMap->at(i));
	}
	random_shuffle(listOfCPtr.begin(), listOfCPtr.end());
	
	cout << listOfCPtr.size();
}

//Displays each player's attributes.
void StartupPhase::PrintPlayerInfo() {
	for(int i = 0; i < numberOfPlayers; i++) {
		players->at(i).PrintPlayerStats();
	}
}

//Function that starts the game.
void StartupPhase:: StartGame() {
	MainPlayPhase mainPhaseObj = MainPlayPhase(players, listOfCPtr.size());
}
