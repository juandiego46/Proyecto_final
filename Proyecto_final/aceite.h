#ifndef ACEITE_H
#define ACEITE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <QTimer>
>>>>>>> 2178e1f (Movimiento al aceite)
=======
#include <QTimer>
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")

class aceite:public QObject,
        public QGraphicsPixmapItem

{
    Q_OBJECT
private:
<<<<<<< HEAD
<<<<<<< HEAD
    int x = 100;
    int y = 0;
    int vel = 5;
=======
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
    int y = -100;
    int vel = 5;
    int random =  rand() % 410;
    QTimer *timer;
<<<<<<< HEAD
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")

public slots:
    void movimiento();

public:
    aceite(QGraphicsItem *mancha = 0);

<<<<<<< HEAD
<<<<<<< HEAD
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);

    void posicion(int _x, int _y);
    int getVel() const;
    void setVel(int newVel);
=======
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
    void posAleatorio();
    int getY() const;
    void setY(int newY);
    void posicion();
    int getVel() const;
    void setVel(int newVel);


<<<<<<< HEAD
>>>>>>> 2178e1f (Movimiento al aceite)
=======
>>>>>>> 92fbec7 (Revert "Revert "Movimiento al aceite"")
};

#endif // ACEITE_H
