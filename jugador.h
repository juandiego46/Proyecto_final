#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>

class jugador: public QObject,
        public QGraphicsPixmapItem
{
   Q_OBJECT

private:
    int x = 0;
    int y = 0;
    int vx = 10;
    int vy = 7;
    int masa = 15;
    QTimer *timer;
    int random = rand() % 2;
    int giro1 = 0;
    int angulo = 90;

public slots:
    void rotacion();

public:
    jugador(QGraphicsItem *moto = 0);
    jugador(int level);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getVx() const;
    void setVx(int newVx);
    int getVy() const;
    void setVy(int newVy);
    void posicion();
    void posicion(int _x, int _y); 
    int getMasa() const;
    void setMasa(int newMasa);
    void giro();
    int getGiro1() const;
    void setGiro1(int newGiro1);

};

#endif // JUGADOR_H
