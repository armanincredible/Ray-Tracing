#include "window.h"
#include "QTimer"
#include <QApplication>
#include <QVBoxLayout>
#include "QPushButton"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.resize(1200, 1200);
    Window w({100, 100}, {400, 400}, {250, 250}, clock_vector);
    w.set_radius(80);
    Window w1({100, 100}, {400, 400}, {250, 250}, click_vector);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&w);
    layout->addWidget(&w1);

    window.setLayout(layout);
    window.show();
    return a.exec();
}
