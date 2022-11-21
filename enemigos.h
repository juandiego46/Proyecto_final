#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QList>
#include <vector>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <math.h>
#include <QVector>

class enemigos:public QObject,
        public QGraphicsPixmapItem
{
     Q_OBJECT
private:
    int x = 0;
    int y = 0;
    int masa = 0;
    int vy = 7;
    int vx = 0;
    int random = rand() % 410;
    QTimer *timer;
    QVector<QGraphicsItem *> vect_enemigos;

public slots:
    void movimiento();

public:
    enemigos(QGraphicsItem *evil=0);
    enemigos(int coch,int level);
    void posicion();
    void posi();    
    int getY() const;
    void setY(int newY);
    int getX() const;
    void setX(int newX);
    int getMasa() const;
    void setMasa(int newMasa);
    int getVy() const;
    void setVy(int newVy);
    void sig_level();
    int choque(QGraphicsItem *ca,int vel = 0);
    int getVx() const;
    void setVx(int newVx);
};

#endif // ENEMIGOS_H
