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

int jugador::getMasa() const
{
    return masa;
}

void jugador::setMasa(int newMasa)
{
    masa = newMasa;
}

int jugador::getGiro1() const
{
    return giro1;
}

void jugador::setGiro1(int newGiro1)
{
    giro1 = newGiro1;
}


jugador::jugador(QGraphicsItem *moto) : QGraphicsPixmapItem(moto)
{

}

jugador::jugador(int level)
{
    if(level == 1){
        setPixmap(QPixmap(":/images2/enduro.png").scaled(25,50));
    }
    else{
        setPixmap(QPixmap(":/images/moto.png").scaled(25,50));
    }
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

void jugador::giro()
{
    setTransformOriginPoint(this->boundingRect().center());
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(rotacion()));
    timer->start(100);


}

void jugador::rotacion()
{
    if(giro1==4){
        giro1=0;
        angulo=90;
        timer->stop();
    }
    else{

        setRotation(angulo);
        angulo+=90;
        giro1++;
        y+=vy*2;
        x+=vx*2;
        if(random == 1){
           setPos(x,y);
        }
        else{
             setPos(-1*x,y);
        }
    }
}






