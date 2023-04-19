#pragma once

#include <iostream>
#include <vector>
#include "Algorithm.h"
#include "BFS.cpp"
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