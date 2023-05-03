#include "BFS.h"

void BFS::run(map<int, set<int>> &convertedGraph) {
    int start = tmp.axisToId(src.x, src.y, limitY);
    //
    distance[start].d = 0;
    q.push({start, 0});
    //vis[start] = 1;
    //
    while (!q.empty()) {
        int node, w;
        node = q.front().ID;
        w = q.front().onPath;

        q.pop();
        //
        if (w) {
            q.push({node, w - 1});
        } else {
            if (vis[node])continue;
            vis[node] = true;
            //
            for (auto &to: convertedGraph[node]) {
                ll on = dst(tmp.idToAxis(node, limitY), tmp.idToAxis(to, limitY));
                ll nCost = distance[node].d + on;
                if (nCost < distance[to].d) {
                    distance[to].d = nCost;
                    q.push({to, on - 1});
                    parent[to] = node;
                }
            }
        }
    }
}

vector<Point> BFS::getPath(map<int, set<int>> &convertedGraph) {
    vector<Point> ret;

    if (distance[tmp.axisToId(ds.x, ds.y, limitY)].d ==(ll)1e18) {
        return{{oo,oo}};
    }
    //
//    cout << "Path: " << distance[tmp.axisToId(ds.x, ds.y, limitY)].d << "\n";
    ret.push_back({(int)distance[tmp.axisToId(ds.x, ds.y, limitY)].d,oo});
    stack<Point> path;
    while (!(ds.compare(src))) {
        //cout << "( " << ds.x << " - " << ds.y <<" )" << "\n";
        path.push(ds);
        //
        ds = tmp.idToAxis(parent[tmp.axisToId(ds.x, ds.y, limitY)], limitY);
    }
    //

    path.push(src);
    while (!path.empty()) {
//			cout << "( " << path.top().x << " - " << path.top().y << " )" << "\n";
        ret.push_back({path.top().x, path.top().y});
        path.pop();
    }
    return ret;
}
