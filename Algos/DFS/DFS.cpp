#include "DFS.h"

void DFS::run(map<int, set<int>> &convertedGraph) {
    //start the helper with the source coordinates
    this->run(convertedGraph,NodeConverter::axisToId(this->src.x,this->src.y,limitY), 0);
}

void DFS::run(map<int, set<int>> &convertedGraph, int parID, ll curWeight) {
    ll destinationId = NodeConverter::axisToId(destination.x, destination.y, limitY);
    
    currPath.push_back(parID);
    //When the current node we are at is the destination node
    //check whether the total weight is less than the answer of
    //the algorithm or not .. if true then this is the current shortest path AND we assign the "currPath" vector as our path answer
    if(parID==destinationId and curWeight<ans){
        ans=curWeight;
        path=currPath;
    }
    
    //We check the children nodes 
    //If not visited then mark as visited and go run the algorithm again but with the child coordinates
    //DONT forget to unmark the visited after the recursion is over
    for(auto child:convertedGraph[parID])if(!vis[child]){
        vis[child]=true;
        ll distance = Algorithm::dst(NodeConverter::idToAxis(parID, limitY), NodeConverter::idToAxis(child, limitY));
        run(convertedGraph, child, distance+curWeight);
        vis[child]=false;
    }
    //Backtracking the node we pushed earlier
    currPath.pop_back();
}

vector<Point> DFS::getPath(map<int, set<int>> &convertedGraph) {
    vector<Point> fullPath;
    if(ans == 1e18){
        return {{oo, oo}};
    }
    ll distance = 0;
    for(int i = 0; i < path.size() - 1; i++){
        distance += dst(tmp.idToAxis(path[i], limitY), tmp.idToAxis(path[i + 1], limitY));
    }
    fullPath.push_back({(int)distance, oo});
    for(auto i : path){
        fullPath.push_back(NodeConverter::idToAxis(i, limitY));
    }
    return fullPath;
}
