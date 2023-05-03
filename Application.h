#pragma once

#include <iostream>
#include <vector>
#include "F:\DS MiniWaslni\Algos\algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
#include "F:\DS MiniWaslni\Resources\NodeConverter.h"
#include "F:\DS MiniWaslni\Resources\Point.h"
using namespace std;

class Application
{
    
    void navigateMenu();
    void editMenu();
    void algorithmTypes(string,string);
    
    Map map;
    Algorithm* algo;
public:
    void start();
};