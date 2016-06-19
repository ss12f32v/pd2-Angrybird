#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPushButton>
#include <QProcess>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <barrier.h>
#include <sling.h>
#include <greenidiot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    greenidiot *green[4];
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void restart_game();
    void exit_game();
private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * event);
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    int count,i=0;
    int startx,starty,endx,endy;
    int changex,changey;
    int green0;
    int green1;
    int green2;
    int green3;
    Bird *birdie[4];
    void kill();
    QPushButton *restartbutton, *exitbutton;




};

#endif // MAINWINDOW_H
