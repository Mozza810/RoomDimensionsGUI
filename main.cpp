#include "RoomDimensionsGUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoomDimensionsGUI w;
    w.show();

    return a.exec();
}
