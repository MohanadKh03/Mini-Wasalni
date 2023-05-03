#include "Map.h"

Map::Map() {
    ifstream citiesFile("cities.txt");
    ifstream edgesFile("edges.txt");
    string name, neighborName;
    int x, y, size, weight;
    while (citiesFile >> name >> x >> y) {
        Node *newCity = new Node(name, x, y);
        graph[name] = newCity;

        int id = tmp.axisToId(x, y, limitY);
        newCity->id = id;

        convertedGraph[id];
        IdToName[id] = name;
    }
    while (edgesFile >> name >> size) {
        int id = tmp.axisToId(graph[name]->point.x, graph[name]->point.y, limitY);
        for (int i = 0; i < size; ++i) {
            edgesFile >> neighborName >> weight;
            int neighourId = tmp.axisToId(graph[neighborName]->point.x, graph[neighborName]->point.y, limitY);

            convertedGraph[id].insert(neighourId);
            convertedGraph[neighourId].insert(id);

            graph[name]->edges[neighborName] = weight;
            graph[neighborName]->edges[name] = weight;
        }
    }
}

void Map::addCity() {
    string city;
    int x, y;
    cout << "Enter city name , position(x,y)\n";
    cin >> city >> x >> y;
    if (graph[city]) {
        cout << "city already exists \n";
        return;
    }
    Node *newNode = new Node(city, x, y);
    graph[city] = newNode;

    int id = tmp.axisToId(graph[city]->point.x, graph[city]->point.y, limitY);
    newNode->id = id;

    convertedGraph[id];
    IdToName[id] = city;
}

void Map::deleteCity() {
    string city;
    cout << "Enter city \t";
    cin >> city;
    if (!graph[city]) {
        cout << "city doesn't exist mother father\n";
        return;
    }
    for (auto &edge: graph[city]->edges) {
        graph[edge.first]->edges.erase(city);
    }
    graph.erase(city);

    int id = tmp.axisToId(graph[city]->point.x, graph[city]->point.y, limitY);
    //
    for (auto it: convertedGraph[id]) {
        convertedGraph[it].erase(id);
    }
    convertedGraph[id].clear();
    convertedGraph.erase(id);
    IdToName.erase(id);

}

void Map::addEdge() {
    string city1, city2;
    bool isDirected;
    cout << "Enter city1,city2 names\n";
    cin >> city1 >> city2;
    if (!graph[city1] || !graph[city2]) {
        cout << "City does not exist\n";
        return;
    }
    int distance = (int) sqrt(pow((graph[city1]->point.x - graph[city2]->point.x), 2) +
                              pow((graph[city1]->point.y - graph[city2]->point.y), 2));
    graph[city1]->edges[city2] = distance;
    graph[city2]->edges[city1] = distance;


    //Converter
    int id1 = tmp.axisToId(graph[city1]->point.x, graph[city1]->point.y, limitY);
    int id2 = tmp.axisToId(graph[city2]->point.x, graph[city2]->point.y, limitY);
    //
    convertedGraph[id1].insert(id2); //
    ///./////
    convertedGraph[id2].insert(id1); //

}

void Map::deleteEdge() {
    cout << "Enter cities name \n";
    string city1, city2;
    cin >> city1 >> city2;
    if (!graph[city1] || !graph[city2]) {
        cout << "one of cities doesn't exist\n";
        return;
    }
    //delete both ways cuz undirected
    graph[city1]->edges.erase(city2);
    graph[city2]->edges.erase(city1);

    int id1 = tmp.axisToId(graph[city1]->point.x, graph[city1]->point.y, limitY);
    int id2 = tmp.axisToId(graph[city2]->point.x, graph[city2]->point.y, limitY);
    //
    if (convertedGraph[id1].find(id2) != convertedGraph[id1].end()) {
        convertedGraph[id1].erase(id2);
        convertedGraph[id2].erase(id1);
    }

}

void Map::displayMap() {
    for (auto &node: graph) {
        cout << node.first << endl;
        for (auto &edge: graph[node.first]->edges)
            cout << edge.first << " " << edge.second << endl;
        cout << "------------------------------------------------------------------------------\n";
    }
    cout << "CONVERTED: \n";
    for (auto &i: convertedGraph) {
        cout << "[ " << i.first << " ]: ";
        for (auto &j: i.second) {
            cout << j << ", ";
        }
        cout << "\n";
    }
    cout << "END CONVERTED: \n";
}

void Map::deleteMap() {
    cout << "Map Deleted\n";
    for (auto &node: graph) {
        delete node.second;
    }
    //have to delete the pointers of each node first then clear
    graph.clear();
}

Map::~Map() {
    ofstream citiesFile("cities.txt");
    ofstream edgesFile("edges.txt");
    for (auto &city: graph) {
        citiesFile << city.second->name << ' ' << city.second->point.x << ' ' << city.second->point.y << endl;

        edgesFile << city.first << ' ' << city.second->edges.size() << endl;
        for (auto &edge: city.second->edges) {
            edgesFile << edge.first << ' ' << edge.second << endl;
        }
    }
    deleteMap();
}