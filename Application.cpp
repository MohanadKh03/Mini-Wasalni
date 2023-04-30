#include "Application.h"

Application::Application() {
    cout << "Application constructor\n";
}

void Application::start() {
    int startChoice;
    while (true) {
        system("CLS");
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
    do {
        system("CLS");
        map.displayMap();
        cout << "-----------------------------------------\n";
        string city1, city2;
        cout << "Enter source and destination cities: ";
        cin >> city1 >> city2;
        algorithmTypes(city1, city2);
        cout << "1.Choose another two cities\n";
        cout << "2.back\n";
        cin >> choice;
    } while (choice == 1);
}

void Application::editMenu() {
    int choice;
    while (true) {
        system("CLS");
        cout << "1: add city\n";
        cout << "2: delete city\n";
        cout << "3: add edge\n";
        cout << "4: delete edge\n";
        cout << "5: display map\n";
        cout << "6: exit\n";
        cin >> choice;
        if (choice == 1)
            map.addCity();
        else if (choice == 2)
            map.deleteCity();
        else if (choice == 3)
            map.addEdge();
        else if (choice == 4)
            map.deleteEdge();
        else if (choice == 5)
            map.displayMap();
        else if (choice == 6)
            break;
        else
            cout << "Enter a valid number(1:6)\n";
    }
}

void Application::algorithmTypes(string city1, string city2) {
    if(city1==city2){
        cout<<"0\n";
        return;
    }
    int algorithm;
    std::map<int, set<int>> convertedGraph = map.getConvertedGraph();
    auto graph = map.getGraph();
    Floyd* floyd = new Floyd();
    floyd->build(convertedGraph);
    floyd->run(convertedGraph);
    while (true) {
        cout << "1.BFS\n";
        cout << "2.DFS\n";
        cout << "3.Dijkstra\n";
        cout << "4.Floyd\n";
        cout << "5.back\n";
        cin >> algorithm;
        system("CLS");
        if (algorithm == 5)
            break;
        else if (algorithm < 1 || algorithm > 4)
            cout << "Enter a valid number(1:5)\n";
        else {

            Point p1, p2;
            p1.x = graph[city1]->point.x;
            p1.y = graph[city1]->point.y;

            p2.x = graph[city2]->point.x;
            p2.y = graph[city2]->point.y;

            switch (algorithm) {
                case 1:
                    algo = new BFS(p1, p2);
                    break;
                case 2:
                    algo = new DFS(p1, p2);
                    break;
                case 3:
                    algo = new Dijkstra(p1,p2);
                    break;
                case 4:
                    floyd->setPoints(p1,p2);
                    floyd->getPath(convertedGraph);
                    break;
            }
           if(algorithm!=4) {
               algo->run(convertedGraph);
               algo->getPath(convertedGraph);
           }
        }
    }
}

Application::~Application() {

}
