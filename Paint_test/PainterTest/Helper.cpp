#include "Helper.h"

#include <QPainter>
#include <QBrush>
#include <QPaintEvent>

Helper::Helper() {}

void Helper::paintBall(QPainter *painter,QPaintEvent* event, QPoint startPos, QPoint updatePos)
{
    QColor color(255,0,0);

    painter->fillRect(event->rect(), QBrush(QColor(64,32,64)));


    painter->setRenderHint(QPainter::Antialiasing);

    painter->translate(startPos.x(),startPos.y());

    painter->setPen(Qt::NoPen);
    painter->setBrush(color);

    painter->save();

    painter->drawEllipse((-25+updatePos.x()),(-25+updatePos.y()),50,50);
    painter->restore();
}
