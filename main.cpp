

#include <QApplication>
#include "firstscreen.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FirstScreen f;

    f.setModal(true);
    f.exec();

    return a.exec();
}

