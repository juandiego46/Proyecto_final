#include "turbo.h"

int turbo::getY() const
{
    return y;
}

void turbo::setY(int newY)
{
    y = newY;
}

int turbo::getVel() const
{
    return vel;
}

void turbo::setVel(int newVel)
{
    vel = newVel;
}

void turbo::posAleatorio()
{
    if(random>90){
       setPos(random,y);
    }
    else{
        random += 90;
        setPos(random,y);
    }
}

void turbo::movimiento()
{
    y += vel;
    setPos(x(),y);
}

turbo::turbo(QGraphicsItem *nitro) : QGraphicsPixmapItem(nitro)
{
    setPixmap(QPixmap(":/images/Nitro1.png").scaled(15,45));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movimiento()));
    timer->start(50);
}
