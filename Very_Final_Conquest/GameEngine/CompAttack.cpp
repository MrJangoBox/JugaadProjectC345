/**
* Attack strategy class for computer players
*/
#include <iostream>
#include "CompAttack.h"

using namespace std;

// Default constructor
CompAttack::CompAttack(){};

/**
* Parameterized constructor
*/
CompAttack::CompAttack(Strategy *initAttackStrategy) : attackStrategy(initAttackStrategy) {

}

// Attack strategy setter
void CompAttack::setAttackStrategy(Strategy *newAttackStrategy){
	this->attackStrategy = newAttackStrategy;
}

/**
* Method that executes a different attack strategy depending on the players
* neighbourhood configuration.sd
*/
void CompAttack::executeAttackStrategy(Player *player){
	return this->attackStrategy->executeAttack(player);
}