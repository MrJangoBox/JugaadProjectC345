#include "Node.h"
#include "Continent.h"
#include "Army.h"
#include<iostream>
#include<string>
using namespace std;

Army::Army(string army_name, int army_population, Node *node, Continent *continent)
{
	this->army_name = army_name;
	this->army_population = army_population;
	this-> node = *node;
	this-> continent = *continent;
};

Army::~Army()
{
	//player destructor method
}