#ifndef CONTINENT_H_
#define CONTINENT_H_
#include<string>
using namespace std;

class Continent
{
public:
	Continent(string name = "", int code = 0);
	virtual ~Continent();
	string name;
	int code;
};

#endif /* CONTINENT_H_ */
