#include "Node.h"
#include "Continent.h"
#include "Player.h"
#include<iostream>
#include<string>
using namespace std;



Player::Player(string name, string rank, string attributes, Node *node)
{
	this->name = name;
	this->rank = rank;
	this->attributes = attributes;
	this->node = node;
};


Player::~Player()
{
	//player destructor method
}