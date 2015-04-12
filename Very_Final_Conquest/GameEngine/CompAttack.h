#ifndef COMPATTACK_H
#define COMPATTACK_H
/**
* Attack strategy class declaration for computer players
*/

#include "Strategy.h"
#include "Player.h"

class CompAttack {
	private:
	Strategy *attackStrategy;
	
	public:
	// Default constructor
	CompAttack();
	/**
	* Parameterized constructor
	*/
	CompAttack(Strategy *initStrategy);

	// Steategy setter
	void setAttackStrategy(Strategy *newAttackStrategy);

	/**
	* Method that executes a different attack strategy depending on the players
	* neighbourhood configuration.sd
	*/
	void executeAttackStrategy(Player *player);
};
#endif