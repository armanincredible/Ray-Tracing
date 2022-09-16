#ifndef WINDOW_H
#define WINDOW_H

#include "QPaintEvent"
#include "vectors.h"
#include "QPainter"
#include "QWidget"
#include "math.h"

enum type_window
{
    clock_vector,
    click_vector
};

class Window : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    Point mouse_click_ = {};
    Point start_point_ = {};
    Point end_point_ = {};
    Point origin_point_ = {};
    type_window type_ = {};
    double radius_ = 0;

public:
    Window(Point start, Point end, Point origin, type_window type):
        start_point_(start),
        end_point_(end),
        origin_point_(origin),
        type_(type)
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

    void set_radius(double radius)
    {
        radius_ = radius;
    }

    Point get_origin_point() const
    {
        return origin_point_;
    }
    Point get_start_point()const
    {
        return start_point_;
    }
    int paintCoordinateSystem(QPainter*);
};


#endif // WINDOW_H
