#pragma once

#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Algos\Algorithm.h"

class DFS : public Algorithm{
private:
    struct InfStruct {
        ll d = -1;
    };
    Point src, ds;
    map<ll,ll>path;
    map<ll, InfStruct>dp;
public:
    ll run(map<int,set<int>>&convertedGraph,int parID);
    void run(map<int,set<int>>&convertedGraph);
    vector<Point> getPath(map<int,set<int>>&convertedGraph);
    DFS(Point src,Point ds){
        this->src = src;
        this->ds = ds;
    }
};