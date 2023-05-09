#include "Dijkstra.h"

void Dijkstra::run(map<int, set<int>> &convertedGraph) {
    int start = NodeConverter::axisToId(src.x, src.y, limitY);
    
    //Start Distance node is at 0(from myself to myself obviously 0)
    distance[start] = 0;
    pq.emplace(0, start);

    
    while (!pq.empty()) {
        int node, cost;
        tie(cost, node) = pq.top();
        pq.pop();

        //We pop the current max(ordered by the cost) , since we need the shortest path so we multiply it by -1
        cost *= -1;
        for (auto &to: convertedGraph[node]) {
            //Checking all the children of the popped node 
            //Add myself(cost) with the weight(Equation between 2 points in 2D Space) and check if the Distance at the child is
            //less or not .. If it is less than it so we update the cost and push the NEGATIVE of (cost+weight) to get the shortest path
            ll nCost = cost + Algorithm::dst(NodeConverter::idToAxis(node, limitY), NodeConverter::idToAxis(to, limitY));
            if (!distance.count(to) || nCost < distance[to]) {
                distance[to] = nCost;
                pq.emplace(-nCost, to);
                parent[to] = node;
            }
        }
    }
}

vector<Point> Dijkstra::getPath(map<int, set<int>> &convertedGraph) {
    vector<Point> fullPath;
    stack<Point> path;
    if (!distance.count(NodeConverter::axisToId(destination.x, destination.y, limitY))) {
        return {{oo, oo}};
    }

    fullPath.push_back({(int) distance[NodeConverter::axisToId(destination.x, destination.y, limitY)], oo});
    //continue getting the ID of the node you are going to(distance) until you find the source .. 
    while (!(destination.compare(src))) {
        path.push(destination);
        int currId = NodeConverter::axisToId(destination.x, destination.y, limitY);
        destination = NodeConverter::idToAxis(parent[currId], limitY);
    }
    //When found then add it to your path
    path.push(src);
    
    //Since its a stack .. LIFO so we get the path by pushing the nodes from start to destinaion
    //and we keep popping the stack until we get the destination at  the end and the path would be basically empty after that
    while (!path.empty()) {
        fullPath.push_back({path.top().x, path.top().y});
        path.pop();
    }
    return fullPath;
}
