#include "Dijkstra.h"

void Dijkstra::run(map<int, set<int>> &convertedGraph) {
    int start = tmp.axisToId(src.x, src.y, limitY);
    //
    distance[start] = 0;
    pq.emplace(0, start);
    //
    while (!pq.empty()) {
        int node, cost;
        tie(cost, node) = pq.top();
        pq.pop();
        cost *= -1;
        //
        for (auto &to: convertedGraph[node]) {
            ll nCost = cost + dst(tmp.idToAxis(node, limitY), tmp.idToAxis(to, limitY));
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
    if (!distance.count(tmp.axisToId(destination.x, destination.y, limitY))) {
        return {{oo, oo}};
    }

    fullPath.push_back({(int) distance[tmp.axisToId(destination.x, destination.y, limitY)], oo});
    while (!(destination.compare(src))) {
        path.push(destination);
        int currId = tmp.axisToId(destination.x, destination.y, limitY);
        destination = tmp.idToAxis(parent[currId], limitY);
    }
    path.push(src);
    
    while (!path.empty()) {
        fullPath.push_back({path.top().x, path.top().y});
        path.pop();
    }
    return fullPath;
}
