#include "vectors.h"
#include "math.h"

static const double RATIO = 10;
static const double EPS = 10e-8;

void Vector::CalculateRealPoints(Point origin_point)
{
    real_in_point_ = {(double)(in_point_.x + origin_point.x), (double)(-in_point_.y + origin_point.y)};
    real_out_point_ = {(double)(out_point_.x + origin_point.x), (double)(-out_point_.y + origin_point.y)};
}

void Vector::CalculateArrow(Point origin_point)
{
    double delta_x = get_length_x();
    double delta_y = get_length_y();

    if (fabs(delta_x) + fabs(delta_y) < EPS)
    {
        return;
    }

    double delta_x_separator = delta_x / RATIO;
    double delta_y_separator = delta_y / RATIO;

    Point separator_point = {in_point_.x - delta_x_separator,
                             in_point_.y - delta_y_separator};

    double sin_al = delta_y / sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    double cos_al = delta_x / fabs (delta_x) * sqrt(1 - pow(sin_al, 2));

    double length = sqrt(pow(delta_x_separator, 2) + pow(delta_y_separator, 2)) / 2;
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
    if (fabs(get_length_x()) < EPS  &&
        fabs(get_length_y()) < EPS)
    {
        return 0;
    }

    CalculateRealPoints(origin_point);
    painter->drawLine(real_in_point_.x, real_in_point_.y,
                     real_out_point_.x, real_out_point_.y);

    CalculateArrow(origin_point);

    QPolygon poly;
    poly<<QPoint(first_point_arrow.x, first_point_arrow.y)<<QPoint(second_point_arrow.x, second_point_arrow.y)<<QPoint(real_in_point_.x, real_in_point_.y);

    painter->setBrush(Qt::black);
    painter->drawPolygon(poly);

    return 0;
}

#define MAKE_POINTS_PLUS                                                                     \
        Point new_in = {in_point_.x + vec.get_length_x(), in_point_.y + vec.get_length_y()};

#define MAKE_POINTS_MINUS                                                                    \
        Point new_in = {in_point_.x - vec.get_length_x(), in_point_.y - vec.get_length_y()};

Vector Vector::operator +(const Vector &vec)
{
    MAKE_POINTS_PLUS
    return Vector(out_point_, new_in);
}


Vector Vector::operator -(const Vector &vec)
{
    MAKE_POINTS_MINUS
    return Vector(out_point_, new_in);
}

void Vector::operator +=(const Vector &vec)
{
    MAKE_POINTS_PLUS
    in_point_ = new_in;
}

void Vector::operator -=(const Vector &vec)
{
    MAKE_POINTS_MINUS
    in_point_ = new_in;
}

#undef MAKE_POINTS_MINUS
#undef MAKE_POINTS_PLUS

double Vector::operator *(const Vector &vec)
{
    Point delta_first = {get_length_x(), get_length_y()};
    Point delta_second = {vec.in_point_.x - vec.out_point_.x, vec.in_point_.y - vec.out_point_.y};
    return delta_first.x * delta_second.x + delta_first.y * delta_second.y;
}

Vector Vector::operator *(const double num)
{
    Point length = {num * (get_length_x()), num * (get_length_y())};

    if (num >= 0)
    {
        return Vector(out_point_, {out_point_.x + length.x, out_point_.y + length.y});
    }
    else
    {
        return Vector(in_point_, {in_point_.x + length.x, in_point_.y + length.y});
    }
}

void Vector::operator *=(const double num)
{
    Point length = {num * (get_length_x()), num * (get_length_y())};
    in_point_ = {out_point_.x + length.x, out_point_.y + length.y};
}

