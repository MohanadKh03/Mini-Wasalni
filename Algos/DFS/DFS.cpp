
#include "DFS.h"

//helper fun
void DFS::run(map<int, set<int>> &convertedGraph) {
    // Hash destination{x, y} to destinationId
    ll destinationId = NodeConverter::axisToId(destination.x, destination.y, limitY);

    // Hash source {x, y} to sourceId
    int srcId = NodeConverter::axisToId(src.x, src.y, limitY);

    this->run(convertedGraph, srcId, destinationId, 0ll);
}

void DFS::run(map<int, set<int>> &convertedGraph, int srcId, ll destinationId, ll curWeight) {

    // take node while i dive into graph
    currPath.push_back(srcId);

    //When arrive to destinationId
    //check whether the weight in this path is less than before
    if(srcId == destinationId and curWeight < ans){
        ans=curWeight;
        path=currPath;
    }

    // iterate over all children of current node
    for(auto child:convertedGraph[srcId])if(!vis[child]){
            vis[child]=true;
            // turn node to Point {x, y}
            Point srcPoint = NodeConverter::idToAxis(srcId, limitY);
            Point childPoint = NodeConverter::idToAxis(child, limitY);
            // calculate distance between src and child
            ll distance = Algorithm::dst(srcPoint, childPoint);
            run(convertedGraph, child, destinationId, distance+curWeight);
            vis[child]=false;
        }
    //Backtracking the node we pushed earlier
    currPath.pop_back();
}

/*

          X <- destination
          *
     1    * 2
  * * * * *
1 *       * 5
  *       *
  * * * * O <- src
     1
 */

vector<Point> DFS::getPath(map<int, set<int>> &convertedGraph) {

    // first point in this vector is weight of path
    vector<Point> fullPath;

    // if there is no path return infinity weight in first point
    if(ans == 1e18){
        return {{oo, oo}};
    }
    fullPath.push_back({(int)ans, oo});
    for(auto i : path){
        // convert nodes of path to Point
        fullPath.push_back(NodeConverter::idToAxis(i, limitY));
    }
    return fullPath;
}

