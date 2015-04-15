#ifndef DICE_H
#define DICE_H
//#include "stdafx.h"

/**
* A player class with its functions initialization
*/
class Dice {
public:
	// Default constructor
	Dice();
	// Parametrized constructor
	Dice(int diceRoll);

	// Public methods Declartions
	void enterDiceRoll(int diceValue);
	int getDiceRoll();
	void rollDice();

	// Public variables declaration
	int diceRoll;

private:

};
#endif
