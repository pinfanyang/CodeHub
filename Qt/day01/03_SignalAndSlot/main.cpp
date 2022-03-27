#include "mymainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWidget w;
    w.show();

    return a.exec();
}
