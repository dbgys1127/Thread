#include "KYHThreadWash.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KYHThreadWash w;
    w.show();
    return a.exec();
}
