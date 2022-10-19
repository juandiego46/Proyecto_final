#ifndef ACEITE_H
#define ACEITE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QTimer>

class aceite:public QObject,
        public QGraphicsPixmapItem

{
    Q_OBJECT
private:

    int y = -100;
    int vel = 7;
    int random =  rand() % 410;
    QTimer *timer;

public slots:
    void movimiento();

public:
    aceite(QGraphicsItem *mancha =0);

    int getY() const;
    void setY(int newY);
    void posicion(int _x, int _y);
    int getVel() const;
    void setVel(int newVel);
    void posAleatorio();

};

#endif // ACEITE_H
