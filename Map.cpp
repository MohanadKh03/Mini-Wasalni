#include "Map.h"

Map::Map(){
    cout << "Map ctr\n";
}

void Map::addCity()
{
    cout << "City Added\n";
}
void Map::deleteCity(){
    cout << "City Deleted\n";
}
void Map::addEdge(){
    cout << "Edge Added\n";
}
void Map::deleteEdge(){
    cout << "Edge Deleted\n";
}

//void deleteMap();

void Map::displayMap(){
    cout << "Display Map\n";
}

void Map::deleteMap()
{
    cout << "Map Deleted\n";
}

Map::~Map(){
    cout << "Map dtr\n";
}