#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enemigos.h"
#include "jugador.h"
#include "mapa.h"
#include "aceite.h"
#include "turbo.h"
#include <QList>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QMainWindow>
#include <QRect>
#include <QApplication>
#include <QTime>

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
    void destruir_tiempo();
    void sig_level();
    void colision_enemigos();


public slots:

    void crea_enemigos();
    void aceiteRandom();
    void colisiones();
    void turboRandom();
    void on_pushButton_clicked();
    void level();
    void normal();
    void efectoNitro();
    void hmov();

private:

    int coches = 1;
    int nivel = 0;
    float coss = 0.86;
    float senn = 0.5;
    float cot = 0.58;
    int v1 = 0;
    int v2 = 0;
    int mov = 0;
    int vida = 2;
    QKeyEvent *event;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    jugador *jugador1;
    mapa *mapp;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTime *reloj;
    enemigos *evil;
    aceite *mancha;
    turbo *nitro;
    QVector<enemigos *> vect_enemigos;
    QVector<aceite *> vect_aceite;
    QVector<turbo *> vect_turbo;
};
#endif // MAINWINDOW_H
