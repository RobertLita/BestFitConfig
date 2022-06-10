#include "ProiectMDS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProiectMDS w;
    w.show();
    return a.exec();
}
