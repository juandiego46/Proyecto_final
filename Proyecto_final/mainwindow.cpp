#include "mainwindow.h"
#include "enemigos.h"
#include "ui_mainwindow.h"
#include "jugador.h"
#include <QListIterator>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(0,0,510,510);
    scene->addRect(0,0,500,500);
    mapp = new mapa();
    mapp->posmapa(0,-2500);
    scene->addItem(mapp);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(hmov()));
    timer->start(100);
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this,SLOT(crea_enemigos()));
    timer2->start(2000);
    jugador1 = new jugador;
    jugador1->posicion(100,250);
    scene->addItem(jugador1);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_F4) {
        close();
    }
    else if(event->key()==Qt::Key_D){
        if(jugador1->getX() < (scene->height())-100){
            qDebug() << "Preciono la tecla D";
            jugador1->setX(jugador1->getX() + jugador1->getVx());
            qDebug() << "PosX= " << jugador1->getX();
            jugador1->setPos(jugador1->getX(), jugador1->getY());
        }
    }
    else if(event->key()==Qt::Key_A){
        if(jugador1->getX() > 70){
            qDebug() << "Preciono la tecla A";
            jugador1->setX(jugador1->getX() - jugador1->getVx());
            qDebug() << "PosX= " << jugador1->getX();
            jugador1->setPos(jugador1->getX(), jugador1->getY());
        }
    }
}

void MainWindow::crea_enemigos()
{
    evil = new enemigos(coches);
    coches++;
    if(coches>6){
        coches = 1;
    }
    evil->posi();
    scene->addItem(evil);
}




void MainWindow::hmov(){
    if(mapp->getYy() < 0){
        mapp->setYy(mapp->getYy()+5);
        mapp->posmapa();
    }
}
