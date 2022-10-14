#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>

class jugador: public QObject,
        public QGraphicsPixmapItem
{
   Q_OBJECT

private:
    int x = 0;
    int y = 0;
    int vx = 8;
    int vy = 7;



public:
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getVx() const;
    void setVx(int newVx);
    int getVy() const;
    void setVy(int newVy);

    jugador(QGraphicsItem *moto = 0);
    void posicion();
    void posicion(int _x, int _y);


};

#endif // JUGADOR_H
