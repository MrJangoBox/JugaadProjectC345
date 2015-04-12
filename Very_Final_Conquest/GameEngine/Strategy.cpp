/**
* The classes that implement a concrete strategy should inherit this.
* The CompAttack class uses this to use a concrete attack strategy.
*/

#include "Strategy.h"
#include "Player.h"
#include "battle.h"
#include "dice.h"

#include <iostream>

using namespace std;

/**
* Method whose implementation varies depending on the attack strategy adopted.
*/
void Strategy::executeAttack(Player *player)
{
}

/**
* Aggressive attack strategy, where the outer loop scans through all Atkr player countries
* and second loop through all the coutries neighbours. This way it ensures to attack each neighbour
* coutry having less armies until wins everything or looses the armies in the attacking countries.
*/
void AggresiveAttack::executeAttack(Player *player){
	
	vector<Country*>* playerCountries = player->getCountriesOwned();

	// Outer loop - goes through all attacker owned countries
	for(int i = 0; i < playerCountries->size(); i++) {

		Country *atkrCountryP = player->getCountry(i);

		Country *playerCountry = playerCountries->at(i); 

		vector<Country*> countryNeighbours = playerCountry->getCNeighbours();

		// Inner loop - goes through all neighbpurs of the country
		for(int j = 0; j < countryNeighbours.size(); j++)
		{
			// determines if suitable according to strtategy to attack
			if(playerCountry->getArmiesPlaced() != 0 && countryNeighbours.at(j)->getArmiesPlaced() < playerCountry->getArmiesPlaced() 
				&& countryNeighbours.at(j)->getArmiesPlaced() >= 0)
			{
				Country *dfndrCountryP = countryNeighbours.at(j);
				cout << "\n\n*********************************************************\n";
				cout << "\nBattle between " << atkrCountryP->getCountryName() << " and " << dfndrCountryP->getCountryName() << endl;

				// Simulates a battle
				Battle myBattle(player, atkrCountryP, dfndrCountryP);
			}
		}
	}
}

/**
* Defensive attack strategy, where the outer loop scans through all Atkr player countries
* and second loop through all the coutries neighbours. In between the two loops, the program makes 
* sure that the country has a significant advantage over the other neighbours and that it haden't conquered 
* all of them already. Then it ensures to attack each neighbour coutry having less armies until wins everything 
* or looses the significant advantage armies in the attacking countries.
*/
void DefensiveAttack::executeAttack(Player *player){

	vector<Country*>* playerCountries = player->getCountriesOwned();

	// Outer loop - goes through all attacker owned countries
	for(int i = 0; i < playerCountries->size(); i++) {
		
		bool significantlyLess = true;

		Country *atkrCountryP = player->getCountry(i);

		Country *playerCountry = playerCountries->at(i); 

		vector<Country*> countryNeighbours = playerCountry->getCNeighbours();

		// Ensures significant advantage before attacking
		while(significantlyLess == true)
		{
			int totalNeighbourArmies = 0;

			// Checks if still has a significant advantage
			for(int k = 0; k < countryNeighbours.size(); k++)
			{
				if(countryNeighbours.at(k)->getArmiesPlaced()+2 >= playerCountry->getArmiesPlaced())
				{
					significantlyLess = false;
				}

				totalNeighbourArmies += countryNeighbours.at(k)->getArmiesPlaced();
			}

			// Checks if hasn't won all the surrounding territories
			if(totalNeighbourArmies <= 0)
			{
				significantlyLess = false;
			}

			if(significantlyLess == true)
			{
				// Inner loop - goes through all neighbpurs of the country
				for(int j = 0; j < countryNeighbours.size(); j++)
				{
					// determines if suitable according to strtategy to attack
					if(playerCountry->getArmiesPlaced() != 0 && countryNeighbours.at(j)->getArmiesPlaced() < playerCountry->getArmiesPlaced() 
						&& countryNeighbours.at(j)->getArmiesPlaced() >= 0)
					{
						Country *dfndrCountryP = countryNeighbours.at(j);
						cout << "\n\n*********************************************************\n";
						cout << "\nBattle between " << atkrCountryP->getCountryName() << " and " << dfndrCountryP->getCountryName() << endl;

						// Simulates a battle
						Battle myBattle(player, atkrCountryP, dfndrCountryP);
					}
				}
			}
		}
	}
}

/**
* Random attack strategy, where the outer loop scans through all Atkr player countries
* and second loop through all the coutries neighbours. At the same time it ensures to randomly 
* check weather to attact with a coutry and then randomly chooses a valid neighbour to attack. 
* Until wins or looses the armies in the attacking countries.
*/
void RandomAttack::executeAttack(Player *player){
	vector<Country*>* playerCountries = player->getCountriesOwned();

	// Outer loop - goes through all attacker owned countries
	for(int i = 0; i < playerCountries->size(); i++) {

		Country *atkrCountryP = player->getCountry(i);

		Country *playerCountry = playerCountries->at(i); 

		vector<Country*> countryNeighbours = playerCountry->getCNeighbours();

		// Randomly chooses to attack with this country or not
		int attackCond = rand() % 2;
		
		if(attackCond == 1)
		{
			// Inner loop - goes through all neighours of the country
			for(int j = 0; j < countryNeighbours.size(); j++)
			{
				// Randomly chooses to attack with this neighbour or not
				int attackNeighbour = rand() % 2;

				// Determines if should and if suitable according to strtategy to attack
				if(playerCountry->getArmiesPlaced() != 0 && attackNeighbour == 1 && countryNeighbours.at(j)->getArmiesPlaced() >= 0)
				{
					Country *dfndrCountryP = countryNeighbours.at(j);
					cout << "\n\n*********************************************************\n";
					cout << "\nBattle between " << atkrCountryP->getCountryName() << " and " << dfndrCountryP->getCountryName() << endl;

					// Simulates a battle
					Battle myBattle(player, atkrCountryP, dfndrCountryP);
				}
			}
		}
	}
}