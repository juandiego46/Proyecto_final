#include "aceite.h"

<<<<<<< HEAD
<<<<<<< HEAD
int aceite::getX() const
{
    return x;
}

void aceite::setX(int newX)
{
    x = newX;
}
=======
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")

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
<<<<<<< HEAD
<<<<<<< HEAD
    y = y + vel;
    setPos(x,y);
    qDebug() << "Mancha en y: " << y;
=======
    y += vel;
    setPos(x(),y);
>>>>>>> 2178e1f (Movimiento al aceite)
=======
    y += vel;
    setPos(x(),y);
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
    if(y > 500){
        scene()->removeItem(this);
        delete this;
    }
}

aceite::aceite(QGraphicsItem *mancha) : QGraphicsPixmapItem(mancha)
{
     setPixmap(QPixmap(":/images/aceite.png").scaled(20,20));
<<<<<<< HEAD
<<<<<<< HEAD
}

void aceite::posicion(int _x, int _y)
{
    x = _x;
    y = _y;
    setPos(_x, _y);
}


=======
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this,SLOT(movimiento()));
     timer->start(100);
}

void aceite::posAleatorio()
{
    if(random>90){
       setPos(random,0);
    }
    else{
        random += 90;
        setPos(random,0);
    }
}




<<<<<<< HEAD
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")