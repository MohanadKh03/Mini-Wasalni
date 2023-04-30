#pragma once

#include <iostream>
#include <vector>
#include "/home/mohanadkhaled/Mini-Wasalni/Mini-Wasalni/Algos/Algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
#include "/home/mohanadkhaled/Mini-Wasalni/Mini-Wasalni/Resources/Point.h"
using namespace std;

class Application
{
    
    void navigateMenu();
    void editMenu();
    void algorithmTypes(string,string);
    
    Map map;
    Algorithm* algo;
public:
    Application();
    void start();
    ~Application();
};