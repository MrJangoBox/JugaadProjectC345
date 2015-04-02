#ifndef NODE_H_
#define NODE_H_

#include<vector>
#include<string>

#include "Army.h"
#include "Continent.h"
#include "Player.h"

using namespace std;

class Node
{
	//friend: a class or func has access to private members - instead of using accessor/mutator methods
	friend ostream& operator<< (ostream &out, const int &node); //don't make a copy of the node you receive, can't change it that's why it's pass by ref and keyword const
	friend istream& operator>> (istream &in, int &node); //don't make a copy of the node you're recieving

public:	Node::Node(string name, Continent *continent, vector<Node>* adjacent, int code, Player player);
	string name;
	Continent *continent;
	vector<Node>* adjacent;
	int code;
	Player player;

	vector<Node>* Node:: getAdjacentCountries(Node node);
	

};
#endif /* NODE_H_ */
