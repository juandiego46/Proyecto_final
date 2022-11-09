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

}

mapa::mapa(int level)
{
    if(level ==1){
        setPixmap(QPixmap(":/images2/mapa1.png"));
    }
    else{
        setPixmap(QPixmap(":/images/mapa1.png"));
    }
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(hmov()));
    timer->start(50);
}

void mapa::posmapa()
{
    setPos(xx,yy);
}

void mapa::posmapa(int x, int y)
{
    setPos(x,y);
}

void mapa::hmov()
{
    if(yy < 0){
        yy += vy;
        setPos(xx,yy);
    }
}
