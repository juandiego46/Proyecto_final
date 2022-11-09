#include "enemigos.h"
#include <QDebug>



int enemigos::getY() const
{
    return y;
}

void enemigos::setY(int newY)
{
    y = newY;
}

int enemigos::getX() const
{
    return x;
}

void enemigos::setX(int newX)
{
    x = newX;
}

int enemigos::getMasa() const
{
    return masa;
}

void enemigos::setMasa(int newMasa)
{
    masa = newMasa;
}

int enemigos::getVy() const
{
    return vy;
}

void enemigos::setVy(int newVy)
{
    vy = newVy;
}

enemigos::enemigos(QGraphicsItem *evil):QGraphicsPixmapItem(evil)
{
    setPixmap(QPixmap(":/images/carro2.png").scaled(30,60));
    vect_enemigos.push_back(this);

}
enemigos::enemigos(int coches, int level)
{
    if(level ==1){
        vy = 10;
        if(coches > 0 && coches <= 5){
            setPixmap(QPixmap(":/images2/nascar.png").scaled(30,60));
            vect_enemigos.push_back(this);
        }
         else{
              setPixmap(QPixmap(":/images2/camioon.png").scaled(30,90));
              vect_enemigos.push_back(this);
        }

    }
    else{
        if(coches > 0 && coches <= 5){
            setPixmap(QPixmap(":/images/carro2.png").scaled(30,60));
            vect_enemigos.push_back(this);
        }
         else{
              setPixmap(QPixmap(":/images/camion.png").scaled(30,90));
              vect_enemigos.push_back(this);
        }
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movimiento()));
    timer->start(50);
}

void enemigos::posicion()
{
    setPos(x,y);
}

void enemigos::posi()
{
    if(random>90){
        x = random;
       setPos(random,0);
    }
    else{
        random += 90;
        x = random;
        setPos(random,0);
    }
}

void enemigos::movimiento()
{
    y += vy;
    setPos(x,y);
}

void enemigos::sig_level()
{
    if(!vect_enemigos.empty()){
        for(auto it : vect_enemigos){
            scene()->removeItem(it);
             vect_enemigos.removeOne(it);
        }
        vect_enemigos.clear();
        delete timer;
    }
}

