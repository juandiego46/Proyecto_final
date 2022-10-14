#ifndef ACEITE_H
#define ACEITE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>

class aceite:public QObject,
        public QGraphicsPixmapItem

{
    Q_OBJECT
private:
    int x = 100;
    int y = 0;
    int vel = 5;

public slots:
    void movimiento();

public:
    aceite(QGraphicsItem *mancha = 0);

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);

    void posicion(int _x, int _y);
    int getVel() const;
    void setVel(int newVel);
};

#endif // ACEITE_H
