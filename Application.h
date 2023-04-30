#pragma once

#include <iostream>
#include <vector>
#include "C:\Users\amoha\CLionProjects\untitled5\Algos\Algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
#include "C:\Users\amoha\CLionProjects\untitled5\Resources\Point.h"
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