#include "App.h"


void Application::algorithmTypes()
{
    algorithms[0] = new BFS();
    algorithms[1] = new DFS();
    //algorithms[2] = new Dijkstra();
    //algorithms[3] = new Floyd();
    int algorithm;
    while(true){
        cout << "1.BFS\n";
        cout << "2.DFS\n";
        cout << "3.Dijkstra\n";
        cout << "4.Floyd\n";
        cout << "4.back\n";
        cin >> algorithm;
        if(algorithm < 1 || algorithm > 3)
            cout << "Enter a valid number(1:4)\n";
        else if(algorithm == 4)
            break;
        else
            algorithms[algorithm-1]->run();
    }
}


void Application::navigateMenu()
{
    int choice;
    do{
        map.displayMap();
        cout << "-----------------------------------------\n";
        string city1,city2;
        cout << "Enter source and destination cities: ";
        cin >> city1 >> city2;

        algorithmTypes();
        cout << "1.Choose another two cities\n";
        cout << "2.back\n";
        cin >> choice;
    }while(choice == 1);
}
void Application::editMenu()
{
    int choice;
    while(true){
        cout << "1: add city\n";
        cout << "2: delete city\n";
        cout << "3: add edge\n";
        cout << "4: delete edge\n";
        cout << "5: display map\n";
        cout << "6: exit\n";
        cin >> choice;
        if(choice == 1)
            map.addCity();
        else if(choice == 2)
            map.deleteCity();
        else if(choice == 3)
            map.addEdge();
        else if(choice == 4)
            map.deleteEdge();
        else if(choice == 5)
            map.displayMap();
        else if(choice == 6)
            break;
        else
            cout << "Enter a valid number(1:6)\n";
    }
}

Application::Application()
{
    
}

void Application::start()
{
    int startChoice;
    while(true){
        cout << "Mini-Wasalny\n";
        cout << "------------------------------------------\n";
        cout << "1.Navigate Map\n";
        cout << "2.Edit Map\n";
        cout << "3.exit\n";
        cin >> startChoice;
        if(startChoice == 1)
            navigateMenu();
        else if(startChoice == 2)
            editMenu();
        else if(startChoice == 3)
            break;
        else
            cout << "Enter a valid number(1:3)\n";
    }
}
