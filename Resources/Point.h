#pragma once
#define oo INT32_MAX
const int limitY = 1000;

class Point{
public:
    int x,y;
    bool compare(Point &tmp) {
        return (tmp.x == this->x && tmp.y == this->y);
    }
};