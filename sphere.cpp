#include "sphere.h"
#include "math.h"
#include <unistd.h>

static const double Ambient = 0.1;

static double calculate_z (const double r, const double x, const double y)
{
    return sqrt (pow(r, 2) - pow(x, 2) - pow(y, 2));
}

void Window_Sphere::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QRect target(0, 0, size_.x, size_.y);

    paintSphere();

    QPixmap pmap(size_.x, size_.y);
    pmap.convertFromImage(src_);

    painter.drawPixmap(target, pmap, target);

    //update();
}

void Window_Sphere::paintSphere()
{
    uchar* collor_buffer = src_.bits();
    double radius_2 = pow(sphere_.get_radius(), 2);
    double origin_x = get_origin_point().x;
    double origin_y = get_origin_point().y;
    Vector ray_and_material_collor = collor_material_ ^ collor_ray_;

    for (int y_len = 0; y_len < size_.y; y_len++)
    {
        for (int x_len = 0; x_len < size_.x; x_len++)
        {
            Point point_on_sphere {x_len - origin_x, origin_y - y_len};

            if (pow(point_on_sphere.x, 2) + pow(point_on_sphere.y, 2) <= radius_2)
            {
                Vector Collor = ray_and_material_collor * (calculate_D(point_on_sphere) + Ambient) +
                                collor_ray_ * pow(calculate_S(point_on_sphere), sphere_.get_power_of_specular());
                Point Collor_point = Collor.get_in_point();
                if (Collor_point.x > 1){Collor_point.x = 1;}
                if (Collor_point.y > 1){Collor_point.y = 1;}
                if (Collor_point.z > 1){Collor_point.z = 1;}

                collor_buffer[y_len * size_.x * 3 + 2 + x_len * 3] = (uchar)(Collor_point.z * 250);
                collor_buffer[y_len * size_.x * 3 + 1 + x_len * 3] = (uchar)(Collor_point.y * 250);
                collor_buffer[y_len * size_.x * 3 + 0 + x_len * 3] = (uchar)(Collor_point.x * 250);
            }
        }
    }
}

double Window_Sphere::calculate_D (Point point_on_sphere)
{
    double z = calculate_z (sphere_.get_radius(), point_on_sphere.x, point_on_sphere.y);
    Vector vec_lamp ({0, 0, 0}, Point{(double)lamp_.x, (double)lamp_.y, (double)lamp_.z});
    Vector normal ({0, 0, 0}, {point_on_sphere.x, point_on_sphere.y, z});

    double cos_fi = get_cos(vec_lamp, normal);
    if (cos_fi < 0)
    {
        cos_fi = 0;
    }

    return cos_fi;
}

double Window_Sphere::calculate_S (Point point_on_sphere)
{
    double z = calculate_z (sphere_.get_radius(), point_on_sphere.x, point_on_sphere.y);
    Vector l({(double)lamp_.x, (double)lamp_.y, (double)lamp_.z}, {point_on_sphere.x, point_on_sphere.y, z});
    l = l * (1 / sqrt(l.get_sqaure_length()));
    Vector normal ({0, 0, 0}, {point_on_sphere.x, point_on_sphere.y, z});
    normal = normal * (1 / sqrt(normal.get_sqaure_length()));
    Vector l_by_n = normal * 2 + l;
    Vector v({point_on_sphere.x, point_on_sphere.y, z}, {(double)viewer_.x, (double)viewer_.y, (double)viewer_.z});

    double cos_alpha = get_cos(l_by_n, v);
    if (cos_alpha < 0)
    {
        cos_alpha = 0;
    }

    return cos_alpha;
}
