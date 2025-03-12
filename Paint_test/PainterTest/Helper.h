#ifndef HELPER_H
#define HELPER_H

#include <QPoint>



class QPainter;
class QPaintEvent;

class Helper
{
public:
    Helper();
    void paintBall(QPainter* painter,QPaintEvent* event,QPoint startPos,QPoint updatePos);
};

#endif // HELPER_H
