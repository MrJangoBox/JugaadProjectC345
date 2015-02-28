//#include "stdafx.h"
/**
* A player class with its functions initialization
*/
class Country {
public:
	// Default constructor
	Country();
	// Parametrized constructor
	Country(string countryName, int numOfArmies);

	// Public methods Declartions
	void enterCountryName();
	string getCountryName();
	int getNumOfArmies();
	void setNumOfArmies(int newNumOfArmies);

	// Public variables declaration
	string countryName;
	int numOfArmies;
	//Country countries[1];
private:

};
