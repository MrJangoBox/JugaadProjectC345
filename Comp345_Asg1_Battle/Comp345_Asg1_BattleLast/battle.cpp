#include "stdafx.h"
#include "battle.h"
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor declaration
Battle::Battle() : playerAtkr(""), playerDfndr("")
{
}

// Parameterized constructor decalration
Battle::Battle(Player pAtkr, Player pDfndr) : playerAtkr(pAtkr), playerDfndr(pDfndr)
{
	cout << "A battle has Begun";
}

// Name defintion method
//void Battle::enterCountryName()
//{
//	cout << "\n\nEnter Country Name: ";
//	cin >> countryName;
//}