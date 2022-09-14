#include "window.h"
#include "math.h"
#include "stdio.h"
/*
Vector Window::operator=(Point point_in)
{
    //return;

    return ctor({(double)(point_in.x + origin_point_.x), (double)(point_in.y + origin_point_.y)});
}

Vector Window::operator=(Vector vec)
{
    //return;

    return Vector()


    return Vector{{(double)(vec.in_point.x + origin_point_.x), (double)(vec.in_point.y + origin_point_.y)}, {vec.out_point}};
}*/

void Vector::CalculateRealPoints(Point origin_point)
{
    real_in_point_ = {(double)(in_point_.x + origin_point.x), (double)(-in_point_.y + origin_point.y)};
    real_out_point_ = origin_point;
}

void Vector::CalculateTriangle(Point& f_point, Point& s_point, Point origin_point)
{
    double delta_x = in_point_.x - out_point_.x;
    double delta_y = in_point_.y - out_point_.y;

    double k = delta_y / delta_x;
    //printf ("%lf\n", k);
    double k1 = -1 / k;

    Point separator_point = {in_point_.x - delta_x / 10, in_point_.y - delta_y / 10};
    /*if (separator_point.x * k != separator_point.y)
    {
        printf ("ERROR\n");
    }*/

    double length_x = 1 * sqrt(pow(delta_x, 2) + pow(delta_y,2)) / 20 * sqrt(1 + pow(k1, 2));
    double length_y = fabs(k1 * length_x);

    f_point.x = separator_point.x - length_x + origin_point.x;
    s_point.x = separator_point.x + length_x + origin_point.x;
    f_point.y = -(separator_point.y + length_y) + origin_point.y;
    s_point.y = -(separator_point.y - length_y) + origin_point.y;
}
