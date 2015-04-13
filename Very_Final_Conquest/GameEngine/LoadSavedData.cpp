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
	LoadSavedGame(*playersList);
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

void LoadSavedData::LoadSavedGame(vector<Player> playersList)
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

	LoadGame(f.at(fileName+2));
}



void LoadSavedData::LoadGame(string filename)
{
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
				LoadPlayer(previousLine);
			}
		}
	}
	inputfile.close();
}

void LoadSavedData::LoadPlayer(string Line)
{
	vector<string> tokens;
	string delimeter = ",";

	size_t endPos = 0;
	string token;
	while (endPos != string::npos)
	{
		endPos = Line.find(delimeter);
		token = Line.substr(0, endPos);
		tokens.push_back(token);
		Line = Line.substr(endPos+delimeter.length(), string::npos);
	}

	cout << map->at(1)->getCountryName();
}