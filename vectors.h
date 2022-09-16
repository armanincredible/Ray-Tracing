#ifndef VECTORS_H
#define VECTORS_H
#include "QPainter"

struct Point
{
    double x = 0;
    double y = 0;
};

class Vector
{
private:
    Point out_point_ = {};
    Point in_point_ = {};

    Point first_point_arrow = {};
    Point second_point_arrow = {};

    Point real_out_point_ = {};
    Point real_in_point_  = {};
public:
    Vector(Point out, Point in):
        out_point_(out),
        in_point_(in)
    {}
    Vector(){}
    Point get_real_in_point() const
    {
        return real_in_point_;
    }
    Point get_real_out_point() const
    {
        return real_out_point_;
    }
    void change_points(Point out, Point in)
    {
        out_point_ = out;
        in_point_  = in;
    }

    void CalculateRealPoints(Point);
    void CalculateTriangle(Point);
    int paintVector(QPainter* painter, Point);
};

#endif // VECTORS_H
