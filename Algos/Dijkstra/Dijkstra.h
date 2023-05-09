#pragma once

#include "../algorithm.h"
class Dijkstra : public Algorithm
{
private:
    //Used priority queue to get the best point every time at top in O(log(n)) , where n is the number of nodes
    priority_queue<pair<ll,ll >>pq;
    map<ll,ll>distance;
    map<ll, ll>parent;
    Point src, destination;
public:
    void run(map<int, set<int>> &convertedGraph);
    vector<Point> getPath(map<int, set<int>> &convertedGraph);
    Dijkstra(Point src,Point dst) {
        this->src = src;
        this->destination = dst;
    }
};