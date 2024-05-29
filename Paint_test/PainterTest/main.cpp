#include "BallAnimation.h"
#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BallAnimation ballAnim;
    ballAnim.show();
    return a.exec();
}
