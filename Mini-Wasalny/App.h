#include "Map.h"
#include <iostream>
using namespace std;

class Application
{
    int mainMenu();
    void displayMap();
    void chooseCities();
    void algorithmTypes();
    void dfs();
    void bfs();
    void dijkstra();

public:
    Application();
    void start();
    ~Application();
};