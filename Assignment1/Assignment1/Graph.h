#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"

#include<vector>
#include <map>

using namespace std;

class Node;

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
	void addnode(const string &name);  //add country
	void addedge(const string& from, const string& to);   //add adjacency

	vector <Node>* countries;
	

};
#endif GRAPH_H_
