#include "window.h"
#include "sphere.h"
#include "QTimer"
#include <QApplication>
#include <QVBoxLayout>
#include "QPushButton"
#include "control.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

#ifdef VECTORS
    QWidget window;
    window.resize(1200, 1200);
    Window_Clock w2({100, 100}, {400, 400}, {250, 250});
    w2.set_radius(80);
    Window_Click w1({100, 100}, {400, 400}, {250, 250});

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&w2);
    layout->addWidget(&w1);

    window.setLayout(layout);
    window.show();
#endif

#ifdef ONLY_SPHERE

    Window_Sphere w(1920, 1080);
    w.add_sphere(300, 20, {0, 0, 0}, {0.6, 0.2, 0.45});
    w.add_lamp({400, 200, 500}, {0.9, 0.7, 0.3});
    //w.set_lamp_point({400, 200, 500});
    w.set_viewer_point({400, 200, 500});
    //w.set_color_material ({0.6, 0.2, 0.45});
    w.resize(1920, 1080);
    w.show();

#endif


#ifdef RACING

    Window_Sphere w(1920, 1080, {0, 1080/2, 0});
    //Window_Sphere w(1920, 1080, 300 , 20);

    w.add_lamp({300, -100, 200}, {0.5, 0.2, 0.4});
    w.add_lamp({1400, 100, 200}, {0.2, 0.3, 0.9});
    w.add_sphere(300, 20, {1920/2, 0, 400}, {0.5, 0.2, 0.85}, false);
    w.set_viewer_point({1920/2, 110, -1000});
    w.resize(1920, 1080);
    w.show();

#endif
    return a.exec();
}
