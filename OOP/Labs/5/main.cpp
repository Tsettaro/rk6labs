#include <iostream>
#include <cmath>
#include <cstdio>
#include "point.hpp"
#include "triangle.hpp"

Point Point::from_stdin() {
    double a, b;
    while((scanf("%lf %lf", &a, &b)) != 2){
        while(getchar() != '\n') ;
        std::cout << "Invalid coordinates. Please try again: \n";
    }
    return Point(a, b);
}

double Point::distance(Point& p1, Point& p2){
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();
    return sqrt(dx * dx + dy * dy);
}

double Triangle::tr_area(double a, double b, double c){
    double semi = (a + b + c)/2;
    return sqrt(semi * (semi - a) * (semi - b) * (semi - c));
}

void Triangle::HeightLengths(){
    double a = Point::distance(_p1, _p2);
    double b = Point::distance(_p2, _p3);
    double c = Point::distance(_p3, _p1);

    double area = tr_area(a, b, c);
    if (a == 0 || b == 0 || c == 0){
        std::cout << "One of sides is equal zero. Exit!\n";
        exit(-1);
    }
    printf("First height - %.3lf \nSecond height - %.3lf \nThird height - %.3lf\n", 2*area/a, 2*area/b, 2*area/c);
}

int main(){
    Point p1 = Point::from_stdin();
    Point p2 = Point::from_stdin();
    Point p3 = Point::from_stdin();
    Triangle tr(p1, p2, p3);
    tr.HeightLengths();
}