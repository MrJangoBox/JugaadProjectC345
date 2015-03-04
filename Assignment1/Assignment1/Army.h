//#ifndef NODE_H_
#define NODE_H_
#include "Continent.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class Army
{
public:
	Army(string army_name, int army_population, Node *node, Continent *continent);
	string army_name;
	int army_population;
	Node *node;
	Continent *continent;
};
//#endif /* NODE_H_ */