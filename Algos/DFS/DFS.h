#pragma once

#include "/home/mohanadkhaled/Mini-Wasalni/Mini-Wasalni/Algos/Algorithm.h"

class DFS : public Algorithm{
    void run(map<int,set<int>>&convertedGraph);
    void getPath(map<int,set<int>>&convertedGraph);
};