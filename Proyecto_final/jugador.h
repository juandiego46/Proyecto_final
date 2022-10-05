#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class jugador: public QObject,
        public QGraphicsPixmapItem
{
   Q_OBJECT

private:
    int x = 0;
    int y = 0;

public:
    jugador();
};

#endif // JUGADOR_H
