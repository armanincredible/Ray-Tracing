#include "window.h"
#include "sphere.h"
#include "QTimer"
#include <QApplication>
#include <QVBoxLayout>
#include "QPushButton"

//#define VECTORS
#define SPHERE

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

#ifdef VECTORS
    QWidget window;
    window.resize(1200, 1200);
    Window_Clock w({100, 100}, {400, 400}, {250, 250});
    w.set_radius(80);
    Window_Click w1({100, 100}, {400, 400}, {250, 250});

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&w);
    layout->addWidget(&w1);

    window.setLayout(layout);
    window.show();
#endif

#ifdef SPHERE

    Window_Sphere w(1920, 1080, 300, 20);
    w.set_lamp_point({400, 200, 500});
    w.set_viewer_point({400, 200, 500});
    w.set_collor_material ({0.6, 0.2, 0.45});
    w.set_collor_ray ({0.9, 0.7, 0.3});
    w.resize(1920, 1080);
    w.show();

#endif
    return a.exec();
}
