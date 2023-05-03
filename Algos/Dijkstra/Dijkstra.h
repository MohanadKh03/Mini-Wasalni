#pragma once

#include "F:\DS MiniWaslni\Algos\algorithm.h"
class Dijkstra : public Algorithm
{
private:
    struct InfStruct {
        ll d = 1e18;
    };

    priority_queue<pair<ll,ll >>pq;
    map<ll,InfStruct>distance;
    map<ll, ll>parent;
    Point src, ds;
public:
    void run(map<int, set<int>> &convertedGraph);
    vector<Point> getPath(map<int, set<int>> &convertedGraph);
    Dijkstra(Point src,Point dst) {
        this->src = src;
        this->ds = dst;
    }
};