#include "mainwindow.h"
#include "QPainter"
#include "QMouseEvent"
#include "window.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int x0 = first_window.start_point_.x;
    int y0 = first_window.start_point_.y;
    int height = first_window.heigh();
    int width = first_window.width();
    int origin_x = first_window.origin_point_.x;
    int origin_y = first_window.origin_point_.y;

    painter.drawRect(x0, y0, width, height);
    painter.drawLine(origin_x, y0 + height,
                     origin_x, y0);

    painter.drawLine(x0,         origin_y,
                     x0 + width, origin_y);

    Vector vec1 = {{0, 0}, {50, 50}};
    vec1.CalculateRealPoints(first_window.origin_point_);
    painter.drawLine(vec1.real_in_point_.x, vec1.real_in_point_.y,
                     vec1.real_out_point_.x, vec1.real_out_point_.y);

    Point f_point = {};
    Point s_point = {};
    vec1.CalculateTriangle(f_point, s_point, first_window.origin_point_);

    QPolygon poly;
    poly<<QPoint(f_point.x, f_point.y)<<QPoint(s_point.x, s_point.y)<<QPoint(vec1.real_in_point_.x, vec1.real_in_point_.y);

    painter.setBrush(Qt::black);
    painter.drawPolygon(poly);

}
*/

void MainWindow::paintEvent(QPaintEvent *event)
{
    static double alpha = 0;

    QPainter painter(this);

    int x0 = first_window.start_point_.x;
    int y0 = first_window.start_point_.y;
    int height = first_window.heigh();
    int width = first_window.width();
    int origin_x = first_window.origin_point_.x;
    int origin_y = first_window.origin_point_.y;

    painter.drawRect(x0, y0, width, height);
    painter.drawLine(origin_x, y0 + height,
                     origin_x, y0);

    painter.drawLine(x0,         origin_y,
                     x0 + width, origin_y);


    Vector vec1 = {{0, 0}, {80 * sin(alpha), 80 * cos(alpha)}};
    vec1.CalculateRealPoints(first_window.origin_point_);
    painter.drawLine(vec1.real_in_point_.x, vec1.real_in_point_.y,
                     vec1.real_out_point_.x, vec1.real_out_point_.y);

    Point f_point = {};
    Point s_point = {};
    vec1.CalculateTriangle(f_point, s_point, first_window.origin_point_);

    QPolygon poly;
    poly<<QPoint(f_point.x, f_point.y)<<QPoint(s_point.x, s_point.y)<<QPoint(vec1.real_in_point_.x, vec1.real_in_point_.y);

    painter.setBrush(Qt::black);
    painter.drawPolygon(poly);

    alpha += 3.14/100;
}
/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int x0 = first_window.start_point_.x;
    int y0 = first_window.start_point_.y;
    int height = first_window.heigh();
    int width = first_window.width();
    int origin_x = first_window.origin_point_.x;
    int origin_y = first_window.origin_point_.y;

    painter.drawRect(x0, y0, width, height);
    painter.drawLine(origin_x, y0 + height,
                     origin_x, y0);

    painter.drawLine(x0,         origin_y,
                     x0 + width, origin_y);

    Vector vec1 = {{0, 0}, {mouse_click.x, mouse_click.y}};
    vec1.CalculateRealPoints(first_window.origin_point_);
    painter.drawLine(vec1.real_in_point_.x, vec1.real_in_point_.y,
                     vec1.real_out_point_.x, vec1.real_out_point_.y);

    Point f_point = {};
    Point s_point = {};
    vec1.CalculateTriangle(f_point, s_point, first_window.origin_point_);

    QPolygon poly;
    poly<<QPoint(f_point.x, f_point.y)<<QPoint(s_point.x, s_point.y)<<QPoint(vec1.real_in_point_.x, vec1.real_in_point_.y);

    painter.setBrush(Qt::black);
    painter.drawPolygon(poly);
}*/

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouse_click.x = event->x() - first_window.origin_point_.x;
    mouse_click.y = first_window.origin_point_.y - event->y();
    repaint();
}
