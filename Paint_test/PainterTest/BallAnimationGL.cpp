#include "BallAnimationGL.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

BallAnimationGL::BallAnimationGL() {

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,QOverload<>::of(&BallAnimationGL::update));
    timer->start(41);

    setWindowTitle("Ball Animation");
    setFixedSize(640,480);
    setAutoFillBackground(false);
}

void BallAnimationGL::paintEvent(QPaintEvent *event)
{

   if(!mPaused) {
       mAngle+=0.1;
   }

   float vx = qCos(mAngle) * mDistance;
   float vy = qSin(mAngle) * mDistance;

   QPainter painter;
   painter.begin(this);
   helper.paintBall(&painter,event,QPoint(width()/2,height()/2),QPoint(vx,vy));
   painter.end();
}

void BallAnimationGL::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()) {
    case Qt::Key_Space:
        mPaused = !mPaused;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
