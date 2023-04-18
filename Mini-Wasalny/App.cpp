#include "App.h"
//commit
int Application::mainMenu()
{
    int choice;
    cout << "Mini-Wasalny\n";
    cout << "------------------------------------------\n";
    cout << "1.Navigate Map\n";
    cout << "2.Create Map\n";
    cout << "3.exit\n";
    cin >> choice;
    return choice;
}

void Application::chooseCities()
{
    displayMap();

    cout << "-----------------------------------------\n";
    string city1,city2;
    cout << "Enter source and destination cities: ";
    cin >> city1 >> city2;

    algorithmTypes();

    cout << "";
}

void Application::algorithmTypes()
{
    int algorithm;
    while(true){
        cout << "1.BFS\n";
        cout << "2.DFS\n";
        cout << "3.Dijkstra\n";
        cout << "4.exit\n";
        cin >> algorithm;
        if(algorithm == 1)
            dfs();
        else if(algorithm == 2)
            bfs();
        else if(algorithm == 3)
            dijkstra();
        else if(algorithm == 4)
            break;
        else
            cout << "Enter a valid number(1:4)\n";
    }
}

void Application::start()
{
    int startChoice;
    do{
        startChoice = mainMenu();
        if(startChoice == 1)
            chooseCities();
        if(startChoice == 2)

    }while(startChoice != 3);
    
}
