//#include "stdafx.h"
//#include "player.h"

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
	Battle(Player pAtkr, Player pDfndr);

	// Public methods Declarations

	// Public variables declaration
	Player playerAtkr;
	Player playerDfndr;
private:

};
