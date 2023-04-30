#pragma once

#include "C:\Users\amoha\CLionProjects\untitled5\Algos\Algorithm.h"

class BFS : public Algorithm
{
	struct InfStruct {
		ll d = 1e18;
	};
	struct Vertex
	{
		ll ID, onPath=0;
	};
	queue<Vertex>q;
	map<ll, InfStruct>distance;
	map<ll, ll>parent;
	map<ll,bool>vis;

public:
    BFS(Point src,Point ds){
        this->src = src;
        this->ds = ds;
    }
    void run(map<int, set<int>> &convertedGraph);
    void getPath(map<int, set<int>> &convertedGraph);
};