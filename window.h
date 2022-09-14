#ifndef WINDOW_H
#define WINDOW_H

#include "vectors.h"

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


class Window
{
public:
    Point start_point_ = {};
    Point end_point_ = {};
    Point origin_point_ = {};

    Window(Point start, Point end, Point origin):
        start_point_(start),
        end_point_(end),
        origin_point_(origin)
    {
    }
    ~Window(){}

    int heigh() const
    {
        return end_point_.y - start_point_.y;
    }

    int width() const
    {
        return end_point_.x - start_point_.x;
    }
};


const Window first_window({100, 100}, {400, 400}, {200, 200});

#endif // WINDOW_H
