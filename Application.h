#pragma once

#include <iostream>
#include <vector>
#include "Algos/algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
#include "Resources/Point.h"
#include "Resources/NodeConverter.h"
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