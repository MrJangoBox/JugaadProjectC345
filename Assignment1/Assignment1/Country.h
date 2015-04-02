#ifndef COUNTRY_H_
#define COUNTRY_H_

#include<vector>
#include<string>

#include "Army.h"
#include "Continent.h"
#include "Player.h"

using namespace std;

class Country
{
	//friend: a class or func has access to private members - instead of using accessor/mutator methods
	friend ostream& operator<< (ostream &out, const int &country); //don't make a copy of the node you receive, can't change it that's why it's pass by ref and keyword const
	friend istream& operator>> (istream &in, int &node); //don't make a copy of the node you're recieving

public:	Country::Country(string name, Continent *continent, vector<Country>* adjacent, int code, string player);
	string name;
	Continent *continent;
	vector<Country>* adjacent;
	int code;
	string player;

	vector<Country>* Country:: getAdjacentCountries(Country country);
	

};
#endif /* COUNTRY_H_ */
