#pragma once

#include "../algorithm.h"

class BFS : public Algorithm
{
	struct Vertex
	{
		ll ID, onPath=0;
	};
	queue<Vertex>q;
	map<ll, ll>distance;
	map<ll, ll>parent;
	map<ll,bool>vis;

public:
    BFS(Point src,Point destination){
        this->src = src;
        this->destination = destination;
    }
    void run(map<int, set<int>> &convertedGraph);
    vector<Point> getPath(map<int, set<int>> &convertedGraph);
};