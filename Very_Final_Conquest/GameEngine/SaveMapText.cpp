#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "SaveMapText.h"

using namespace std;

// Default constructor declaration
SaveMapText::SaveMapText() : mapFile()
{
}

// Parameterized constructor decalration
SaveMapText::SaveMapText(string mFile, LoadData textMap) : mapFile(mFile), mapText(textMap)
{
	SaveMap(mapFile, mapText);
}

void SaveMapText::SaveMap(string mapFile, LoadData mapText)
{

	ofstream outputfile;
	outputfile.open(mapFile);

	// Continets output
	outputfile << "[Continents]\n";

	for(int i = 0; i < mapText.getAllContients()->size(); i++)
	{
		outputfile << mapText.getAllContients()->at(i).getContinentName() << "=" << mapText.getAllContients()->at(i).getArmyValue() << endl;
	}

	// Country output
	outputfile << "[Territories]\n";

	for(int i = 0; i < mapText.getAllCountries()->size(); i++)
	{
		outputfile << mapText.getAllCountries()->at(i).getCountryName() << "," << mapText.getAllCountries()->at(i).getCountryContinentName() << "," << mapText.getAllCountries()->at(i).getArmiesPlaced() << endl;
	}

	outputfile.close();
}
