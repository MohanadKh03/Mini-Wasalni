#pragma once

#include <iostream>
#define ll long long
using namespace std;

#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Resources\Point.h"
#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Resources\NodeConverter.h"
#include <cmath>

class Algorithm{
protected:
    NodeConverter tmp;
    Point src,ds;
    long long dst(Point p1, Point p2) {
        return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
public:
    virtual void run(map<int,set<int>>&convertedGraph) = 0;
    virtual vector<Point> getPath(map<int,set<int>>&convertedGraph) = 0;
};