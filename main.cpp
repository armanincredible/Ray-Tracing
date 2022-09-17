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
    Window_Clock w({100, 100}, {400, 400}, {250, 250});
    w.set_radius(80);
    Window_Click w1({100, 100}, {400, 400}, {250, 250});

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&w);
    layout->addWidget(&w1);

    window.setLayout(layout);
    window.show();
    return a.exec();
}
