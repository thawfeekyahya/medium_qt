#include "MyScene.h"

#include <QKeyEvent>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QDebug>
#include <QPainter>

MyScene::MyScene(QObject *parent)
    : QGraphicsScene{parent}
{

    setSceneRect(0,0,640,480);
    setBackgroundBrush(Qt::blue);
    drawEllipse();
    QTimer* timer = new QTimer(this);
    timer->setInterval(41);
    timer->start();
    connect(timer,&QTimer::timeout,[this]() {
        if(!mPaused) moveCircle();
    });

}

void MyScene::setPaused(bool paused)
{
    mPaused = paused;
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
    switch(event->key()) {
    default:
        QGraphicsScene::keyPressEvent(event);
    }
}

void MyScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->fillRect(rect,QBrush(QColor(64,0,64))); // To avoid background flikcering when opengl is used as viewport
}

void MyScene::drawEllipse()
{
    mEllipse = addEllipse(QRect(640/2-25,480/2-25,50,50),QPen(Qt::NoPen),QBrush(QColor(255,0,0)));

    //mEllipse->setFlag(QGraphicsItem::ItemIsFocusable);
    //setFocusItem(mEllipse);
}

void MyScene::moveCircle()
{
    mAngle += 0.1;
    float vx = qCos(mAngle) * mDistance;
    float vy = qSin(mAngle) * mDistance;

    mEllipse->setX(vx);
    mEllipse->setY(vy);
}
