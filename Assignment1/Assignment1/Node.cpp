#include "Node.h"
#include "Continent.h"
#include "Army.h"
#include "Player.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//node constructor
Node::Node(string name, Continent *continent, vector<Node>)
{
	this->name = name;
	this->continent = *continent;
	this->adjacent = vector<Node*>();
};

Node::~Node()
{
	//node or country destructor method
}

ostream& operator<< (ostream &out, const Node &node)
{
	out << "[" << node.continent << ", " << node.name << "]";
	return out;
}

istream& operator>> (istream &in, Node &node)
{
	return in;
}
