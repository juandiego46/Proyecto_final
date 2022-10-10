#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class jugador: public QObject,
        public QGraphicsPixmapItem
{
   Q_OBJECT

private:
    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;

public:
    jugador();

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getVx() const;
    void setVx(int newVx);
    int getVy() const;
    void setVy(int newVy);
};

#endif // JUGADOR_H
