#ifndef GRAPH_H_
#define GRAPH_H_

#include "Country.h"

#include<vector>
#include <map>

using namespace std;

class Country;

 struct vertex
 {
     typedef pair<int,vertex*> ve;
     vector<ve> adj; //cost of edge, destination vertex
     string name;
     vertex(string s)
     {
		name=s;
     }
 };

class Graph
{
public:
	Graph();
	virtual ~Graph();

	typedef map<string, vertex*> vmap;
	vmap work;
	void addCountry(const string &name);  //add country
	void addEdge(const string& from, const string& to);   //add adjacency

	vector <Country>* countries;
	

};
#endif GRAPH_H_
