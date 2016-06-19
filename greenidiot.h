#ifndef GREENIDIOT_H
#define GREENIDIOT_H

#include <gameitem.h>
#include <QGraphicsScene>
#include <QTimer>

#define GREEN_DENSITY 10.0f
#define GREEN_FRICTION 0.2f
#define GREEN_RESTITUTION 0.5f


class greenidiot: public GameItem
{
public:
    greenidiot(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    b2Vec2 speed;
public slots:
    void paint();
};

#endif // GREENIDIOT_H
