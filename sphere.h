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
    Point center_coordinate_ = {0, 0, 0};
    Vector color_material_ = {};
    bool matte_ = 0;
public:
    Sphere(double length, double pow, Point coord, Point color, bool matte):
        power_of_specular_(pow),
        radius_(length),
        center_coordinate_(coord),
        color_material_({0, 0, 0}, color),
        matte_(matte)
    {}
    void set_radius(double radius)
    {
        radius_ = radius;
    }
    double get_radius() const
    {
        return radius_;
    }
    void set_center_coordinate(Point point)
    {
        center_coordinate_ = point;
    }
    Point get_center_coordinate() const
    {
        return center_coordinate_;
    }
    double get_power_of_specular() const
    {
        return power_of_specular_;
    }
    void set_color_material (Point p)
    {
        color_material_.change_points({0, 0, 0}, p);
    }
    Vector get_color_material()
    {
        return color_material_;
    }
    bool is_matte ()
    {
        return matte_;
    }
};

class Lamp
{
private:
    Point lamp_coordinate_ = {};
    Vector color_ray_ = {};
public:
    Lamp (Point coordinate, Point color):
        lamp_coordinate_(coordinate),
        color_ray_({0, 0, 0}, color)
    {}
    void set_color_ray (Point p)
    {
        color_ray_.change_points({0, 0, 0}, p);
    }
    Vector get_collor_ray ()
    {
        return color_ray_;
    }
    void set_lamp_point (Point p)
    {
        lamp_coordinate_ = p;
    }
    Point get_lamp_point () const
    {
        return lamp_coordinate_;
    }
};

class Window_Sphere : public Window
{
protected:
    void paintEvent(QPaintEvent *) override;
private:
    std::list<Sphere> spheres_ = {};
    std::list<Lamp> lamps_ = {};
    QImage src_ = {};
    Point_int size_ = {};
    Point_int viewer_ = {};
public:
    void paintSphere();
    void paintRacing();
    Window_Sphere(double size_x, double size_y):
        Window({0, 0}, {size_x, size_y}, {size_x/2, size_y/2}),
        src_(QImage(QSize(size_x, size_y), QImage::Format_RGB888))
    {
        size_ = {int(size_x), int(size_y)};
    };

    Window_Sphere(double size_x, double size_y, Point origin):
        Window({0, 0}, {size_x, size_y}, {origin.x, origin.y, origin.z}),
        src_(QImage(QSize(size_x, size_y), QImage::Format_RGB888))
    {
        size_ = {int(size_x), int(size_y)};
    };

    void add_lamp (Point coordinate, Point color)
    {
        lamps_.push_back(Lamp(coordinate, color));
    }
    void add_sphere (double length, double pow, Point coord, Point color, bool matte)
    {
        spheres_.push_back(Sphere(length, pow, coord, color, matte));
    }

    void set_viewer_point (Point_int p)
    {
        viewer_ = p;
    }
    Point_int get_viewer_point () const
    {
        return viewer_;
    }

    void clap_value(double &value)
    {
        if (value > 1 || value < 0)
        {
            value = 1;
        }
    }
    void clap_value(int &value)
    {
        if (value > 1 || value < 0)
        {
            value = 1;
        }
    }

    double calculate_diffuse (Point, Sphere&, Lamp&);
    double calculate_specular (Point, Sphere&, Lamp&);
    int get_points_crossed_sphere (Vector&, Point&);
};


#endif // SPHERE_H
