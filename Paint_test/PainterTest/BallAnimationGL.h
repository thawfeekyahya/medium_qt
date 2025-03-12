#ifndef BALLANIMATIONGL_H
#define BALLANIMATIONGL_H

#include "Helper.h"

#include <QObject>
#include <QOpenGLWidget>

class BallAnimationGL : public QOpenGLWidget
{
    Q_OBJECT
public:
    BallAnimationGL();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
private:
    float mAngle{0};
    int mDistance{200};
    bool mPaused = false;
    Helper helper;
};

#endif // BALLANIMATIONGL_H
