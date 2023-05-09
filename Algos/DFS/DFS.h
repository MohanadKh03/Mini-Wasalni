#pragma once

#include "../algorithm.h"
class DFS : public Algorithm{
private:
    vector<ll>currPath, path;
    ll ans;
    map<ll, bool> vis;

    //helper for the algorithm run
    void run(map<int,set<int>>&convertedGraph,int parID, ll curWeight);
public:
    void run(map<int,set<int>>&convertedGraph);
    vector<Point> getPath(map<int,set<int>>&convertedGraph);
    DFS(Point src,Point destination){
        this->src = src;
        this->destination = destination;
        this->ans=1e18;
    }
};