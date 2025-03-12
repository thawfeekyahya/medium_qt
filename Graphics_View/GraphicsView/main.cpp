#include <QApplication>
#include <QOpenGLWidget>
#include "MainWindow.h"
#include "MyScene.h"
#include "MyView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyScene scene;
    MyView view(&scene);


    QOpenGLWidget *gl = new QOpenGLWidget();
    QSurfaceFormat format;
    format.setSamples(4);
    gl->setFormat(format);
    view.setViewport(gl);

    view.show();
    return a.exec();
}
