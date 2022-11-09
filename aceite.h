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
#include <QVector>

class aceite: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int y = -100;
    int vel = 5;
    int random =  rand() % 410;
    QTimer *timer;
    QVector<QGraphicsItem *> vect_aceite;

public slots:
    void movimiento();

public:
    aceite(QGraphicsItem *mancha = 0);

    int getY() const;
    void setY(int newY);
    void posicion(int _x, int _y);
    int getVel() const;
    void setVel(int newVel);
    void posAleatorio();
    void sig_level();


};

#endif // ACEITE_H
