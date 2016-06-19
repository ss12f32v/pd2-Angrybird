#ifndef BARRIER_H
#define BARRIER_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include"gameitem.h"


#define BRICK_DENSITY 3.0f
#define BRICK_FRICTION 0.2f
#define BRICK_RESTITUTION 0.5f

class barrier:public GameItem
{
public:
    barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BARRIER_H
