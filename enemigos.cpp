#include "enemigos.h"
#include <QDebug>



enemigos::enemigos(QGraphicsItem *evil):QGraphicsPixmapItem(evil)
{
    setPixmap(QPixmap(":/images/carro2.png").scaled(30,60));
}
enemigos::enemigos(int coches)
{
    if(coches > 0 && coches <= 5){
        setPixmap(QPixmap(":/images/carro2.png").scaled(30,60));
    }
     else{
          setPixmap(QPixmap(":/images/camion.png").scaled(30,90));
        }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void enemigos::posi()
{
    if(random>90){
       setPos(random,0);
    }
    else{
        random += 90;
        setPos(random,0);
    }
}

void enemigos::move()
{
   setPos(x(),y()+7);
   if(pos().y()+60 > 500){
       scene()->removeItem(this);
       delete this;
   }
}
