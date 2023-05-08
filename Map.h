#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
using namespace std;
#include "Resources/Point.h"
#include "Resources/NodeConverter.h"

class Map{

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
    map<int,string> IdToName;

    NodeConverter tmp;
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
    map<int,string >getIdToName(){
        return IdToName;
    }
    map<string,Node*> getGraph(){
        return graph;
    }
    ~Map();
};