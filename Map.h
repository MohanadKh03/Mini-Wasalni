#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
using namespace std;

struct Point{
    int x,y;
    bool compare(Point &tmp) {
        return (tmp.x == this->x && tmp.y == this->y);
    }
};

class Map{
    const int limitY = 15;

    class Node {
    public:
        Point point;
        Node(string name, int x, int y) {
            this->name = name;
            this->point.x = x;
            this->point.y = y;
        }
        int id;
        string name;
        map<string, int> edges; // {to , distance }
    };
    map<string,Node*>graph;
    map<int,set<int>>convertedGraph;

    class NodeConverter {
    public:
        Point idToAxis(int id,int m) {
            int x = id / m + (id % m != 0);
            int y = (id % m);
            if (id % m == 0)y += m;
            return { x,y };
        }
        //
        int axisToId(int x, int y,int m) {
            return(x - 1) * m + y;
        }
        //
    }tmp;
public: 
    Map();

    void addCity();
    void deleteCity();
    void addEdge();
    void deleteEdge();
    void deleteMap();
    void displayMap();

    map<int,set<int>> getConvertedGraph(){
        return convertedGraph;
    }

    ~Map();
};