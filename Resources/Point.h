#pragma once

const int limitY = 15;

class Point{
public:
    int x,y;
    bool compare(Point &tmp) {
        return (tmp.x == this->x && tmp.y == this->y);
    }
};