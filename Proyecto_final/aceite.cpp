#include "aceite.h"

int aceite::getX() const
{
    return x;
}

void aceite::setX(int newX)
{
    x = newX;
}

int aceite::getY() const
{
    return y;
}

void aceite::setY(int newY)
{
    y = newY;
}

int aceite::getVel() const
{
    return vel;
}

void aceite::setVel(int newVel)
{
    vel = newVel;
}

void aceite::movimiento()
{
    y = y + vel;
    setPos(x,y);
    qDebug() << "Mancha en y: " << y;
    if(y > 500){
        scene()->removeItem(this);
        delete this;
    }
}

aceite::aceite(QGraphicsItem *mancha) : QGraphicsPixmapItem(mancha)
{
     setPixmap(QPixmap(":/images/aceite.png").scaled(20,20));
}

void aceite::posicion(int _x, int _y)
{
    x = _x;
    y = _y;
    setPos(_x, _y);
}


