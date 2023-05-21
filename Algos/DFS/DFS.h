
#ifndef DFS_H
#define DFS_H
#pragma once
#include "../algorithm.h"
class DFS : public Algorithm{
private:
    vector<ll>currPath, path;
    ll ans;
    map<ll, bool> vis;
public:
    void run(map<int,set<int>>&convertedGraph, int srcId,ll  destinationId, ll  curWeight);
    void run(map<int,set<int>>&convertedGraph);
    vector<Point> getPath(map<int,set<int>>&convertedGraph);
    DFS(Point src,Point destination){
        this->src = src;
        this->destination = destination;
        this->ans=1e18;
    }

};

#endif // DFS_H