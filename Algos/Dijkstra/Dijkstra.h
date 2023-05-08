#pragma once

#include "../algorithm.h"
class Dijkstra : public Algorithm
{
private:
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