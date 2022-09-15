#ifndef WINDOW_H
#define WINDOW_H

#include "vectors.h"

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
