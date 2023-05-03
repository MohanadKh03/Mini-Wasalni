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

vector<Point> Dijkstra::getPath(map<int, set<int>> &convertedGraph) {
    if (distance[tmp.axisToId(ds.x, ds.y, limitY)].d == 1e18) {
        return {{oo, oo}};
    }
    vector<Point> ret;
//    cout << "Path: " << distance[tmp.axisToId(ds.x, ds.y, limitY)].d << "\n";
    ret.push_back({(int) distance[tmp.axisToId(ds.x, ds.y, limitY)].d, oo});
    stack<Point> path;
    while (!(ds.compare(src))) {
        path.push(ds);
        //
        int currId = tmp.axisToId(ds.x, ds.y, limitY);
        ds = tmp.idToAxis(parent[currId], limitY);
    }
    //
    path.push(src);
    while (!path.empty()) {
        ret.push_back({path.top().x, path.top().y});
//        cout << "( " << path.top().x<< " - " << path.top().y <<" )" << "\n";
        path.pop();
    }
    return ret;
}
