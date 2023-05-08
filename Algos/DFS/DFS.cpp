#include "DFS.h"

void DFS::run(map<int, set<int>> &convertedGraph) {
    this->run(convertedGraph,tmp.axisToId(this->src.x,this->src.y,limitY), 0);
}

ll DFS::run(map<int, set<int>> &convertedGraph, int parID, ll curWeight) {
    ll destinationId = tmp.axisToId(destination.x, destination.y, limitY);
    currPath.push_back(parID);
    if(parID==destinationId and curWeight<ans){
        ans=curWeight;
        path=currPath;
    }
    for(auto child:convertedGraph[parID])if(!vis[child]){
        vis[child]=true;
        ll distance = dst(tmp.idToAxis(parID, limitY), tmp.idToAxis(child, limitY));
        run(convertedGraph, child, distance+curWeight);
        vis[child]=false;
    }
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
        fullPath.push_back(tmp.idToAxis(i, limitY));
    }
    return fullPath;
}
