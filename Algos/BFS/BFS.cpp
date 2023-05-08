#include "BFS.h"

void BFS::run(map<int, set<int>> &convertedGraph) {
    int source = tmp.axisToId(src.x, src.y, limitY);
    //
    distance[source] = 0;
    q.push({source, 0});
    //
    while (!q.empty()) {
        int node, cost;
        node = q.front().ID;
        cost = q.front().onPath;

        q.pop();
        //
        if (cost) {
            q.push({node, cost - 1});
        } else {
            if (vis[node])continue;
            vis[node] = true;
            //
            for (auto to: convertedGraph[node]) {
                ll on = dst(tmp.idToAxis(node, limitY), tmp.idToAxis(to, limitY));
                ll nCost = distance[node] + on;
                if(!distance.count(to) || nCost < distance[to]){
                    distance[to] = nCost;
                    q.push({to, on - 1});
                    parent[to] = node;
                }
            }
        }
    }
}

vector<Point> BFS::getPath(map<int, set<int>> &convertedGraph) {
    vector<Point> finalPath;

    if (!distance.count(tmp.axisToId(destination.x, destination.y, limitY))) {
        return{{oo,oo}};
    }

    finalPath.push_back({(int)distance[tmp.axisToId(destination.x, destination.y, limitY)],oo});
    stack<Point> path;
    while (!(destination.compare(src))) {
        path.push(destination);
        destination = tmp.idToAxis(parent[tmp.axisToId(destination.x, destination.y, limitY)], limitY);
    }

    path.push(src);
    while (!path.empty()) {
        finalPath.push_back({path.top().x, path.top().y});
        path.pop();
    }
    return finalPath;
}
