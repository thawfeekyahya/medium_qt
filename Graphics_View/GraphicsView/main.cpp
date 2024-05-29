
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "MyView.h"
#include "MyScene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyScene scene;

    MyView view(&scene);
    view.show();
    return a.exec();
}
