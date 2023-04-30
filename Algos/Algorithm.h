#pragma once

#include <iostream>
using namespace std;

#include <map>
#include <set>

class Algorithm{
public:
    virtual void run(map<int,set<int>>&convertedGraph) = 0;
    virtual void getPath(map<int,set<int>>&convertedGraph) = 0;
};