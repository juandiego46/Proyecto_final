#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enemigos.h"
#include "jugador.h"
#include "mapa.h"
#include <QList>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void hmov();
    void crea_enemigos();


private:
    int coches = 1;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    jugador *jugador1;
    mapa *mapp;
    QTimer *timer;
    QTimer *timer2;
    enemigos *evil;

};
#endif // MAINWINDOW_H
