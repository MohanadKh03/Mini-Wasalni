#pragma once
#include "Point.h"
class NodeConverter {
public:
    Point idToAxis(int id,int m) {
        int x = id / m + (id % m != 0);
        int y = (id % m);
        if (id % m == 0)y += m;
        return { x,y };
    }
    //
    int axisToId(int x, int y,int m) {
        return(x - 1) * m + y;
    }
    //
};