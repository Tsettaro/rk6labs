#include <cmath>
#include <iostream>

class Point {
	private:
		float _x, _y;
	public:
		Point(): _x(0), _y(0) {};
		Point (float x, float y): _x(x),_y(y) {};
		float getX() {return _x;}
		float getY() {return _y;}
		// Статический метод класса
		static Point polar(float, float); 
};