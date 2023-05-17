#include "Application.h"

#define oo INT32_MAX



void Application::start() {
    int startChoice;
    while (true) {
        system("clear");
        cout << "Mini-Wasalny\n";
        cout << "------------------------------------------\n";
        cout << "1.Navigate Map\n";
        cout << "2.Edit Map\n";
        cout << "3.exit\n";
        cin >> startChoice;
        if (startChoice == 1)
            navigateMenu();
        else if (startChoice == 2)
            editMenu();
        else if (startChoice == 3)
            break;
        else
            cout << "Enter a valid number(1:3)\n";
    }
}

void Application::navigateMenu() {
    int choice;
    bool firstTime = true;
    do {
        string city1, city2;
        choice = 1;
        if(firstTime){
            system("clear");
            map.displayMap();
            cout << "-----------------------------------------\n";
            cout << "Enter source and destination cities: ";
        } else {
            cout << "Cities not found in map. Enter correct ones: ";
        }
        cin >> city1 >> city2;
        if(map.getGraph()[city1] == NULL || !map.getGraph()[city2]){
            firstTime = false;
            continue;
        }
        algorithmTypes(city1, city2);
        cout << "1.Choose another two cities\n";
        cout << "2.back\n";
        cin >> choice;
        if(choice == 1) firstTime = true;
    } while (choice == 1);
}

void Application::editMenu() {
    int choice;
    while (true) {
        cout << "1: add city\n";
        cout << "2: delete city\n";
        cout << "3: add edge\n";
        cout << "4: delete edge\n";
        cout << "5: exit\n";
        cin >> choice;
        system("clear");
        map.displayMap();
        if (choice == 1)
            map.addCity();
        else if (choice == 2)
            map.deleteCity();
        else if (choice == 3)
            map.addEdge();
        else if (choice == 4)
            map.deleteEdge();
        else if (choice == 5)
            break;
        else
            cout << "Enter a valid number(1:5)\n";
    }
}

void Application::algorithmTypes(string city1, string city2) {
    if (city1 == city2) {
        cout << "0\n";
        return;
    }
    //get all the graphs info 
    auto convertedGraph = map.getConvertedGraph();
    auto IdToName = map.getIdToName();
    auto graph = map.getGraph();

    //floyd is a special algorithm so we need to build it and run it first in order to 
    //use it to its full capacity and get the result later and not compute it every time cuz it runs in
    //O(n^3)
    Floyd *floyd = new Floyd();
    floyd->build(convertedGraph);
    floyd->run(convertedGraph);

    int algorithm;
    while (true) {
        vector<Point> path;
        cout << "1.BFS\n";
        cout << "2.DFS\n";
        cout << "3.Dijkstra\n";
        cout << "4.Floyd\n";
        cout << "5.back\n";
        cin >> algorithm;
        system("clear");
        if (algorithm == 5)
            break;
        if (algorithm < 1 || algorithm > 4) {
            cout << "Enter a valid number(1:5)\n";
            continue;
        }
        Point p1, p2;
        p1.x = graph[city1]->point.x;
        p1.y = graph[city1]->point.y;

        p2.x = graph[city2]->point.x;
        p2.y = graph[city2]->point.y;

        switch (algorithm) {
            case 1:
                algo = new BFS(p1, p2);
                algo->run(convertedGraph);
                path = algo->getPath(convertedGraph);
                break;
            case 2:
                algo = new DFS(p1, p2);
                algo->run(convertedGraph);
                path = algo->getPath(convertedGraph);
                break;
            case 3:
                algo = new Dijkstra(p1, p2);
                algo->run(convertedGraph);
                path = algo->getPath(convertedGraph);
                break;
            case 4:
                floyd->setPoints(p1, p2);
                path = floyd->getPath(convertedGraph);
                break;
            default:
                break;
        }
        if (path.front().x == oo and path.front().y == oo) {
            cout << "there is no path between those destinations\n";
            continue;
        }

        cout << "path cost is : " << path.front().x << "\n";
        for (int i = 1; i < path.size(); ++i) {
            auto cityId = NodeConverter::axisToId(path[i].x, path[i].y, limitY);
            cout << IdToName[cityId] << ' ';
            cout << path[i].x << " " << path[i].y << "\n";
        }
    }
}

