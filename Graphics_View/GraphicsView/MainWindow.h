#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWindow>

class MyView;
class MyScene;

class MainWindow : public QOpenGLWindow
{
public:
    MainWindow();
private:
    MyScene* mScene;
    MyView* mView;
};

#endif // MAINWINDOW_H
