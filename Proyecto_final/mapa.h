#ifndef MAPA_H
#define MAPA_H

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
#include <QVector>



class mapa:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int xx = 0;
    int yy = -2500;
<<<<<<< HEAD
<<<<<<< HEAD
    int vx = 0;
    int vy = 0;
=======
    int vy = 5;
>>>>>>> 2178e1f (Movimiento al aceite)
=======
    int vy = 5;
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")

public:
    mapa(QGraphicsItem *map=0);
    void posmapa();
    void posmapa(int x,int y);
    int getXx() const;
    void setXx(int newXx);
    int getYy() const;
    void setYy(int newYy);
<<<<<<< HEAD
<<<<<<< HEAD
    int getVx() const;
    void setVx(int newVx);
=======
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
    int getVy() const;
    void setVy(int newVy);
};

#endif // MAPA_H
