#pragma once

#include "../algorithm.h"
class Floyd : public Algorithm
{
private:
    struct InfStruct {
        ll value = 1e18;
    };
    Point src, destination;
    map<pair<int, int>, InfStruct>dp;
    map<pair<ll,ll>, InfStruct>path;
public:
    void run(map<int, set<int>> &convertedGraph);
    vector<Point> getPath(map<int, set<int>> &convertedGraph);
    void build(map<int, set<int>> &convertedGraph);
    void setPoints(Point src, Point dst);
};