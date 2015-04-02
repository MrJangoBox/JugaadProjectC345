#include "Country.h"
#include "Continent.h"
#include "Player.h"

#include<iostream>
#include<string>

using namespace std;


Player::Player(string name, Node *node)
{
	this->name = name;
	this->node = node;
};


/*Player::~Player()
{
	//player destructor method
}*/