#ifndef SLING_H
#define SLING_H


#include <QGraphicsScene>


#include"gameitem.h"
class sling:public GameItem

{
public:
    sling(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // SLING_H
