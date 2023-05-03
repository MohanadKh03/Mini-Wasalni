#include "Floyd.h"
void Floyd::setPoints(Point source, Point dst) {
    this->src = source;
    this->ds = dst;
}
void Floyd::run(map<int, set<int>> &convertedGraph)
{
    for (auto& it : convertedGraph) {
        for (auto& i : convertedGraph) {
            for (auto& j : convertedGraph) {
                if (dp[{i.first, j.first}].d > dp[{i.first, it.first}].d + dp[{it.first, j.first}].d) {
                    dp[{i.first, j.first}].d = dp[{i.first, it.first}].d + dp[{it.first, j.first}].d;
                    path[{i.first, j.first}] = path[{i.first, it.first}];
                }
            }
        }
    }
}
vector<Point> Floyd::getPath(map<int, set<int>> &convertedGraph)
{
    vector<Point>ret;

    int u = tmp.axisToId(src.x,src.y,limitY), v = tmp.axisToId(ds.x, ds.y,limitY);
    if (dp[{u, v}].d == 1e18) {
        return{{oo,oo}};
    }
//    cout << "Path: " << dp[{u, v}].d << "\n";
    ret.push_back({(int)dp[{u, v}].d,oo});
    vector<ll>vv = { u };
    while (u!=v) {
        u =(int)path[{u,v}].d;
        vv.push_back(u);
    }
    for (auto& it : vv) {
        Point currPoint = tmp.idToAxis((int)it,limitY);
//        cout << "( " << currPoint.x << " - " << currPoint.y << " )" << "\n";
        ret.push_back({currPoint.x,currPoint.y});
    }
    return ret;
}
void Floyd::build(map<int, set<int>>& graph) {
    for (auto& i : graph) {
        for (auto& j : i.second) {
            ll tmpDist = dst(tmp.idToAxis(i.first,limitY), tmp.idToAxis(j,limitY));
            dp[{i.first, j}].d = tmpDist;
            path[{i.first, j}].d = j;
        }
    }
}
