#include "BallAnimation.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QtMath>

BallAnimation::BallAnimation(QWidget *parent)
    : QWidget{parent}
{
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,QOverload<>::of(&BallAnimation::update));
    timer->start(41);

    setWindowTitle("Ball Animation");
    resize(640,480);
}

void BallAnimation::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Space:
        mPaused = !mPaused;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}


void BallAnimation::paintEvent(QPaintEvent *event)
{

    QColor color(255,0,0);

    QPainter painter(this);

    // painter.setWindow(0,0,20,20); // like zoom in or cropping the area only what you need
    //painter.setViewport(width()/2,height()/2,640,480); // like scaling the enitre window
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width()/2,height()/2);

    painter.setPen(Qt::NoPen);
    painter.setBrush(color);

    painter.save();

    if(!mPaused) {
        //if(mAngle > 360) mAngle = 0.0;
        mAngle+=0.1;
    }

    float vx = qCos(mAngle) * mDistance;
    float vy = qSin(mAngle) * mDistance;

    painter.drawEllipse((-25+vx),(-25+vy),50,50);
    //painter.drawRect(0,0,100,100);
    painter.restore();
}
