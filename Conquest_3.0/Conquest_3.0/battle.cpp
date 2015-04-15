//#include "stdafx.h"
#include "battle.h"
#include "player.h"
#include "dice.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor declaration
Battle::Battle() : playerAtkr(), countryAtkr(), countryDfndr()
{
}

// Parameterized constructor decalration
Battle::Battle(Player *pAtkr, Player *pDfndr, Country *cAtkr, Country *cDfndr) : playerAtkr(pAtkr), playerDfndr(pDfndr), countryAtkr(cAtkr), countryDfndr(cDfndr)
{

	// Very simple AI, if player is a computer, it will always All-in if atttacks depending on strategy
	if(pAtkr->getPlayerName() == "PLAYER 1") {
		battleDrive(countryDfndr, countryAtkr);
	} else {
		allIn(countryAtkr, countryDfndr);
	}

}

//Function to find highest (maximum) value in array
int Battle::maximumValue(int a[])
{
	 int max = 0;       // start with max = first element

     for(int i = 0; i<3; i++)
     {
		 int value = a[i];
		 
		 // Adds roll value to displayed list of rolls if set
		 if (value != -1)
			cout << value << ", ";

          if(value > max)
		  {
			  //cout << "\n\ngreater element " << array[i] << "\n\n finally ";
              max = value;
		  }
	 }
     return max;                // return highest value in array
}

// Determines maximum attack roll allowance based on number of armies in country
int Battle::availableAttackType(Country cAtkr) 
{
	
	int maxRollNum = 4;

	if (cAtkr.getArmiesPlaced() < 3) 
		maxRollNum = cAtkr.getArmiesPlaced();

	return maxRollNum;
}

// User choice of attack
int Battle::attackChoice(int maxRollNum) 
{
	int numDiceRoll = NULL;
	switch(maxRollNum) 
	{
		case 1 : while (numDiceRoll == NULL)
				 {
					cout << "\nChoose number of dice roll (available: 1) ";
					cin >> numDiceRoll;
					if (numDiceRoll != 1) 
					{
						numDiceRoll = NULL;
					}
					cin.clear();
					cin.ignore(10000,'\n');
				 }
				 break;
		case 2 : while (numDiceRoll == NULL)
				 {
					cout << "\nChoose number of dice roll (available: 1 or 2) ";
					cin >> numDiceRoll;
					if (numDiceRoll != 1 && numDiceRoll != 2) 
					{
						numDiceRoll = NULL;
					}
					cin.clear();
					cin.ignore(10000,'\n');
				 }
				 break;
		case 3 : while (numDiceRoll == NULL)
				 {
					cout << "\nChoose number of dice roll (available: 1,2 or 3) ";
					cin >> numDiceRoll;
					if (numDiceRoll != 1 && numDiceRoll != 2 && numDiceRoll != 3) 
					{
						numDiceRoll = NULL;
					}
					cin.clear();
					cin.ignore(10000,'\n');
				 }
				 break;
		case 4 : while (numDiceRoll == NULL)
				 {
					cout << "\nChoose number of dice roll (available: 1,2,3 or 4) ";
					cin >> numDiceRoll;
					if (numDiceRoll != 1 && numDiceRoll != 2 && numDiceRoll != 3 && numDiceRoll != 4) 
					{
						numDiceRoll = NULL;
					}
					cin.clear();
					cin.ignore(10000,'\n');
				 }
				 break;
	}
	return numDiceRoll;
}

// Performs the selected number of roles and stores them in array
int* Battle::attackRoll(int numOfAtckRolls) 
{
	static int roundsAtkr[3];

	// Initializes Array to no rolls
	for(int j = 0; j < 3; j++)
	{
		roundsAtkr[j] = -1;
	}

	Dice diceAtkr(0);
	switch(numOfAtckRolls)
	{
		case 1 : for(int i=0; i<1; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
				 }
				 break;
		case 2 : for(int i=0; i<2; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
				 }
				 break;
		case 3 : for(int i=0; i<3; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
				 }
				 break;
	}
	return roundsAtkr;
}

// Determines maximum defense roll allowance based on number of armies in country
int Battle::availableDefenseType(Country cDfndr, int numOfAtckRolls) 
{
	
	int maxRollNum = 2;

	if (cDfndr.getArmiesPlaced() < 2) 
	{
		maxRollNum = cDfndr.getArmiesPlaced();
	} else if(numOfAtckRolls < 2) {
		maxRollNum = numOfAtckRolls;
	}

	return maxRollNum;
}

// Determines maximum number of defence rolls
int* Battle::defenseRoll(int maxRollNum) 
{
	static int roundsDfndr[3];

	for(int j = 0; j < 3; j++)
	{
		roundsDfndr[j] = -1;
	}

	Dice diceDfndr(0);
	switch(maxRollNum)
	{
		case 0 : for(int i=0; i<1; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
				 }
				 break; 
		case 1 : for(int i=0; i<1; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
				 }
				 break;
		case 2 : for(int i=0; i<2; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
				 }
				 break;
	}
	return roundsDfndr;
}

// Determines best roll in provided array
int Battle::getBestRoll(int arr[])
{
	int maxValue = maximumValue(arr); 
	cout <<  "  Max: " << maxValue << endl;
	return maxValue;
}

// Determines second best roll in provided array
int Battle::getSecondBestRoll(int* arr, int currentMax)
{
	int i = 0;


	while(*(arr + i) != currentMax)
	{
		i++;
	}
	*(arr + i) = -1;

	cout <<  "other rolls: ";

	int maxValue = maximumValue(arr);

	cout <<  "  Max: " << maxValue;

	return maxValue;	
}

// Determines winner of the round
string Battle::getWinner(int maxAtkr, int maxDfndr)
{
	if(maxAtkr <= maxDfndr)
	{
		return "Defender";
	} else {
		return "Attacker";
	}
}

// Remove army from the loosing country
void Battle::removeArmy(string winPlayer, Country &cAtkr, Country &cDfndr) 
{
	if(winPlayer == "Defender")
	{
		cout << "\n\n***Defender Won***" << endl;
		//cAtkr.setNumOfArmies(cAtkr.getNumOfArmies()-1);
		cAtkr.DecrementArmyCount(1);

	} else {

		cout << "\n\n***Attacker Won***" << endl;
		//cDfndr.setNumOfArmies(cDfndr.getNumOfArmies()-1);
		cDfndr.DecrementArmyCount(1);


		if(cDfndr.getArmiesPlaced() < 0)
		{
			cDfndr.setArmies(1);

			for(int i = 0; i < playerDfndr->getCountriesOwned()->size(); i++)
			{
				if(playerDfndr->getCountriesOwned()->at(i)->getCountryName() == cDfndr.getCountryName())
				{
					playerDfndr->getCountriesOwned()->erase(playerDfndr->getCountriesOwned()->begin()+i);
				}
			}

			playerAtkr->getCountriesOwned()->push_back(&cDfndr);
		}

	}
	cout << "\nStatistical Outcome: \n";
	cout << "\nAttacking Country's Armies: " << cAtkr.getArmiesPlaced();
	cout << "\nDefending Country's Armies: " << cDfndr.getArmiesPlaced() << endl;
}

// Determines the max attacker roll automatically during All-in
int Battle::maxAttackType(Country cAtkr) 
{
	
	int maxRollNum = 3;

	if (cAtkr.getArmiesPlaced() < 3) 
		maxRollNum = cAtkr.getArmiesPlaced();

	return maxRollNum;
}

// All in attack feature until conquer or loss
void Battle::allIn(Country *cAtkr, Country *cDfndr) 
{
	while(cAtkr -> getArmiesPlaced() > 0 && cDfndr -> getArmiesPlaced() > -1)
	{
		cout << "\n\n_____________New Round Starts______________";

		// Attacker Rolls *********************************************
		cout << "\n\n------First Roll Results------";

		// Retrieves max number of attack rolls
		int attackRolls = maxAttackType(*cAtkr);

		int *atkrArray;
		// Returns the pointer for the attack rolls array
		atkrArray = attackRoll(attackRolls);

		cout << "\n\nAttacker rolled: ";

		// Returns the max attack roll
		int attackBest = getBestRoll(atkrArray);

		// Defender Rolls *********************************************

		// Returns the max number of defend rolls
		int numDefenseRolls = availableDefenseType(*cDfndr, attackRolls);

		int *dfndrArray;
		// Returns the pointer for the defense rolls array
		dfndrArray = defenseRoll(numDefenseRolls);

		cout << "\n\nDefender rolled: ";

		// Returns the max defense roll
		int defenseBest = getBestRoll(dfndrArray);

		// Determine the Winner ***************************************

		// Returns the winning player
		string playerWinner = getWinner(attackBest, defenseBest);

		// Removes one country of the loosing player
		removeArmy(playerWinner, *cAtkr, *cDfndr);

		// Calculates a second win if defender & attacker rolled more than one dice
		if (numDefenseRolls > 1 && attackRolls > 1) 
		{

			cout << "\n\n------Second Roll Results------";

			cout << "\n\nAttacker ";

			int attackSecondBest = getSecondBestRoll(atkrArray, attackBest);
			int defenseSecondBest = getSecondBestRoll(dfndrArray, defenseBest);

			// Returns the winning player for a second roll
			string playerSecondWinner = getWinner(attackSecondBest, defenseSecondBest);

			// Removes a second country of the second loosing player
			removeArmy(playerSecondWinner, *cAtkr, *cDfndr);
		}
	}
	cout << "\n_______________End of Attack_______________\n\n";
}

// Battle Function between two players
void Battle::battleDrive(Country *countryDfndr, Country *countryAtkr) {

	// Retrieves available attack types
	int numAttackType = availableAttackType(*countryAtkr);

	// To choose the number of rolls
	int attackRolls = attackChoice(numAttackType);
	
	if( attackRolls != 4) {
		cout << "\n\n_____________New Round Starts______________";

		// Attacker Rolls *********************************************
		cout << "\n\n------First Roll Results------";

		int *atkrArray;
		// Returns the pointer for the attack rolls array
		atkrArray = attackRoll(attackRolls);

		cout << "\n\nAttacker rolled: ";

		// Returns the max attack roll
		int attackBest = getBestRoll(atkrArray);

		// Defender Rolls *********************************************

		// Returns the max number of defend rolls
		int numDefenseRolls = availableDefenseType(*countryDfndr, attackRolls);

		int *dfndrArray;
		// Returns the pointer for the defense rolls array
		dfndrArray = defenseRoll(numDefenseRolls);

		cout << "\n\nDefender rolled: ";

		// Returns the max defense roll
		int defenseBest = getBestRoll(dfndrArray);

		// Determine the Winner ***************************************

		// Returns the winning player
		string playerWinner = getWinner(attackBest, defenseBest);

		// Removes one country of the loosing player
		removeArmy(playerWinner, *countryAtkr, *countryDfndr);

		// Determines possible second winner ***************************

		// Calculates a second win if defender & attacker rolled more than one dice
		if (numDefenseRolls > 1 && attackRolls > 1) 
		{
			cout << "\n\n------Second Roll Results------";

			cout << "\n\nAttacker ";

			int attackSecondBest = getSecondBestRoll(atkrArray, attackBest);

			cout << "\nDefender ";
			int defenseSecondBest = getSecondBestRoll(dfndrArray, defenseBest);

			cout << "\n";
			// Returns the winning player for a second roll
			string playerSecondWinner = getWinner(attackSecondBest, defenseSecondBest);

			// Removes a second country of the second loosing player
			removeArmy(playerSecondWinner, *countryAtkr, *countryDfndr);
		}
		cout << "\n_______________End of Attack_______________\n\n";
	} else {
		allIn(countryAtkr, countryDfndr);
	}
}