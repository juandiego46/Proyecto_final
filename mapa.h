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
    int vy = 7;

public slots:


public:
    mapa(QGraphicsItem *map=0);
    void posmapa();
    void posmapa(int x,int y);
    int getXx() const;
    void setXx(int newXx);
    int getYy() const;
    void setYy(int newYy);
    int getVy() const;
    void setVy(int newVy);
};

#endif // MAPA_H
