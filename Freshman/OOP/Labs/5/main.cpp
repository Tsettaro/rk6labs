#include <iostream>
#include <cmath>
#include "point.hpp"
#include "triangle.hpp"

std::istream& operator >>(std::istream& in, Point& p){
    char sep = ';';
    in >> p._x >> sep >> p._y;
    return in;
}

double Triangle::distance(Point& p1, Point& p2){
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();
    return sqrt(dx * dx + dy * dy);
}

double Triangle::tr_area(double a, double b, double c){
    double semi = (a + b + c)/2;
    return sqrt(semi * (semi - a) * (semi - b) * (semi - c));
}

void Triangle::HeightLengths(){
    double a = distance(_p1, _p2);
    double b = distance(_p1, _p3);
    double c = distance(_p2, _p3);

    double area = tr_area(a, b, c);
    if (a == 0 || b == 0 || c == 0){
        std::cout << "One of sides is equal zero. Exit!\n";
        exit(-1);
    }
    printf("First height - %.3lf \nSecond height - %.3lf \nThird height - %.3lf\n", 2*area/a, 2*area/b, 2*area/c);
}

int main(){
    Point p1, p2, p3;
    std::cout << "Input x1;y1 x2;y2 x3;y3 or exit:\n";
    std::cin >> p1 >> p2 >> p3;
    Triangle tr(p1, p2, p3);
    tr.HeightLengths();
}