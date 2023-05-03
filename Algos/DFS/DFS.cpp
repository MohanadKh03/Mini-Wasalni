#include "DFS.h"

void DFS::run(map<int, set<int>> &convertedGraph) {
    this->run(convertedGraph,tmp.axisToId(this->src.x,this->src.y,limitY));
}

ll DFS::run(map<int, set<int>> &convertedGraph, int parID) {

    Point cur = tmp.idToAxis(parID, limitY);
    //
    if (cur.compare(ds)) {
        return 0;
    }
    //
    auto &ret = dp[parID];
    if (ret.d != -1)return ret.d;
    //
    ret.d = 1e14;
    //
    for (auto &to: convertedGraph[parID]) {
        ll cost = this->run(convertedGraph, to) + dst(tmp.idToAxis(parID, limitY), tmp.idToAxis(to, limitY));
        if (ret.d > cost) {
            ret.d = cost;
            path[parID] = to;
        }
    }
    //
    return ret.d;
}

vector<Point> DFS::getPath(map<int, set<int>> &convertedGraph) {
    auto srcID = tmp.axisToId(src.x, src.y, limitY);
    if (dp[srcID].d >= 1e14) {
        return{{oo,oo}};
    }
    //
    Point cur = src;
    vector<Point>ret;
    ret.push_back({(int)dp[srcID].d ,oo});
//    cout << "Path: " << dp[srcID].d << "\n";
    while (!cur.compare(ds)) {
//        cout << "( " << cur.x << " - " << cur.y << " )" << "\n";
        ret.push_back({cur.x,cur.y});
        ll CurrId=tmp.axisToId(cur.x, cur.y, limitY);
        ll parId=path[CurrId];
        cur = tmp.idToAxis((int)parId,limitY);
    }
    ret.push_back({ds.x,ds.y});
//    cout << "( " << ds.x << " - " << ds.y << " )" << "\n";
    return ret;
}
