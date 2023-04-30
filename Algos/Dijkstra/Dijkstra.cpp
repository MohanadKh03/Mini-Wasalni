#include "Dijkstra.h"

void Dijkstra::run(map<int, set<int>> &convertedGraph) {
    int start = tmp.axisToId(src.x, src.y, limitY);
    //
    distance[start].d = 0;
    pq.emplace(0, start);
    //
    while (!pq.empty()) {
        int node, d;
        tie(d, node) = pq.top();
        pq.pop();
        d *= -1;
        //
        for (auto &to: convertedGraph[node]) {
            ll nCost = d + dst(tmp.idToAxis(node, limitY), tmp.idToAxis(to, limitY));
            if (nCost < distance[to].d) {
                distance[to].d = nCost;
                pq.emplace(-nCost, to);
                parent[to] = node;
            }
        }
    }
}

void Dijkstra::getPath(map<int, set<int>> &convertedGraph) {
    if (distance[tmp.axisToId(ds.x, ds.y, limitY)].d == 1e18) {
        return;
    }
    //
    cout << "Path: " << distance[tmp.axisToId(ds.x, ds.y, limitY)].d << "\n";

    stack<Point>path;
    while (!(ds.compare(src))) {
        path.push(ds);
        //
        int currId = tmp.axisToId(ds.x, ds.y, limitY);
        ds = tmp.idToAxis(parent[currId], limitY);
    }
    //
    path.push(src);
    while (!path.empty()) {
        cout << "( " << path.top().x<< " - " << path.top().y <<" )" << "\n";
        path.pop();
    }
}
