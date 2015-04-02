#include "Country.h"
#include "Continent.h"
#include "Army.h"
//#include "Player.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Continent;
class Player;

//node constructor
Country::Country(string name, Continent *continent, vector<Country>* adjacent, int code, string player)
{
	this->name = name;
	this->continent = continent;
	this->adjacent = adjacent;
	this->code = code;
	this->player = player;
};

//vector<Country>* Country:: getAdjacentCountries(Country country)
//{
//	//use Cheng's function to get neighbouring countries - she parses from the file and puts it in a vector - call that vector
//	//like a getter method 
//};




/*Node::~Node()
{
	//node or country destructor method
}*/

ostream& operator<< (ostream &out, const Country &country)
{
	out << "[" << country.continent << ", " << country.name << "]";
	return out;
}

istream& operator>> (istream &in, Country &country)
{
	return in;
}
