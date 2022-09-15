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

    //double k = delta_y / delta_x;
    //printf ("%lf\n", k);
    //double k1 = -1 / k;

    Point separator_point = {in_point_.x - delta_x / 10, in_point_.y - delta_y / 10};


    double sin_al = delta_y / sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    double cos_al = delta_x / fabs (delta_x) * sqrt(1 - pow(sin_al, 2));

    double sqaure_triangle = 100;
    double length = sqaure_triangle / (4 * sqrt(pow(delta_x / 10, 2) + pow(delta_y / 10, 2)));
    //double tg_alpha = length / sqrt(pow(separator_point.x, 2) + pow(separator_point.y, 2));
    //double cos_alpha = 1 / sqrt(1 + pow(tg_alpha, 2));
    //double cos_alpha = 1/9;
    //double sin_alpha = sqrt(1 - pow(cos_alpha, 2));
    /*if (separator_point.x * k != separator_point.y)
    {
        printf ("ERROR\n");
    }*/

    //double length_x = 1 * sqrt(pow(delta_x, 2) + pow(delta_y,2)) / 20 * sqrt(1 + pow(k1, 2));
    //double length_y = fabs(k1 * length_x);
    //length = 20;
    double length_x =length * sin_al;
    double length_y =length * cos_al;

    f_point.x = separator_point.x - length_x + origin_point.x;
    s_point.x = separator_point.x + length_x + origin_point.x;
    f_point.y = -(separator_point.y + length_y) + origin_point.y;
    s_point.y = -(separator_point.y - length_y) + origin_point.y;
}
