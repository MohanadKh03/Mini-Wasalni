#include <iostream>
#include "App.h"
using namespace std;



int main(){
    Application app;
    app.start();
    Algorithm* algo;
    int option = 1;
    if(option == 1)
        algo = new BFS();
    else
        algo = new DFS();
    return 0;
}