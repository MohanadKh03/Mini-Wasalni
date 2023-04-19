#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Map{
        class Node {
            struct Point {
                int x, y;
            }point;
        public:
            Node(string name, int x, int y) {
                this->name = name;
                this->point.x = x;
                this->point.y = y;
            }
            string name;
            //map<string, pair<int, bool>> edges; // {to , {distance,directed/undirected} }
        };
        //Node a = new Node();
        //Node = new Node.. 
        //Node
        //graph.push_back(node)
        //
        map<string,Node>graph;
        //map<string,vector<Node*>>graph;
public: 
    Map();

    void addCity();
    void deleteCity();
    void addEdge();
    void deleteEdge();
    void deleteMap();
    void displayMap();

    ~Map();
};