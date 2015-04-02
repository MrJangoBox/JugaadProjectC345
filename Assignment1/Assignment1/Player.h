#ifndef PLAYER_H_
#define PLAYER_H_

#include "Continent.h"
#include "Node.h"

#include<vector>
#include<string>

using namespace std;

class Player
{
public:
	Player(string name, Node *node);
	string name;
	Node *node;
};

#endif PLAYER_H_