//#include "stdafx.h"
//#include "player.h"
//#include "country.h"
#include "dice.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <string>
using namespace std;

// Default constructor declaration
Dice::Dice() : diceRoll(0)
{
}

// Parameterized constructor decalration
Dice::Dice(int diceRoll) : diceRoll(diceRoll)
{
}

// Dice Roll defintion method
void Dice::enterDiceRoll(int diceValue)
{
	diceRoll = diceValue;
}

// Dice Roll retrieval method
int Dice::getDiceRoll()
{
	return diceRoll;
}

// Roll Dice and changes value
void Dice::rollDice()
{

	diceRoll = 0;

	// Rolls the dice and sets its dice roll value
	diceRoll = rand() % 6 + 1;
}