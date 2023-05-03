#pragma once

#include <iostream>
#include <vector>
#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Algos\Algorithm.h"
#include "Algos/BFS/BFS.cpp"
#include "Algos/DFS/DFS.cpp"
#include "Algos/Dijkstra/Dijkstra.cpp"
#include "Algos/Floyd/Floyd.cpp"
#include "Map.cpp"
#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Resources\NodeConverter.h"
#include "C:\Users\amoha\Downloads\Compressed\Mini-Wasalni-main\Mini-Wasalni-main\Resources\Point.h"
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