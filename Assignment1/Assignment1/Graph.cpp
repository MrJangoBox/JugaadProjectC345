#include "Graph.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void Graph::addCountry(const string &name)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
        {
           vertex *v;
           v= new vertex(name);
           work[name]=v;
           return;
	    }
     cout<<"\nVertex already exists!";
}

void Graph::addEdge(const string& from, const string& to)
{
    vertex *f=(work.find(from)->second);
    vertex *t=(work.find(to)->second);
    pair<int,vertex*> edge = make_pair(to, from);  //edge pair tells you countries on both sides of it
    f->adj.push_back(edge);
}

