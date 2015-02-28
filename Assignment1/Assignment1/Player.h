//#ifndef NODE_H_
#define NODE_H_

#include<vector>
#include<string>
#include "Continent.h"
#include "Node.h"

using namespace std;

class Player
{
public:
	Player(string name, string rank, string attributes, Node *node);
	string name;
	string rank;
	string attributes;
	Node *node;
};

//#endif /* NODE_H_ */