// Comp353_Asg1_BattleLast.cpp : main project file.
#include "stdafx.h"
#include "player.h"
#include "country.h"
#include "dice.h"

#include <time.h>       /* time */
#include <iostream>
#include <array>
#include <string>
using namespace std;

void printCountries(Country in[])
{
	for (int i = 0; i < 1; i++)
	{
		cout << "Coutry Number " << i + 1 << " Name: ";
		cout << in[i].getCountryName();
	}
}

//Function to find highest (maximum) value in array
int maximumValue(int a[])
{
	 int max = 0;       // start with max = first element

     for(int i = 0; i<3; i++)
     {
          if(a[i] > max)
		  {
			  //cout << "\n\ngreater element " << array[i] << "\n\n finally ";
              max = a[i];
		  }
	 }
     return max;                // return highest value in array
}

int availableAttackType(Country cAtkr) 
{
	
	int maxRollNum = 3;

	if (cAtkr.getNumOfArmies() < 3) 
		maxRollNum = cAtkr.getNumOfArmies();

	return maxRollNum;
}

int attackChoice(int maxRollNum) 
{
	int numDiceRoll = NULL;
	switch(maxRollNum) 
	{
		case 1 : while (numDiceRoll == NULL)
				 {
					cout << "Choose number of dice roll (available: 1)";
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
					cout << "Choose number of dice roll (available: 1 or 2)";
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
					cout << "Choose number of dice roll (available: 1,2 or 3)";
					cin >> numDiceRoll;
					if (numDiceRoll != 1 && numDiceRoll != 2 && numDiceRoll != 3) 
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

int* attackRoll(int numOfAtckRolls) 
{
	static int roundsAtkr[3];
	Dice diceAtkr(0);
	switch(numOfAtckRolls)
	{
		case 1 : for(int i=0; i<1; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
					//cout << roundsAtkr[i] << endl;
				 }
				 break;
		case 2 : for(int i=0; i<2; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
					//cout << roundsAtkr[i] << endl;
				 }
				 break;
		case 3 : for(int i=0; i<3; i++)
			     {
					diceAtkr.rollDice();
					roundsAtkr[i] = diceAtkr.getDiceRoll();
					//cout << roundsAtkr[i] << endl;
				 }
				 break;
	}
	return roundsAtkr;
}

int availableDefenseType(Country cDfndr) 
{
	
	int maxRollNum = 2;

	if (cDfndr.getNumOfArmies() < 2) 
		maxRollNum = cDfndr.getNumOfArmies();

	return maxRollNum;
}

int* defenseRoll(int maxRollNum) 
{
	static int roundsDfndr[3];
	Dice diceDfndr(0);
	switch(maxRollNum)
	{
		case 0 : for(int i=0; i<1; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
					//cout << roundsDfndr[i] << endl;
				 }
				 break; 
		case 1 : for(int i=0; i<1; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
					//cout << roundsDfndr[i] << endl;
				 }
				 break;
		case 2 : for(int i=0; i<2; i++)
			     {
					diceDfndr.rollDice();
					roundsDfndr[i] = diceDfndr.getDiceRoll();
					//cout << roundsDfndr[i] << endl;
				 }
				 break;
	}
	return roundsDfndr;
}

int getBestRoll(int arr[])
{
	cout <<  "\n\nMax Value: " << maximumValue(arr) << endl;
	return maximumValue(arr);
}

int getSecondBestRoll(int* arr, int currentMax)
{
	int i = 0;
	while(*(arr + i) != currentMax)
	{
		i++;
	}
	cout << "Current max position: " << currentMax << endl;
	cout << "Current max: " << currentMax << endl;
	cout << "\nBefore: " << *(arr + i);
	*(arr + i) = 0;
	cout << "\nAfter: " << *(arr + i);
		
	cout <<  "\n\nMax Second Value: " << maximumValue(arr) << endl;
	return maximumValue(arr);
	
}


string getWinner(int maxAtkr, int maxDfndr)
{
	if(maxAtkr <= maxDfndr)
	{
		return "Defender";
	} else {
		return "Attacker";
	}
}

void removeCountry(string winPlayer, Country &cAtkr, Country &cDfndr) 
{
	if(winPlayer == "Defender")
	{
		cAtkr.setNumOfArmies(cAtkr.getNumOfArmies()-1);
	} else {
		cDfndr.setNumOfArmies(cDfndr.getNumOfArmies()-1);
	}
	cout << "\nAttacker Armies: " << cAtkr.getNumOfArmies();
	cout << "\nDefender Armies: " << cDfndr.getNumOfArmies();
}

// Battle Function between two players
void battleDrive() {

	cout << "\tWelcome to the battle mechanics module\n\t\tby Oleksandr Dymov";

	// Initialization of attacker and its country
	Player playerAtkr("John");
	Country countryAtkr("Atlantis", 4);

	// Print to Console the initialization
	cout << "\n\nAttacker Player Name: " + playerAtkr.getPlayerName();
	cout << "\nCountry Name: " + countryAtkr.getCountryName();
	cout << "\nNumber of Armies: " << countryAtkr.getNumOfArmies();

	// Initialization of defender and its country
	Player playerDfndr("Silvia");
	Country countryDfndr("Eurasia", 3);

	// Print to Console the initialization
	cout << "\n\nDefender Player Name: " + playerDfndr.getPlayerName();
	cout << "\nCountry Name: " + countryDfndr.getCountryName();
	cout << "\nNumber of Armies: " << countryDfndr.getNumOfArmies() << endl;

	// Retrieves available attack types
	int numAttackType = availableAttackType(countryAtkr);

	// To choose the number of rolls
	int attackRolls = attackChoice(numAttackType);
	
	int *atkrArray;
	// Returns the pointer for the attack rolls array
	atkrArray = attackRoll(attackRolls);

	// Returns the max attack roll
	int attackBest = getBestRoll(atkrArray);

	// Returns the max number of defend rolls
	int numDefenseRolls = availableDefenseType(countryDfndr);

	int *dfndrArray;
	// Returns the pointer for the defense rolls array
	dfndrArray = defenseRoll(numDefenseRolls);

	// Returns the max defense roll
	int defenseBest = getBestRoll(dfndrArray);

	// Returns the winning player
	string playerWinner = getWinner(attackBest, defenseBest);

	// Removes one country of the loosing player
	removeCountry(playerWinner, countryAtkr, countryDfndr);

	// Calculates a second win if defender & attacker rolled more than one dice
	if (numDefenseRolls > 1 && attackRolls > 1) 
	{
		int attackSecondBest = getSecondBestRoll(atkrArray, attackBest);
		int defenseSecondBest = getSecondBestRoll(dfndrArray, defenseBest);

		// Returns the winning player for a second roll
		string playerSecondWinner = getWinner(attackSecondBest, defenseSecondBest);
		cout << "\n\nSecond winner: " << playerSecondWinner;
		
		cout << "\nBefore Removal Attacker Armies: " << countryAtkr.getNumOfArmies();
		cout << "\nDefender Armies: " << countryDfndr.getNumOfArmies();

		// Removes a second country of the second loosing player
		removeCountry(playerSecondWinner, countryAtkr, countryDfndr);
	}

}




int main()
{
	// Sets the seed for rand generator based on time
	srand(time(NULL));

	// Battle's main function
	battleDrive();
	












	//string attackType = "";
	//bool turnOver = false;
	//string rollDice = "";

	// Aletenatively can set the parameters manually (simply uncomment these lines re-run)
	//cout << "\n\n\nAttacker Information";
	//playerAtkr.enterPlayerName();
	//countryAtkr.enterCountryName();

	//cout << "\n\n\nDefender Information";
	//playerDfndr.enterPlayerName();
	//countryDfndr.enterCountryName();

	// Information about entered parameters (simply uncomment these lines re-run)
	//cout << "\n\n\nEntered Players Information";
	//cout << "\n\nAttacker Player Name: " + playerAtkr.getPlayerName();
	//cout << "\nCountry Name: " + countryAtkr.getCountryName() + " which has " << countryAtkr.getNumOfArmies() << " armies.";

	//cout << "\n\nDefender Player Name: " + playerDfndr.getPlayerName();
	//cout << "\nCountry Name: " + countryDfndr.getCountryName() + " which has " << countryDfndr.getNumOfArmies() << " armies.";


	// Retrieve information when parameterized player construction init's a coutry Array
	//cout << "\n\n" + playerAtkr.countries[0].getCountryName();


	//Dice diceAtkr(0);
	//Dice diceDfndr(0);

	////int roundsAtkr[3];
	////int roundsDfndr[2];

	////cout << "\n\nArray 1 size: " << sizeof(roundsAtkr);
	////cout << "\n\nArray 1 size: " << sizeof(roundsDfndr);

 //   cout << "\n\n\nA battle has Begun!\n";

	//while (attackType != "dice" && attackType != "all-in") 
	//{
	//	cout << "\n\nAttacker Turn, choose to roll a dice(enter dice) or All-In (enter all-in): ";
	//	cin >> attackType;
	//}

	//while (turnOver == false)
	//{
	//	int roundsAtkr[3];
	//	int roundsDfndr[2];
	//	if (attackType == "dice") 
	//	{
	//		int numOfAtkrTurns = 3;
	//		bool endRolls = false;
	//		
	//		// Attacker's Dice Rolls (Maximum 3 rolls)
	//		while (countryAtkr.getNumOfArmies() > 0 && countryDfndr.getNumOfArmies() > 0 && numOfAtkrTurns > 0 && endRolls == false)
	//		{
	//			rollDice = "";
	//			diceAtkr.rollDice();
	//			cout << "\n\nDice roll gives: " << diceAtkr.getDiceRoll();
	//			
	//			if (diceAtkr.getDiceRoll() > countryAtkr.getNumOfArmies())
	//			{
	//				roundsAtkr[3-numOfAtkrTurns] = 1;
	//				cout << "\n\nNot loged since greater than the number of armies in attacker's country!";
	//			} else {
	//				roundsAtkr[3-numOfAtkrTurns] = diceAtkr.getDiceRoll();
	//			}

	//			if (numOfAtkrTurns < 2) {
	//				rollDice = "n";
	//				cout << "\n\nIt was your last run.\n\n";
	//			}

	//			while (rollDice != "y" & rollDice != "n") {
	//				cout << "\n\nWould you like to roll another dice? (enter y or n)";
	//				cin >> rollDice;
	//			}

	//			if (rollDice == "n") {
	//				endRolls = true;
	//			}

	//			numOfAtkrTurns--;
	//		}

	//		cout << "\n\n\nNow Defender's turn to roll dice(s)";
	//		
	//		bool singleRound = false;

	//		// Determines the number of Defender's turns
	//		int numOfDfndrTurns = 0;
	//		if (numOfAtkrTurns > 1) 
	//		{
	//			singleRound = true;
	//		}

	//		// Defender's Dice Rolls (Maximum number of turns equlas to attacker's rolls minus 1 or 1 if rolled once)
	//		while (countryAtkr.getNumOfArmies() > 0 && countryDfndr.getNumOfArmies() > 0 && numOfDfndrTurns < 3)
	//		{
	//			rollDice = "";

	//			diceDfndr.rollDice();
	//			cout << "\n\nDice roll gives: " << diceDfndr.getDiceRoll();
	//				
	//			if (diceDfndr.getDiceRoll() > countryAtkr.getNumOfArmies())
	//			{
	//				roundsDfndr[numOfDfndrTurns] = 1;
	//				cout << "\n\nNot loged since greater than the number of armies in attacker's country!";
	//			} else {
	//				roundsDfndr[numOfDfndrTurns] = diceDfndr.getDiceRoll();
	//			}
	//			
	//			if (numOfDfndrTurns > 0 || singleRound == true) {
	//				rollDice = "n";
	//				cout << "\n\nIt was your last run.\n\n";
	//			}

	//			while (rollDice != "y" & rollDice != "n") {
	//				cout << "\n\nWould you like to roll another dice? (enter y or n)";
	//				cin >> rollDice;
	//			}

	//			if (rollDice == "n") {
	//				numOfDfndrTurns = 3;
	//			}

	//			numOfDfndrTurns++;
	//		}

	//		// Shows the maximum scores obtained by the two players
	//		cout << "\n\nAttacker's max value " << maximumValue(roundsAtkr);
	//		cout << "\n\nDefender's max value " << maximumValue(roundsDfndr);

	//		// Determines the winning player
	//		if(maximumValue(roundsAtkr) > maximumValue(roundsDfndr)) {
	//			cout << "\n\nDefender looses a country!";
	//			countryDfndr.setNumOfArmies(countryDfndr.getNumOfArmies() - 1);
	//		} else {
	//			cout << "\n\nAttacker looses a country!";
	//			countryAtkr.setNumOfArmies(countryAtkr.getNumOfArmies() - 1);
	//		}

	//			cout << "\n\nArray 1 size: " << sizeof(roundsAtkr);
	//			cout << "\n\nArray 1 size: " << sizeof(roundsDfndr);

	//		// Print to Console the initialization
	//		cout << "\n\nAttacker Player Name: " + playerAtkr.getPlayerName();
	//		cout << "\nCountry Name: " + countryAtkr.getCountryName();
	//		cout << "\nNumber of Armies: " << countryAtkr.getNumOfArmies();

	//		// Print to Console the initialization
	//		cout << "\n\nDefender Player Name: " + playerDfndr.getPlayerName();
	//		cout << "\nCountry Name: " + countryDfndr.getCountryName();
	//		cout << "\nNumber of Armies: " << countryDfndr.getNumOfArmies();


	//		turnOver = true;
	//	} else if (attackType == "all-in") {
	//	
	//		turnOver = true;
	//	}
	//}

	cout << "\n\n";
	system("pause");
	return 0;
}
