#pragma once

#include "F:\DS MiniWaslni\Algos\algorithm.h"
class Floyd : public Algorithm
{
private:
    struct InfStruct {
        ll d = 1e18;
    };
    Point src, ds;
    map<pair<int, int>, InfStruct>dp;
    map<pair<ll,ll>, InfStruct>path;
public:
    void run(map<int, set<int>> &convertedGraph);
    vector<Point> getPath(map<int, set<int>> &convertedGraph);
    void build(map<int, set<int>> &convertedGraph);
    void setPoints(Point src, Point dst);
};