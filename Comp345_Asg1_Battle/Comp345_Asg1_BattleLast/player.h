//#include "stdafx.h"

/**
* A player class with its functions initialization
*/
class Player {
public:
	// Default constructor
	Player();
	// Parametrized constructor
	Player(string playerName);

	// Public methods Declartions
	void enterPlayerName();
	string getPlayerName();
	void enterCountries();
	string getPlayerCountryName(); 

	// Public variables declaration
	string playerName;

private:

};

