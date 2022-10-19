#include "jugador.h"

int jugador::getX() const
{
    return x;
}

void jugador::setX(int newX)
{
    x = newX;
}

int jugador::getY() const
{
    return y;
}

void jugador::setY(int newY)
{
    y = newY;
}

int jugador::getVx() const
{
    return vx;
}

void jugador::setVx(int newVx)
{
    vx = newVx;
}

int jugador::getVy() const
{
    return vy;
}

void jugador::setVy(int newVy)
{
    vy = newVy;
}

jugador::jugador(QGraphicsItem *moto) : QGraphicsPixmapItem(moto)
{
    setPixmap(QPixmap(":/images/moto.png").scaled(25,50));
}

void jugador::posicion()
{
    setPos(x,y);
}

void jugador::posicion(int _x, int _y)
{
    x = _x;
    y = _y;
    setPos(_x, _y);
}








