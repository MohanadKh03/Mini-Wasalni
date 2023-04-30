#pragma once

#include <iostream>
#include <vector>
#include "/home/mohanadkhaled/Mini-Wasalni/Mini-Wasalni/Algos/Algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
using namespace std;

class Application
{
    
    void navigateMenu();
    void editMenu();
    void algorithmTypes();
    
    Map map;
    vector<Algorithm*>algos;
public:
    Application();
    void start();
    ~Application();
};