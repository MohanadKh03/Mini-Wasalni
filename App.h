#include "Map.h"
#include <iostream>
#include <array>
using namespace std;

class Application
{
    void navigateMenu();
    void editMenu();

    void algorithmTypes();

    //void dfs();
    //void bfs();
    //void dijkstra();

    Algorithm* algorithms[4];//0 BFS , 1 DFS , 2 Dijkstra , 3 Floyd 
    Map map;
public:

    Application();
    void start();
    ~Application();
};