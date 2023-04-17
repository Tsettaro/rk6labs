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