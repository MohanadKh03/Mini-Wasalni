#include "Floyd.h"
void Floyd::setPoints(Point source, Point dst)
{
    this->src = source;
    this->destination = dst;
}
void Floyd::run(map<int, set<int>> &convertedGraph)
{
    for (auto &it : convertedGraph)
    {
        for (auto &i : convertedGraph)
        {
            for (auto &j : convertedGraph)
            {
                if (dp[{i.first, j.first}].value > dp[{i.first, it.first}].value + dp[{it.first, j.first}].value)
                {
                    dp[{i.first, j.first}].value = dp[{i.first, it.first}].value + dp[{it.first, j.first}].value;
                    path[{i.first, j.first}] = path[{i.first, it.first}];
                }
            }
        }
    }
}
vector<Point> Floyd::getPath(map<int, set<int>> &convertedGraph)
{
    vector<Point> finalPath;

    int srcId = NodeConverter::axisToId(src.x, src.y, limitY), destId = NodeConverter::axisToId(destination.x, destination.y, limitY);
    if (dp[{srcId, destId}].value == 1e18)
    {
        return {{oo, oo}};
    }
    finalPath.push_back({(int)dp[{srcId, destId}].value, oo});
    vector<ll> pathWithId = {srcId};
    while (srcId != destId)
    {
        srcId = (int)path[{srcId, destId}].value;
        pathWithId.push_back(srcId);
    }
    for (auto &it : pathWithId)
    {
        Point currPoint = NodeConverter::idToAxis((int)it, limitY);
        finalPath.push_back({currPoint.x, currPoint.y});
    }
    return finalPath;
}
void Floyd::build(map<int, set<int>> &graph)
{
    for (auto &i : graph){
        for (auto &j : i.second){
            ll tmpDist = Algorithm::dst(NodeConverter::idToAxis(i.first, limitY), NodeConverter::idToAxis(j, limitY));
            dp[{i.first, j}].value = tmpDist;
            path[{i.first, j}].value = j;
        }
    }
}
