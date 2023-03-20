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

// Расстояние между двумя точками
double Point::distance(Point* q){
    double _d = sqrt(pow(q->getX() - _x, 2) + pow(q->getY() - _y, 2));
    return _d;
}

int main(int argc, char** argv) {
	double d = -1.0, local_d;
    Point **p;
    Point *f, *s;
    int x, y;
    int i, j;
    if (argc < 3) {
        std::cout << "Invalid count of arguments\n";
        return -1;
    }
    p = new Point*[argc];
    for (i = 1, j = 0; i < argc; i++, j++){
        sscanf(argv[i],"%d%*c%d", &x, &y);
        p[j] = new Point(x, y);
    }
    for (i = 0; i < argc-1; i++){
        for (j = i+1; j < argc - 1; j++){
            local_d = p[i]->distance(p[j]);
            if (local_d > d){
                d = local_d;
                f = p[i];
                s = p[j];
            }
        }
    }
    printf("The longest distance is between points with coordinates (%d;%d) and (%d;%d) - %.3f\n", f->getX(), f->getY(), s->getX(), s->getY(), d);
    // Очищение массива указателей
    for (i = 0; i < argc-1; i++){
        delete p[i];
    }
    delete []p;
}