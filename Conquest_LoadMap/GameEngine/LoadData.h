#include <string>
using namespace std;

class LoadData 
{
private:
	void LoadData::loadMap(string mapFile);
		// Public vars
	string mapFile;

public:
	// Default constructor
	LoadData();
	// Parametrized constructor
	LoadData(string mFile);

};