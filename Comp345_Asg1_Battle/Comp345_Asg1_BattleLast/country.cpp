#include "stdafx.h"
#include "country.h"


// Default constructor declaration
Country::Country() : countryName(""), numOfArmies(0)
{
}

// Parameterized constructor decalration
Country::Country(string countryName, int numOfArmies) : countryName(countryName), numOfArmies(numOfArmies)
{
}

// Name defintion method
void Country::enterCountryName()
{
	cout << "\n\nEnter Country Name: ";
	cin >> countryName;
}

// Name retrieval method
string Country::getCountryName()
{
	return countryName;
}

// Number of armies retrieval method
int Country::getNumOfArmies()
{
	return numOfArmies;
}

// Number of armies definition method
void Country::setNumOfArmies(int newNumOfArmies)
{
	numOfArmies = newNumOfArmies;
}