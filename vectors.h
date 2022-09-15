#ifndef VECTORS_H
#define VECTORS_H

struct Point
{
    double x = 0;
    double y = 0;
};

class Vector
{
public:
    Point out_point_ = {};
    Point in_point_ = {};

    Point real_out_point_ = {};
    Point real_in_point_  = {};

    Vector(Point out, Point in):
        out_point_(out),
        in_point_(in)
    {}

    void CalculateRealPoints(Point);
    void CalculateTriangle(Point&, Point&, Point);
};

#endif // VECTORS_H
