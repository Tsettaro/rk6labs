#include "point.hpp"

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