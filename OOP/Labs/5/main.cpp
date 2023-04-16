#include <iostream>
#include <cmath>

class Point {
private:
    double x_;
    double y_;
public:
    Point() : x_(0), y_(0) {};
    Point(double x, double y) : x_(x), y_(y) {};

    double getX() {return x_ ;}
    double getY() { return y_ ;}
};

class Triangle {
private:
    Point p1_;
    Point p2_;
    Point p3_;

    double distance(Point& p1, Point& p2) {
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return sqrt(dx * dx + dy * dy);
    }

    double sem_per(double a, double b, double c) {
        return (a + b + c) / 2;
    }

    double tr_area(double s, double a, double b, double c) {
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
public:
    Triangle(Point& p1, Point& p2, Point& p3): p1_(p1), p2_(p2), p3_(p3) {}

    double HeightLength() {
        double a = distance(p1_, p2_);
        double b = distance(p2_, p3_);
        double c = distance(p3_, p1_);

        double s = sem_per(a, b, c);
        double area = tr_area(s, a, b, c);

        double height = 2 * area / a;
        return height;
    }
};

int main(){
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите координаты вершин треугольника (x1 y1 ; x1 y1 ; x3 y3): \n";
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;
    Point p1(x1, y2);
    Point p2(x2, y2);
    Point p3(x3,y3);
    Triangle tr(p1, p2, p3);
    std::cout << tr.HeightLength() << '\n';
}