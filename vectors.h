#ifndef VECTORS_H
#define VECTORS_H
#include "QPainter"
#include "math.h"

struct Point
{
    double x = 0;
    double y = 0;
    double z = 0;
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
    Point get_out_point() const
    {
        return out_point_;
    }
    Point get_in_point() const
    {
        return in_point_;
    }
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
    double get_length_x() const
    {
        return in_point_.x - out_point_.x;
    }
    double get_length_z() const
    {
        return in_point_.z - out_point_.z;
    }
    double get_length_y() const
    {
        return in_point_.y - out_point_.y;
    }
    double get_sqaure_length() const
    {
        return pow(get_length_x(), 2) + pow(get_length_y(), 2) + pow(get_length_z(), 2);
    }

    void CalculateRealPoints(Point);
    void CalculateArrow(Point);
    int paintVector(QPainter* painter, Point);

    Vector operator + (const Vector &);
    Vector operator - (const Vector &);
    Vector operator ^ (const Vector &);
    void operator += (const Vector &);
    void operator -= (const Vector &);
    double operator * (const Vector &);
    Vector operator * (const double);
    void operator *= (const double);
};

double get_cos (Vector&, Vector&);

#endif // VECTORS_H
