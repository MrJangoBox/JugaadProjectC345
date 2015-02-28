#ifndef GRAPH_H_
#define GRAPH_H_
#include<vector>
#include "Node.h"
using namespace std;

class Graph
{
public:
	Graph();
	virtual ~Graph();
	vector<Node*> countries;
};
#endif /* GRAPH_H_ */
