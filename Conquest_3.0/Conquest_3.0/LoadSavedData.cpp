#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h>

#include "LoadSavedData.h"
#include "Continent.h"
#include "Country.h"
#include "Player.h"
#include "StartupPhase.h"

using namespace std;

// Default constructor declaration
LoadSavedData::LoadSavedData() : playersList()
{
}

// Parameterized constructor declaration
LoadSavedData::LoadSavedData(vector<Player> *playersLPtr, vector<Country*>* LoadedMap) : playersList(playersLPtr), map(LoadedMap)
{
	// Reinitialization of player list
	playerVector = LoadSavedGame();

	//playersList.erase(playersList.begin() + 1, playersList.begin() + 3);
}

vector<string> open(string path = ".") {

    DIR* dir;
    dirent* pdir;
    vector<string> files;

    dir = opendir(path.c_str());

    while (pdir = readdir(dir)) {
        files.push_back(pdir->d_name);
    }
    
    return files;
}

int LoadSavedData::getIndexOfCountry(string name) 
{
	for(int i = 0; i < map->size(); i++) 
	{
		if(map->at(i)->getCountryName() == name)
			return i;
	}
	return 999; // need proper exceptions.
}

vector<Player>* LoadSavedData::LoadSavedGame()
{
	vector<string> f;
    f = open("savedGames"); // or pass which dir to open

	cout << "\n\nPreviously saved games: \n"; 

	// Displays all previously saved files
	for(int i = 2; i < f.size(); i++)
	{
		cout << "Option [" << i-2 << "] " << f.at(i) << endl;
	}

	int fileName = -1;
	cout << "\nPlease enter one of the existing file options: " << endl;
	cin >> fileName;

	while(fileName < 0 || fileName > f.size())
	{
		cout << "\n invalid option, please try again ";
		cin >> fileName;
	}

	return LoadGame(f.at(fileName+2));
}

vector<Player>* LoadSavedData::getLoadedVector()
{
	return playerVector;
}

vector<Player>* LoadSavedData::LoadGame(string filename)
{
	vector<Player>* newPlayerVector = new vector<Player>;
	string nextLine;
	string previousLine = " ";

	ifstream inputfile;
	inputfile.open ("savedGames/" + filename);
	getline(inputfile,nextLine);

	if(nextLine == "[Players]")
	{
		while(!inputfile.eof( )) //Read the file till it reached the end.
		{
			getline(inputfile,nextLine); // Retrieves and stores the next line in the file.
			if (nextLine != previousLine && !nextLine.empty())
			{
				previousLine = nextLine;
				newPlayerVector->push_back(LoadPlayer(previousLine));
			}
		}
	}
	inputfile.close();

	return newPlayerVector;
}

Player LoadSavedData::LoadPlayer(string Line)
{
	int countryPos;

	vector<string> tokens;
	string delimeter = ",";

	string tokenLine;
	size_t pos = 0;
	string tokenDelimeter = "=";

	size_t endPos = 0;
	string token;
	while (endPos != string::npos)
	{
		endPos = Line.find(delimeter);
		token = Line.substr(0, endPos);
		tokens.push_back(token);
		Line = Line.substr(endPos+delimeter.length(), string::npos);
	}


	Player player = Player(tokens.at(0), 0);
	player.setDefinedTypeOfPlayer(tokens.at(1));
	player.setRemainingArmies(stoi(tokens.at(2)));

	for (int i = 3; i < tokens.size(); i++)
	{
		tokenLine = tokens.at(i);
		pos = tokenLine.find(tokenDelimeter);
		token = tokenLine.substr(0, pos);
		tokenLine.erase(0, pos + tokenDelimeter.length());
		
		countryPos = getIndexOfCountry(token);

		map->at(countryPos)->setArmies(stoi(tokenLine));

		player.addCountriesOwned(map->at(countryPos));
	}


	return player;
}