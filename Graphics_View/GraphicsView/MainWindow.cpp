#include "MainWindow.h"
#include "MyScene.h"
#include "MyView.h"


MainWindow::MainWindow() {
    resize(640,480);
    mScene = new MyScene(this);
    mView = new MyView(mScene);

}
