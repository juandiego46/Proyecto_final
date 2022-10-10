#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class enemigos:public QObject,
        public QGraphicsPixmapItem
{
     Q_OBJECT
private:
    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 0;

public:
    enemigos();
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getVx() const;
    void setVx(int newVx);
    int getVy() const;
    void setVy(int newVy);
};

#endif // ENEMIGOS_H
