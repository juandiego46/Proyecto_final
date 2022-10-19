#include "aceite.h"

aceite::aceite(QGraphicsItem *mancha) : QGraphicsPixmapItem(mancha)
{
     setPixmap(QPixmap(":/images/aceite.png").scaled(20,20));

     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this,SLOT(movimiento()));
     timer->start(100);
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
    y += vel;
    setPos(x(),y);
    if(y > 500){
        scene()->removeItem(this);
        delete this;
    }
}


void aceite::posAleatorio()
{
    if(random>90){
       setPos(random,y);
    }
    else{
        random += 90;
        setPos(random,y);
    }
}

