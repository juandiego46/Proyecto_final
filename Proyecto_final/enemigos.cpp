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
<<<<<<< HEAD
<<<<<<< HEAD
    setPos(random,0);
=======
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
    if(random>90){
       setPos(random,0);
    }
    else{
        random += 90;
        setPos(random,0);
    }
<<<<<<< HEAD
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
}

void enemigos::move()
{
<<<<<<< HEAD
<<<<<<< HEAD
   setPos(x(),y()+5);
=======
   setPos(x(),y()+7);
>>>>>>> 2178e1f (Movimiento al aceite)
=======
   setPos(x(),y()+7);
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
   if(pos().y()+60 > 500){
       scene()->removeItem(this);
       delete this;
   }
}
