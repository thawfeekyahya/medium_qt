#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QObject>

class MyScene : public QGraphicsScene
{
public:
    explicit MyScene(QObject *parent = nullptr);
    void setPaused(bool paused);
protected:
    void keyPressEvent(QKeyEvent* event) override;
private:
    void drawEllipse();

    QGraphicsEllipseItem* mEllipse;

    int mDistance{200};
    float mAngle{0.1};
    void moveCircle();
    bool mPaused{false};
};

#endif // MYSCENE_H
