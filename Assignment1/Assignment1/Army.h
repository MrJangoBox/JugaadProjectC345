#ifndef ARMY_H_
#define ARMY_H_

#include "Continent.h"
#include "Country.h"

#include<vector>
#include<string>

using namespace std;

class Node;
class Continent;

class Army  //THIS CLASS MAY OR MAY NOT BE ENTIRELY USELESS
{
public:
	Army(string playerName, Node *node, Continent *continent);
	string playerName;
	Node *node;
	Continent *continent;
};
#endif /* NODE_H_ */