#include "Country.h"
#include "Continent.h"
#include "Army.h"

#include<iostream>
#include<string>

using namespace std;

Army::Army(string playerName, Node *node, Continent *continent)
{
	this-> playerName = playerName;
	this-> node = node;
	this-> continent = continent;
};

/*Army::~Army()
{
	//player destructor method
}*/