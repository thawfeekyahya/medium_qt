#include "MyView.h"
#include "MyScene.h"
#include <QKeyEvent>
#include <QDebug>


MyView::MyView(MyScene *scene): QGraphicsView(scene),
    mScene(scene)
{

}

void MyView::keyPressEvent(QKeyEvent *event)
{
        switch(event->key()) {
        case Qt::Key_Space:
           mPaused = !mPaused;
           mScene->setPaused(mPaused);
           break;
        default:
           QGraphicsView::keyPressEvent(event);
    }

}
