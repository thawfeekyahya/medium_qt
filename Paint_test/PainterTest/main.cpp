#include "BallAnimation.h"
#include "BallAnimationGL.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    BallAnimationGL ballAnim;
    ballAnim.show();
    return a.exec();
}
