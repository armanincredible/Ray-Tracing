#ifndef WINDOW_H
#define WINDOW_H

#include "QPaintEvent"
#include "vectors.h"
#include "QPainter"
#include "QWidget"
#include "math.h"



class Window : public QWidget
{
    Q_OBJECT

protected:
    virtual void paintEvent(QPaintEvent *){};

private:
    Point start_point_ = {};
    Point end_point_ = {};
    Point origin_point_ = {};
    double radius_ = 0;

public:
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

    void set_radius(double radius)
    {
        radius_ = radius;
    }
    double get_radius()
    {
        return radius_;
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

class Window_Clock : public Window
{
protected:
    void paintEvent(QPaintEvent *) override;
public:
    Window_Clock(Point start, Point end, Point origin):
        Window(start, end, origin){};
};

class Window_Click : public Window
{
private:
     Point mouse_click_ = {};
protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
public:
    Window_Click(Point start, Point end, Point origin):
        Window(start, end, origin){};
};


#endif // WINDOW_H
