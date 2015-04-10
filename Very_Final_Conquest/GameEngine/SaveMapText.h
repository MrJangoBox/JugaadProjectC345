#ifndef SAVEMAP_H
#define SAVEMAP_H
#include <string>
#include <vector>

#include "Continent.h"
#include "LoadData.h"

using namespace std;

class SaveMapText 
{
private:
	string mapFile;
	LoadData mapText;
	
	void print();
	void SaveMap(string mapFile, LoadData textMap);

public:
	SaveMapText(); // Default constructor
	SaveMapText(string mFile, LoadData textMap); // Parametrized constructor

};
#endif