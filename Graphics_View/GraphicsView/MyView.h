#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

class MyScene;
class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    MyView(MyScene* scene);
protected:
    void keyPressEvent(QKeyEvent* event);
private:
    MyScene* mScene;
    bool mPaused{false};
};

#endif // MYVIEW_H
