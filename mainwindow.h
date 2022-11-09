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


public slots:

    void crea_enemigos();
    void aceiteRandom();
    void colisiones();
    void turboRandom();
    void on_pushButton_clicked();
    void level();

private:
    int coches = 1;
    int nivel = 0;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    jugador *jugador1;
    mapa *mapp;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    enemigos *evil;
    aceite *mancha;
    turbo *nitro;

};
#endif // MAINWINDOW_H
