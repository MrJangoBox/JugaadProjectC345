#include "stdafx.h"
#include "player.h"

// Default constructor declaration
Player::Player() : playerName("")
{
}

// Parameterized constructor decalration
Player::Player(string playerName) : playerName(playerName)
{
	// Alternative constructor implementation for manual parametrization includes array of country objects
	//Country countries[1] = { Country("Atlantis",3) };
	//cout << "\n\nCountry Name: " + countries[0].getCountryName();
	//cout << "\nNumber of Armies: ";
	//cout << countries[0].getNumOfArmies();
}

// Name defintion method
void Player::enterPlayerName()
{
	cout << "\n\nEnter Player Name: ";
	cin >> playerName;
}

// Name retrieval method
string Player::getPlayerName()
{
	return playerName;
}

// Name retrieval method
//string Player::getPlayerCountryName()
//{
//	for (int i=0; i<1; i++) { 
//		return countries[i].getCountryName();
//	}
//}