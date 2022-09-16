#include "vectors.h"
#include "math.h"

static const double RATIO = 10;
static const double EPS = 10e-8;

void Vector::CalculateRealPoints(Point origin_point)
{
    real_in_point_ = {(double)(in_point_.x + origin_point.x), (double)(-in_point_.y + origin_point.y)};
    real_out_point_ = origin_point;
}

void Vector::CalculateTriangle(Point origin_point)
{
    double delta_x = in_point_.x - out_point_.x;
    double delta_y = in_point_.y - out_point_.y;

    if (fabs(delta_x) + fabs(delta_y) < EPS)
    {
        printf ("here\n");
        //return;
    }

    double delta_x_separator = delta_x / RATIO;
    double delta_y_separator = delta_y / RATIO;

    Point separator_point = {in_point_.x - delta_x_separator,
                             in_point_.y - delta_y_separator};


    double sin_al = delta_y / sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    double cos_al = delta_x / fabs (delta_x) * sqrt(1 - pow(sin_al, 2));

    double length = sqrt(pow(delta_x_separator, 2) + pow(delta_y_separator, 2)) / 2;//sqaure_triangle / (4 * sqrt(pow(delta_x / 10, 2) + pow(delta_y / 10, 2)));
    double length_x =length * sin_al;
    double length_y =length * cos_al;

    first_point_arrow.x = separator_point.x - length_x + origin_point.x;
    second_point_arrow.x = separator_point.x + length_x + origin_point.x;
    first_point_arrow.y = -(separator_point.y + length_y) + origin_point.y;
    second_point_arrow.y = -(separator_point.y - length_y) + origin_point.y;
}

int Vector::paintVector (QPainter* painter, Point origin_point)
{
    if (painter == NULL)
    {
        return -1;
    }
    if (fabs(in_point_.x) < EPS  && fabs(in_point_.y) < EPS &&
        fabs(out_point_.x) < EPS &&  fabs(out_point_.y) < EPS)
    {
        return 0;
    }
    CalculateRealPoints(origin_point);
    painter->drawLine(real_in_point_.x, real_in_point_.y,
                     real_out_point_.x, real_out_point_.y);

    CalculateTriangle(origin_point);

    QPolygon poly;
    poly<<QPoint(first_point_arrow.x, first_point_arrow.y)<<QPoint(second_point_arrow.x, second_point_arrow.y)<<QPoint(real_in_point_.x, real_in_point_.y);

    painter->setBrush(Qt::black);
    painter->drawPolygon(poly);

    return 0;
}
