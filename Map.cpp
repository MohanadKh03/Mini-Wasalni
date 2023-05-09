#include "Map.h"

Map::Map() {
    ifstream citiesFile("cities.txt");
    ifstream edgesFile("edges.txt");
    string name, neighborName;
    int x, y, size, weight;
    while (citiesFile >> name >> x >> y) {
        Node *newCity = new Node(name, x, y);
        graph[name] = newCity;

        int id = NodeConverter::axisToId(x, y, limitY);
        newCity->id = id;

        convertedGraph[id];
        IdToName[id] = name;
    }
    while (edgesFile >> name >> size) {
        int id = NodeConverter::axisToId(graph[name]->point.x, graph[name]->point.y, limitY);
        for (int i = 0; i < size; ++i) {
            edgesFile >> neighborName >> weight;
            int neighourId = NodeConverter::axisToId(graph[neighborName]->point.x, graph[neighborName]->point.y, limitY);

            graph[name]->edges[neighborName] = weight;
            convertedGraph[id].insert(neighourId);

        }
    }
}

void Map::addCity() {
    string city;
    int x, y;
    cout << "Enter city name , position(x,y)\n";
    cin >> city >> x >> y;
    if (graph[city]) {
        cout << "City already exists \n";
        return;
    }
    Node *newNode = new Node(city, x, y);
    graph[city] = newNode;

    int id = NodeConverter::axisToId(graph[city]->point.x, graph[city]->point.y, limitY);
    newNode->id = id;

    convertedGraph[id];
    IdToName[id] = city;
}

void Map::deleteCity() {
    string city;
    cout << "Enter city \t";
    cin >> city;
    if (!graph[city]) {
        cout << "City doesn't exist \n";
        return;
    }
    //deleting all edges that go to our city
    for (auto &edge: graph[city]->edges) {
        graph[edge.first]->edges.erase(city);
    }

    graph.erase(city);

    int id = NodeConverter::axisToId(graph[city]->point.x, graph[city]->point.y, limitY);
    
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
    cout << "Enter city1(from),city2(to) names\n";
    cin >> city1 >> city2;
    if (!graph[city1] || !graph[city2]) {
        cout << "City does not exist\n";
        return;
    }
    do{
        cout << "Directed or Undirected ?(1,0): ";
        cin >> isDirected;
    }while(isDirected != 1);
    int distance = (int) sqrt(pow((graph[city1]->point.x - graph[city2]->point.x), 2) +
                              pow((graph[city1]->point.y - graph[city2]->point.y), 2));
    graph[city1]->edges[city2] = distance;
    if(isDirected)
        graph[city2]->edges[city1] = distance;

    //Converter
    int id1 = NodeConverter::axisToId(graph[city1]->point.x, graph[city1]->point.y, limitY);
    int id2 = NodeConverter::axisToId(graph[city2]->point.x, graph[city2]->point.y, limitY);
    //
    convertedGraph[id1].insert(id2); //
    ///./////
    if(isDirected)
        convertedGraph[id2].insert(id1); //

}


//Deleting edge FROM and TO .. cant delete both ways at once .. if undirected you must call it two times
void Map::deleteEdge() {
    cout << "Enter cities name(from,to) \n";
    string city1, city2;
    cin >> city1 >> city2;
    if (!graph[city1] || !graph[city2]) {
        cout << "one of cities doesn't exist\n";
        return;
    }

    int id1 = NodeConverter::axisToId(graph[city1]->point.x, graph[city1]->point.y, limitY);
    int id2 = NodeConverter::axisToId(graph[city2]->point.x, graph[city2]->point.y, limitY);

    if(graph[city1]->edges.find(city2) != graph[city1]->edges.end()){
        graph[city1]->edges.erase(city2);
        convertedGraph[id1].erase(id2);
    }
    else
        cout << "No edge from " << city1 << " to " << city2 << endl;
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