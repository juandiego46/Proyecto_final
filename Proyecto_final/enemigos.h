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
#include <QVector>

class enemigos:public QObject,
        public QGraphicsPixmapItem
{
     Q_OBJECT
private:
<<<<<<< HEAD
    int random = rand() % 420;
=======
    int random = rand() % 410;
>>>>>>> 2178e1f (Movimiento al aceite)
    QTimer *timer;

public:
    enemigos(QGraphicsItem *evil=0);
    enemigos(int coch);
    void posi();

public slots:
    void move();

};

#endif // ENEMIGOS_H
