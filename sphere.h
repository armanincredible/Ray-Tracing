#ifndef SPHERE_H
#define SPHERE_H

#include "window.h"
#include "vectors.h"

struct Point_int
{
    int x = 0;
    int y = 0;
    int z = 0;
};

class Sphere
{
private:
    double radius_ = 0;
    double power_of_specular_ = 0;
public:
    Sphere(double length, double pow):
        power_of_specular_(pow),
        radius_(length)
    {}
    void set_radius(double radius)
    {
        radius_ = radius;
    }
    double get_radius() const
    {
        return radius_;
    }
    double get_power_of_specular() const
    {
        return power_of_specular_;
    }
};

class Window_Sphere : public Window
{
protected:
    void paintEvent(QPaintEvent *) override;
private:
    Sphere sphere_ = {0, 0};
    QImage src_ = {};
    Point_int size_ = {};
    double radius = 0;
    Point_int lamp_ = {};
    Point_int viewer_ = {};
    Vector collor_material_ = {};
    Vector collor_ray_ = {};
public:
    void paintSphere();
    Window_Sphere(double size_x, double size_y):
        Window({0, 0}, {size_x, size_y}, {size_x/2, size_y/2}),
        src_(QImage(QSize(size_x, size_y), QImage::Format_RGB888))
    {
        size_ = {int(size_x), int(size_y)};
    };
    Window_Sphere(double size_x, double size_y, double radius, double pow):
        Window({0, 0}, {size_x, size_y}, {size_x/2, size_y/2}),
        src_(QImage(QSize(size_x, size_y), QImage::Format_RGB888)),
        sphere_(radius, pow)
    {
        size_ = {int(size_x), int(size_y)};
    };
    void set_radius_of_sphere(double length)
    {
        sphere_.set_radius(length);
    }
    void set_collor_material (Point p)
    {
        collor_material_.change_points({0, 0, 0}, p);
    }
    void set_collor_ray (Point p)
    {
        collor_ray_.change_points({0, 0, 0}, p);
    }
    void set_lamp_point (Point_int p)
    {
        lamp_ = p;
    }
    Point_int get_lamp_point () const
    {
        return lamp_;
    }

    void set_viewer_point (Point_int p)
    {
        viewer_ = p;
    }
    Point_int get_viewer_point () const
    {
        return viewer_;
    }

    double calculate_D (Point);
    double calculate_S (Point);
};


#endif // SPHERE_H
