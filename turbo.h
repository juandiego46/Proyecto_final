#ifndef TURBO_H
#define TURBO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QTimer>
#include <QVector>
#include <qmainwindow.h>

class turbo: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int y = -100;
    int vel = 5;
    int random =  rand() % 410;
    QTimer *timer;
    QVector<QGraphicsItem *> vect_turbo;

public slots:
    void movimiento();

public:
    turbo(QGraphicsItem *nitro = 0);

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getVel() const;
    void setVel(int newVel);
    void posAleatorio();
    void sig_level();
};

#endif // TURBO_H
