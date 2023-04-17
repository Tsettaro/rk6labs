#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

class Point {
private:
    double _x;
    double _y;
public:
    Point() : _x(0), _y(0) {};
    Point(double x, double y) : _x(x), _y(y) {};
    double getX() {return _x ;}
    double getY() {return _y ;}
    static Point from_stdin();
    static double distance(Point&, Point&);
};

Point Point::from_stdin() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    return Point(a, b);
}

class Triangle {
private:
    Point _p1;
    Point _p2;
    Point _p3;
    double tr_area(double, double, double);
public:
    Triangle(Point& p1, Point& p2, Point& p3): _p1(p1), _p2(p2), _p3(p3) {}
    void HeightLengths();
};

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
    std::cout << area << '\n';
    if (a == 0 || b == 0 || c == 0){
        std::cout << "One of sides is equal zero. Abort!\n";
        exit(-1);
    }
    printf("First height - %lf \nSecond height - %lf \nThird height - %lf\n", 2.0*area/a, 2.0*area/b, 2.0*area/c);
}

int main(){
    Point p1 = Point::from_stdin();
    Point p2 = Point::from_stdin();
    Point p3 = Point::from_stdin();
    Triangle tr(p1, p2, p3);
    tr.HeightLengths();
}