#include "mapa.h"

int mapa::getXx() const
{
    return xx;
}

void mapa::setXx(int newXx)
{
    xx = newXx;
}

int mapa::getYy() const
{
    return yy;
}

void mapa::setYy(int newYy)
{
    yy = newYy;
}

<<<<<<< HEAD
int mapa::getVx() const
{
    return vx;
}

void mapa::setVx(int newVx)
{
    vx = newVx;
}
=======
>>>>>>> 2178e1f (Movimiento al aceite)

int mapa::getVy() const
{
    return vy;
}

void mapa::setVy(int newVy)
{
    vy = newVy;
}

mapa::mapa(QGraphicsItem *map):QGraphicsPixmapItem(map)
{
    setPixmap(QPixmap(":/images/mapa1.png"));
}

void mapa::posmapa()
{
    setPos(xx,yy);
}

void mapa::posmapa(int x, int y)
{
    setPos(x,y);
}
