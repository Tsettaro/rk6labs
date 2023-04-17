class Point {
private:
    double _x;
    double _y;
public:
    Point() : _x(0), _y(0) {};
    Point(double x, double y) : _x(x), _y(y) {};
    static Point from_stdin();
    static double distance(Point&, Point&);
    double getX() {return _x ;}
    double getY() {return _y ;}
};