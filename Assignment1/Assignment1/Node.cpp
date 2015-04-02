#include "Node.h"
#include "Continent.h"
#include "Army.h"
#include "Player.h"
#include "Node.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Continent;
class Player;

//node constructor
Node::Node(string name, Continent *continent, vector<Node>* adjacent, int code, Player player)
{
	this->name = name;
	this->continent = continent;
	this->adjacent = adjacent;
	this->code = code;
	this->player = player;
};

vector<Node>* Node:: getAdjacentCountries(Node node)
{
	//use Cheng's function to get neighbouring countries - she parses from the file and puts it in a vector - call that vector
	//like a getter method 
};




/*Node::~Node()
{
	//node or country destructor method
}*/

ostream& operator<< (ostream &out, const Node &node)
{
	out << "[" << node.continent << ", " << node.name << "]";
	return out;
}

istream& operator>> (istream &in, Node &node)
{
	return in;
}
