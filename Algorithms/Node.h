#pragma once
// x-y -> id
/*
1 2 3 4
5 6 7 8
9 10 11 12
x,y,n,m;
id;
id=(x-1)*m+y;
x = id/m+(id%m!=0);
y = id%(m)+(id%m==0)?m:0;
*/
struct Axis {
	int x, y;
	bool compare(Axis &tmp) {
		return (tmp.x == this->x && tmp.y == this->y);
	}
};
class NodeConverter {
public:
	Axis idToAxis(int id,int m) {
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
//x1,y1 - x2,y2