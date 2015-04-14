#ifndef BATTLE_H
#define BATTLE_H
//#include "stdafx.h"
#include "country.h"
#include "Player.h"

#include <string>
using namespace std;

/**
* A player class with its functions initialization
*/
class Battle {
public:
	// Default constructor
	Battle();
	// Parametrized constructor
	Battle(Player *pAtkr, Country *cAtkr, Country *cDfndr);

	// Public methods Declarations

	// Public variables declaration
	Country *countryAtkr;
	Country *countryDfndr;
	Player *playerAtkr;


private:
	// Private methods Declarations

	// Main battle function with the two conflicting coutries as input
	void battleDrive(Country *countryDfndr, Country *countryAtkr);

	// Function to fing highest value in input array
	int maximumValue(int a[]);

	// Determines maximum attack roll allowance based on number of armies in country
	int availableAttackType(Country cAtkr);

	// Determines maximum defense roll allowance based on number of armies in country
	int availableDefenseType(Country cDfndr, int numOfAtckRolls);

	// User choice of attack
	int attackChoice(int maxRollNum);

	// Performs the selected number of roles and stores them in array
	int* attackRoll(int numOfAtckRolls); 

	// Determines maximum number of defence rolls
	int* defenseRoll(int maxRollNum);

	// Determines best roll in provide array
	int getBestRoll(int arr[]);

	// Determines second best roll in provide array
	int getSecondBestRoll(int* arr, int currentMax);

	// Determines winner of the round
	string getWinner(int maxAtkr, int maxDfndr);

	// Determines the max attacker roll automatically during All-in
	int maxAttackType(Country cAtkr); 

	// All in attack feature until conquer or loss
	void allIn(Country *cAtkr, Country *cDfndr);

	// Private variables declaration

};
#endif
