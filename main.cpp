#include "mainscene.h"
#include "start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainScene s;
//    s.show();
    start w;
    w.show();

    return a.exec();
}
