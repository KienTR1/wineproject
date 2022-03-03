#include "mywine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mywine w;
    w.show();

    return a.exec();
}
