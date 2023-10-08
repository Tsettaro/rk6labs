#include <iostream>
#include <cmath>
#include <cstdio>

class Point {
	private:
		int _x, _y;
	public:
		Point (int x, int y): _x(x),_y(y) {};
		Point(): _x(0), _y(0) {};
		int getX() {return _x;}
		int getY() {return _y;}
		double distance(Point*);
};