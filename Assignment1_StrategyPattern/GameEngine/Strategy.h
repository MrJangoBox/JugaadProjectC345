/**
* The classes that implement a concrete strategy should inherit this.
* The CompAttack class uses this to use a concrete attack strategy.
*/

#include "Player.h"


class Strategy {
public:
	/**
	* Method whose implementation varies depending on the attack strategy adopted.
	*/
	virtual void executeAttack(Player *player);
};

/**
* A concrete Strategy that implements aggressive strategy
*/
class AggresiveAttack : public Strategy {
	public:
	void executeAttack(Player *player);
};

/**
* A concrete Strategy that implements defensive strategy
*/
class DefensiveAttack : public Strategy {
	public:
	void executeAttack(Player *player);
};

/**
* A concrete Strategy that implements random strategy
*/
class RandomAttack : public Strategy {
	public:
	void executeAttack(Player *player);
};