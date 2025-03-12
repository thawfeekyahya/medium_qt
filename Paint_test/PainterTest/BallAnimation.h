#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include "Helper.h"

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
protected:
    void paintEvent(QPaintEvent* event) override;
signals:
private:
    float mAngle{0};
    int mDistance{200};
    bool mPaused = false;
    Helper helper;
};

#endif // BALLANIMATION_H
