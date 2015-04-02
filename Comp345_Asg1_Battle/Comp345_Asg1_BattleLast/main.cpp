// Comp353_Asg1_BattleLast.cpp : main project file.
#include "stdafx.h"
#include "player.h"
//#include "country.h"
#include "dice.h"
#include "battle.h"

#include <time.h>       /* time */
#include <iostream>
#include <array>
#include <string>
using namespace std;


int main()
{
	cout << "\tWelcome to the battle mechanics module\n\t\tby Oleksandr Dymov";

	// Initialization of attacker and its country pointer
	Player playerAtkr("John");
	Country *countryAtkr;
	Country CountryAtkr("Atlantis", 4);
	countryAtkr = &CountryAtkr;


	// Print to Console the initialization
	cout << "\n\nAttacker Player Name: " + playerAtkr.getPlayerName();
	cout << "\nCountry Name: " + countryAtkr -> getCountryName();
	cout << "\nNumber of Armies: " << countryAtkr -> getNumOfArmies();

	// Initialization of defender and its country pointer
	Player playerDfndr("Silvia");
	Country *countryDfndr;
	Country CountryDfndr("Eurasia", 3);
	countryDfndr = &CountryDfndr;

	// Print to Console the initialization
	cout << "\n\nDefender Player Name: " + playerDfndr.getPlayerName();
	cout << "\nCountry Name: " + countryDfndr -> getCountryName();
	cout << "\nNumber of Armies: " << countryDfndr -> getNumOfArmies() << endl;




	// Sets the seed for rand generator based on time
	srand(time(NULL));
	
	// Battle's main function
	Battle myBattle(countryAtkr, countryDfndr);

	// Displays Final Results
	cout << "\n\n\n*** Final Results ***\n\nNumber of Attacker Armies: " << countryAtkr -> getNumOfArmies();
	cout << "\nNumber of Defender Armies: " << countryDfndr -> getNumOfArmies() << endl;




	cout << "\n\n";
	system("pause");
	return 0;
}
