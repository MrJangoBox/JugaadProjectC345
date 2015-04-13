#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "SaveData.h"
#include "Continent.h"
#include "Country.h"
#include "Player.h"

using namespace std;

// Default constructor declaration
SaveData::SaveData() : playersList()
{
}

// Parameterized constructor decalration
SaveData::SaveData(vector<Player> *playersSPtr) : playersList(playersSPtr)
{
	SaveGame(*playersList);
}

void SaveData::SaveGame(vector<Player> playersList)
{
	// Creating the save file name
	string fileName;
	cout << "\nPlease Enter file name for saving the game: " << endl;
	cin >> fileName;

	// Open file to write in
	ofstream outputfile;
	outputfile.open ("savedGames/" + fileName + ".txt");

	// Writing to file
	outputfile << "[Players]\n";

	for(int i = 0; i < playersList.size(); i++)
	{
		outputfile << playersList.at(i).getPlayerName() << ",";
		outputfile << playersList.at(i).getTypeOfPlayer();
		for(int j = 0; j < playersList.at(i).getCountriesOwned()->size(); j++)
		{
			outputfile << "," << playersList.at(i).getCountriesOwned()->at(j)->getCountryName() << "=" << playersList.at(i).getCountriesOwned()->at(j)->getArmiesPlaced();
		}
		outputfile << endl;
	}

	outputfile.close();
}